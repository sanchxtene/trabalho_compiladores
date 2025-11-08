%code requires {
	#include <asd.h>
	typedef struct asd_tree asd_tree_t;
	extern asd_tree_t *arvore;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
%}

%union {
	char* texto;
	valor_lexico_t* valor_lexico;
	asd_tree_t* no;
}

%define parse.error verbose

%token <texto> TK_TIPO
%token <texto> TK_VAR
%token <texto> TK_SENAO
%token <texto> TK_DECIMAL
%token <texto> TK_SE
%token <texto> TK_INTEIRO
%token <texto> TK_ATRIB
%token <texto> TK_RETORNA
%token <texto> TK_SETA
%token <texto> TK_ENQUANTO
%token <texto> TK_COM
%token <texto> TK_OC_LE
%token <texto> TK_OC_GE
%token <texto> TK_OC_EQ
%token <texto> TK_OC_NE
%token <valor_lexico> TK_ID
%token <valor_lexico> TK_LI_INTEIRO
%token <valor_lexico> TK_LI_DECIMAL
%token <texto> TK_ER

%type <no> programa lista elemento tipo literal
%type <no> declaracao_variavel_top declaracao_funcao
%type <no> cabecalho lista_opcional_parametros
%type <no> corpo cs_bloco_de_comandos sequencia comando_simples 
%type <no> cs_declaracao_variavel cs_comando_atribuicao cs_retorno
%type <no> cs_controle_fluxo condicional senao_opcional
%type <no> cs_chamada_funcao argumentos lista_expressoes repeticao
%type <no> expressao expr_or expr_and expr_eq expr_rel expr_add expr_mul expr_unary expr_primary

%%

/* PROGRAMA VAZIO OU APENAS COM DECLARAÇÕES DE VARIÁVEL SEM INICIALIZAÇÃO DEVEM TER ALGUM NÓ? */
programa: lista ';' { arvore = $1; } ;
programa: %empty { arvore = NULL; } ;

/* a lista inteira pode ser NULL, checa se o elemento é NULL antes de adionar */
lista: elemento { $$ = $1; } ;
lista: elemento ',' lista { if ($1 == NULL) {
				$$ = $3;
			    } else {
				$$ = $1;
				if ($3 != NULL) {
					asd_add_child($$, $3);
				}
			    }
			  }; 


/* retorno de declaracao_variavel_top pode ser NULL */
elemento: declaracao_variavel_top { $$ = $1; } ;
elemento: declaracao_funcao { $$ = $1; } ;

tipo: TK_DECIMAL { $$ = asd_new("decimal"); }
    | TK_INTEIRO { $$ = asd_new("inteiro"); } ;

literal: TK_LI_DECIMAL { $$ = asd_new($1->valor); free($1->valor); free($1); } 
       | TK_LI_INTEIRO { $$ = asd_new($1->valor); free($1->valor); free($1); } ;

/* Variavel Global - Não cria nó, retorna NULL */
declaracao_variavel_top: TK_VAR TK_ID TK_ATRIB tipo 
			{ $$ = NULL; free($2->valor); free($2); asd_free($4); } ;


/* Declaração de Função - Nó = Cabecalho; e filho = Corpo, não cria nó caso seja NULL*/
declaracao_funcao: cabecalho corpo { $$ = $1; if($2 != NULL) 
						{asd_add_child($$, $2);} } ;

// CABECALHO
/* Cabecalho - Nó = ID->label e free() nas strings contendo o label do TK_ID e do tipo */
cabecalho: TK_ID TK_SETA tipo lista_opcional_parametros TK_ATRIB
	  { $$ = asd_new($1->valor);
		 free($1->valor);
		 free($1);
		 asd_free($3); };

lista_opcional_parametros: %empty { $$ = NULL; } 
			| com_opcional lista_parametros { $$ = NULL; } ;

lista_parametros: parametro  
		| parametro ',' lista_parametros;

parametro: TK_ID TK_ATRIB tipo { free($1->valor); free($1); asd_free($3); } ;

com_opcional: TK_COM | %empty;
	

// CORPO
/* Corpo - Nó = Bloco_de_Comando; PODE SER NULL */
corpo: cs_bloco_de_comandos { $$ = $1; } ;

/* Bloco de Comandos - Nó = Sequencia; PODE SER NULL */
cs_bloco_de_comandos: '[' sequencia ']' { $$ = $2; };

/* Sequencia - Nó = Primeiro comando da sequencia ou não cria nó e retorna NULL */
sequencia: %empty { $$ = NULL; }
	 | comando_simples sequencia { 
			if ($2 == NULL){
				$$ = $1;
			} else {
				if ($1 == NULL) {
					$$ = $2;
				} else {
					asd_add_child($1, $2);
					$$ = $1;
				}
			}
		};

	// COMANDOS SIMPLES
comando_simples:  cs_declaracao_variavel { $$ = $1; } 
		| cs_retorno { $$ = $1; }
		| cs_chamada_funcao { $$ = $1; }
		| cs_bloco_de_comandos { $$ = $1; }
		| cs_controle_fluxo { $$ = $1; }
		| cs_comando_atribuicao { $$ = $1; };

	// Declaracao Variavel (COMANDO SIMPLES)
/* Caso 1: Se não é inicializado, propaga o NULL até o comando de "sequencia"            */
/* Caso 2: Se é inicializado, o nó raíz será o nó vindo do $5 = inicializador = "com" o 
	   lexema do literal já incluso como filho e na declaração se adiciona o ID      */
cs_declaracao_variavel: TK_VAR TK_ID TK_ATRIB tipo { $$ = NULL; free($2->valor); free($2); asd_free($4); }
		      | TK_VAR TK_ID TK_ATRIB tipo TK_COM literal
			{ $$ = asd_new("com");
			  asd_tree_t *id_node = asd_new($2->valor);
			  asd_add_child($$, id_node); 
			  asd_add_child($$, $6);
			  free($2->valor);
			  free($2);
			  asd_free($4);
			};


	// Comando de Atribuicao
cs_comando_atribuicao: TK_ID TK_ATRIB expressao 
                     { $$ = asd_new(":="); 
			    asd_tree_t *id_node = asd_new($1->valor);
			    free($1->valor);
			    free($1);
			    asd_add_child($$, id_node);
			    asd_add_child($$, $3); } ;

	// Chamada de Funcao
cs_chamada_funcao: TK_ID '(' argumentos ')' { 
		        /* ... */
			size_t len = strlen("call ") + strlen($1->valor) + 1;
			char *nome = malloc(len);
			sprintf(nome, "call %s", $1->valor);
			$$ = asd_new(nome);
			if ($3 != NULL) {
				asd_add_child($$, $3);
			}
			free($1->valor);
			free($1);
			free(nome);
		} ;

argumentos: lista_expressoes { $$ = $1; } | %empty { $$ = NULL; } ;
lista_expressoes: expressao { $$ = $1; }
		| expressao ',' lista_expressoes { $$ = $1; asd_add_child($$, $3); } ;

	// Comando de Retorno
cs_retorno: TK_RETORNA expressao TK_ATRIB tipo
		{ $$ = asd_new("retorna"); asd_add_child($$, $2); asd_free($4); } ;

	// Construcoes de Fluxo de Controle
cs_controle_fluxo: condicional { $$ = $1; }
		 | repeticao { $$ = $1; } ;

	// Se
condicional: TK_SE '(' expressao ')' cs_bloco_de_comandos senao_opcional
		{ $$ = asd_new("se");
		  asd_add_child($$, $3);
		  if ($5 != NULL) {
			asd_add_child($$, $5);
		  }
		  if ($6 != NULL) {
			asd_add_child($$, $6);
		  } 
		};    

	// Senao (opcional)
senao_opcional: %empty { $$ = NULL; }
	      | TK_SENAO cs_bloco_de_comandos { $$ = $2; } ;
	
	// Enquanto
repeticao: TK_ENQUANTO '(' expressao ')' cs_bloco_de_comandos 
		{ $$ = asd_new("enquanto");
		  asd_add_child($$, $3);
		  if ($5 != NULL) {
			asd_add_child($$, $5);
		  }
		} ;


	// EXPRESSOES
expressao: expr_or { $$ = $1; } ;
expr_or: expr_or '|' expr_and { $$ = asd_new("|"); asd_add_child($$, $1); asd_add_child($$, $3); } | expr_and { $$ = $1; } ;
expr_and: expr_and '&' expr_eq { $$ = asd_new("&"); asd_add_child($$, $1); asd_add_child($$, $3); } | expr_eq { $$ = $1; } ;
expr_eq: expr_eq TK_OC_EQ expr_rel { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); } | expr_eq TK_OC_NE expr_rel { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); } | expr_rel { $$ = $1; } ;

expr_rel: expr_rel '<' expr_add { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_rel '>' expr_add { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_rel TK_OC_LE expr_add { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_rel TK_OC_GE expr_add { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_add { $$ = $1; } ;

expr_add: expr_add '+' expr_mul  { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_add '-' expr_mul { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_mul { $$ = $1; } ;

expr_mul: expr_mul '*' expr_unary { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_mul '/' expr_unary { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_mul '%' expr_unary { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); } 
| expr_unary { $$ = $1; } ;

expr_unary: '+' expr_unary { $$ = asd_new("+"); asd_add_child($$, $2); }
| '-' expr_unary { $$ = asd_new("-"); asd_add_child($$, $2); }
| '!' expr_unary { $$ = asd_new("!"); asd_add_child($$, $2); }
| expr_primary { $$ = $1; };

expr_primary: TK_ID { $$ = asd_new($1->valor); free($1->valor); free($1); }
            | literal { $$ = $1; } 
	    | '(' expressao ')' { $$ = $2; } 
	    | cs_chamada_funcao { $$ = $1; } ;


%%

void yyerror (char const *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}

