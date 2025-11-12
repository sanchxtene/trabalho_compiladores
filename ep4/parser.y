%code requires {
	#include "asd.h"
	#include "scope.h"
	#include "errors.h"
	typedef struct asd_tree asd_tree_t;
	extern asd_tree_t *arvore;
	extern char *current_function_name;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;

bool is_operator_label(const char *label) {
    if (label == NULL) return false;

    return (
        strcmp(label, "+")  == 0 ||
        strcmp(label, "-")  == 0 ||
        strcmp(label, "*")  == 0 ||
        strcmp(label, "/")  == 0 ||
        strcmp(label, "%")  == 0 ||
        strcmp(label, "|")  == 0 ||
        strcmp(label, "&")  == 0 ||
        strcmp(label, "<")  == 0 ||
        strcmp(label, ">")  == 0 ||
        strcmp(label, "<=") == 0 ||
        strcmp(label, ">=")  == 0 ||
        strcmp(label, "==")  == 0 ||
        strcmp(label, "!=")  == 0 ||
	strcmp(label, "!") == 0
    );
}
%}

%union {
	char* texto;
	valor_lexico_t* valor_lexico;
	asd_tree_t* no;
	Argument *argument;
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
%type <argument> lista_opcional_parametros
%type <argument> lista_parametros
%type <argument> parametro

%type <no> programa lista elemento tipo literal
%type <no> declaracao_variavel_top declaracao_funcao
%type <no> cabecalho corpo cs_bloco_de_comandos sequencia comando_simples 
%type <no> cs_declaracao_variavel cs_comando_atribuicao cs_retorno
%type <no> cs_controle_fluxo condicional senao_opcional
%type <no> cs_chamada_funcao argumentos lista_expressoes repeticao
%type <no> expressao expr_or expr_and expr_eq expr_rel expr_add expr_mul expr_unary expr_primary

%%

/* PROGRAMA VAZIO OU APENAS COM DECLARAÇÕES DE VARIÁVEL SEM INICIALIZAÇÃO DEVEM TER ALGUM NÓ? */
programa: cria_escopo lista ';' remove_escopo { arvore = $2; } 
	| %empty { arvore = NULL; } ;

cria_escopo: %empty { push_scope(); };
remove_escopo: %empty { pop_scope(); }; 
remove_escopo_funcao: %empty { free(current_function_name);
				current_function_name = NULL; 
				print_scope_stack();
				pop_scope();
			     };


/* a lista inteira pode ser NULL, checa se o elemento é NULL antes de adionar */
lista: elemento { $$ = $1; } 
     | elemento ',' lista { if ($1 == NULL) {
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
	| declaracao_funcao { $$ = $1; } ;

tipo: TK_DECIMAL { $$ = asd_new("tipo", TYPE_DECIMAL); }
    | TK_INTEIRO { $$ = asd_new("tipo", TYPE_INTEIRO); } ;

literal: TK_LI_DECIMAL { $$ = asd_new($1->valor, TYPE_DECIMAL); free($1->valor); free($1);} 
       | TK_LI_INTEIRO { $$ = asd_new($1->valor, TYPE_INTEIRO); free($1->valor); free($1);} ;

/* Variavel Global - Não cria nó, retorna NULL */
declaracao_variavel_top: TK_VAR TK_ID TK_ATRIB tipo 
			{ $$ = NULL;
			       insert_symbol($2->valor, NATURE_ID, $4->type, NULL);
			       free($2->valor);
			       free($2);
			       asd_free($4);
			} ;


/* Declaração de Função - Nó = Cabecalho; e filho = Corpo, não cria nó caso seja NULL*/
declaracao_funcao: cabecalho corpo remove_escopo_funcao 
		  { $$ = $1;
			 if($2 != NULL) {
				asd_add_child($$, $2);
			 }

			// Printa os parametros declarados no escopo da funcao
			Symbol *sym = lookup_symbol($1->label);
			Argument *arg = sym->args;
			if (arg == NULL) {
				fprintf(stderr, "Função '%s' declarada sem parâmetros", $1->label);
			} else {
				fprintf(stderr, "Função '%s' declarada com os parâmetros: ", $1->label);
				while (arg != NULL) {
					fprintf(stderr, "%s (%d), ", arg->name, arg->type);  // debug
					arg = arg->next;
				}
			}

			fprintf(stderr, "\n");
		  } ;


// CABECALHO
/* Cabecalho - Nó = ID->label e free() nas strings contendo o label do TK_ID e do tipo */
// ------- Cabecalho cria novo contexto depois de inserir o symbolo da função no escopo atual --------- 
// ------- TESTAR PRA VER SE TA FUNCIONANDO COMO ESPERADO ---------------------------------------------
cabecalho: TK_ID TK_SETA tipo lista_opcional_parametros TK_ATRIB
	  { $$ = asd_new($1->valor, $3->type);
		 insert_symbol($1->valor, NATURE_FUNCAO, $3->type, $4);
		 current_function_name = strdup($1->valor);
		 push_scope();
		
		 // Adiciona a lista de parametros ao escopo interno da funcao	 
		 Argument *arg = $4;
		 while (arg) {
			insert_symbol(arg->name, NATURE_ID, arg->type, NULL);
			arg = arg->next;
		 }
		 free($1->valor);
		 free($1);
		 asd_free($3);
	  };

lista_opcional_parametros: TK_COM lista_parametros { $$ = $2; } 
			 | lista_parametros { $$ = $1; } 
			 | %empty { $$ = NULL; } ;

lista_parametros: parametro  { $$ = $1; }
		| lista_parametros ',' parametro { $$ = append_argument($1, $3); };

parametro: TK_ID TK_ATRIB tipo { $$ = create_argument($1->valor, $3->type);
				 free($1->valor);
				 free($1);
				 asd_free($3);
			       } ;
	

// CORPO
/* Corpo - Nó = Bloco_de_Comando; PODE SER NULL */
corpo: cs_bloco_de_comandos { $$ = $1; } ;

/* Bloco de Comandos - Nó = Sequencia; PODE SER NULL */
cs_bloco_de_comandos: '[' sequencia ']' { $$ = $2; };

/* Sequencia - Nó = Primeiro comando da sequencia ou não cria nó e retorna NULL */
sequencia: %empty { $$ = NULL; }
	 | comando_simples sequencia
		{ if ($2 == NULL){
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
cs_declaracao_variavel: TK_VAR TK_ID TK_ATRIB tipo
			 { $$ = NULL;
				insert_symbol($2->valor, NATURE_ID, $4->type, NULL);
				free($2->valor);
				free($2);
				asd_free($4); 
			 }
		      | TK_VAR TK_ID TK_ATRIB tipo TK_COM literal
			{ $$ = asd_new("com", $4->type);
			       insert_symbol($2->valor, NATURE_ID, $4->type, NULL);
			        if ($4->type == TYPE_INTEIRO && $6->type == TYPE_DECIMAL){
					fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'inteiro' e recebeu um literal do tipo 'decimal' (linha %d)\n", $2->valor, $2->linha);
					exit(ERR_WRONG_TYPE);	
				}
				if ($4->type == TYPE_DECIMAL && $6->type == TYPE_INTEIRO){
					fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'decimal' e recebeu um literal do tipo 'inteiro' (linha %d)\n", $2->valor, $2->linha);
					exit(ERR_WRONG_TYPE);	
				}
			       asd_tree_t *id_node = asd_new($2->valor, $4->type);
			       asd_add_child($$, id_node); 
			       asd_add_child($$, $6);
			       free($2->valor);
			       free($2);
			       asd_free($4); 
			};


	// Comando de Atribuicao
cs_comando_atribuicao: TK_ID TK_ATRIB expressao 
			{Symbol *sym = lookup_symbol($1->valor);
			 if (!sym) {
				fprintf(stderr, "Erro: variável '%s' não declarada (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_UNDECLARED);
			 }
			 if (sym->nature != NATURE_ID) {
				fprintf(stderr, "Erro: o id '%s' já foi declarado como funcao (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_FUNCTION);	
			 }
			 if (sym->type == TYPE_INTEIRO && $3->type == TYPE_DECIMAL){
				fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'inteiro' e recebeu uma expressao do tipo 'decimal' (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_WRONG_TYPE);	
			 }
			 if (sym->type == TYPE_DECIMAL && $3->type == TYPE_INTEIRO){
				fprintf(stderr, "Erro: variável '%s' esperava um valor do tipo 'decimal' e recebeu uma expressao do tipo 'inteiro' (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_WRONG_TYPE);	
			 }     
			 $$ = asd_new(":=", sym->type);
			      asd_tree_t *id_node = asd_new($1->valor, sym->type);
			      free($1->valor);
			      free($1);
			      asd_add_child($$, id_node);
			      asd_add_child($$, $3);
			 } ;


	// Chamada de Funcao
cs_chamada_funcao: TK_ID '(' argumentos ')'
			{ Symbol *sym = lookup_symbol($1->valor);
			  if (!sym) {
				fprintf(stderr, "Erro: função '%s' não declarada (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_UNDECLARED);
			  }
			  if (sym->nature != NATURE_FUNCAO) {
				fprintf(stderr, "Erro: o id '%s' foi declarado como variavel (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_VARIABLE);	
			  }

			  // Verifica o numero de argumentos
			  Argument *param = sym->args;
			  size_t param_count = 0;
			  if (param == NULL) {
				fprintf(stderr, "Função '%s' declarada sem parâmetros\n", $1->valor);
			  } else {
				fprintf(stderr, "Função '%s' declarada com parâmetros:\n", $1->valor);
				while (param) {
					fprintf(stderr, "  %s (tipo %s)\n", param->name, type_to_string(param->type));
					param_count++;
					param = param->next;
				}
			  }
			  
			  // Conta argumentos passados
			  size_t arg_count = 0;
			  asd_tree_t *args = $3;
			  
			  while (args != NULL) {
				if(is_operator_label(args->label)){ 
					args = args->children[args->number_of_children - 1];
				} else {
					arg_count++;
					fprintf(stderr, "   Argumento %zu: tipo %s\n", arg_count, type_to_string(args->type));
					if (args->number_of_children > 0 && args->children != NULL && args->children[args->number_of_children - 1] != NULL) {
						args = args->children[args->number_of_children - 1];
					} else {
						args = NULL;
					}											
				}				
			  }
			  
			  fprintf(stderr, "Numero de argumentos passados para a funcao '%s': %zu\n", $1->valor, arg_count);

			  // Verifica se o num de args esta certo
			  if (arg_count < param_count) {
				fprintf(stderr, "Erro: número insuficiente de argumentos na chamada da função '%s' (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_MISSING_ARGS);
			  }
			  if (arg_count > param_count) {
				fprintf(stderr, "Erro: número excessivo de argumentos na chamada da função '%s' (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_EXCESS_ARGS);
			  }

			  // verifica os tipos dos argumentos
			  args = $3;
			  param = sym->args;
			  while (args != NULL && param != NULL) {
				asd_tree_t *expr = (args->children ? args->children[0] : args);
		                if (!expr) break;

		                if (expr->type != param->type) {
					fprintf(stderr, "Erro: tipo incompatível no argumento '%s' da função '%s' (linha %d)\n"
						"Esperado: %s, recebido: %s\n",
						param->name, sym->name, $1->linha,
						type_to_string(param->type),
						type_to_string(expr->type));
					exit(ERR_WRONG_TYPE_ARGS);
		                }

				// Avanca para o prox argumento
				if (args->children != NULL) {
					args = args->children[0]; 
				} else {
					args = NULL; 
				}
				param = param->next; // Avanca para o proóximo parametro
			  }

			  size_t len = strlen("call ") + strlen($1->valor) + 1;
			  char *nome = malloc(len);
			  sprintf(nome, "call %s", $1->valor);
			  $$ = asd_new(nome, sym->type);
			       if ($3 != NULL) {
					asd_add_child($$, $3);
			       }
			       free($1->valor);
			       free($1);
			       free(nome); } ;


argumentos: lista_expressoes  { $$ = $1; }
	  | %empty            { $$ = NULL; };

lista_expressoes: expressao { $$ = $1; }
		| expressao ',' lista_expressoes { $$ = $1; 
						   asd_add_child($1, $3); };

	// Comando de Retorno
cs_retorno: TK_RETORNA expressao TK_ATRIB tipo
		{ if ($2->type != $4->type){
			fprintf(stderr, "Erro: na função '%s' o tipo da expressao de retorno e o tipo do retorno são diferentes\n", current_function_name);
			exit(ERR_WRONG_TYPE);
		  }

		  Symbol *func_sym = lookup_symbol(current_function_name);
		  if (func_sym->type != $2->type) {
			fprintf(stderr, "Erro: tipo de retorno incorreto na função '%s' (esperado: %s, encontrado: %s)\n",
				current_function_name,
				type_to_string(func_sym->type),
				type_to_string($2->type));
				exit(ERR_WRONG_TYPE);
		  }  
		  $$ = asd_new("retorna", $4->type);
			asd_add_child($$, $2);
			asd_free($4);
		} ;

	// Construcoes de Fluxo de Controle
cs_controle_fluxo: condicional { $$ = $1; }
		 | repeticao { $$ = $1; } ;

	// Se
condicional: TK_SE '(' expressao ')' cria_escopo cs_bloco_de_comandos remove_escopo senao_opcional
		{ $$ = asd_new("se", $3->type);
			asd_add_child($$, $3);
			if ($6 != NULL) {
				asd_add_child($$, $6);
			}
			if ($8 != NULL) {
				asd_add_child($$, $8);
			} 
		};    

	// Senao (opcional)
senao_opcional: %empty { $$ = NULL; }
	      | TK_SENAO cria_escopo cs_bloco_de_comandos remove_escopo { $$ = $3; } ;
	
	// Enquanto
repeticao: TK_ENQUANTO '(' expressao ')' cria_escopo cs_bloco_de_comandos remove_escopo
		{ $$ = asd_new("enquanto", $3->type);
			asd_add_child($$, $3);
			if ($6 != NULL) {
				asd_add_child($$, $6);
			}
		} ;


	// EXPRESSOES
expressao: expr_or { $$ = $1; } ;

expr_or:
  expr_or '|' expr_and { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '|'\n");
				exit(ERR_WRONG_TYPE);
			 }
			 $$ = asd_new("|", TYPE_INTEIRO);
				asd_add_child($$, $1);
				asd_add_child($$, $3); }
| expr_and { $$ = $1; } ;

expr_and: 
  expr_and '&' expr_eq { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '&'\n");
				exit(ERR_WRONG_TYPE);
			 }
			 $$ = asd_new("&", TYPE_INTEIRO);
				asd_add_child($$, $1);
				asd_add_child($$, $3); }
| expr_eq { $$ = $1; } ;


expr_eq:
  expr_eq TK_OC_EQ expr_rel { if ($1->type != $3->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '=='\n");
					exit(ERR_WRONG_TYPE);
				}
				$$ = asd_new("==", TYPE_INTEIRO);
					asd_add_child($$, $1);
					asd_add_child($$, $3); } 
| expr_eq TK_OC_NE expr_rel { if ($1->type != $3->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '!='\n");
					exit(ERR_WRONG_TYPE);
				}
				$$ = asd_new("!=", TYPE_INTEIRO);
					asd_add_child($$, $1);
					asd_add_child($$, $3); }
| expr_rel { $$ = $1; } ;


expr_rel:
  expr_rel '<' expr_add { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  $$ = asd_new("<", TYPE_INTEIRO);
				asd_add_child($$, $1);
				asd_add_child($$, $3); } 
| expr_rel '>' expr_add { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  $$ = asd_new(">", TYPE_INTEIRO);
				asd_add_child($$, $1);
				asd_add_child($$, $3); } 
| expr_rel TK_OC_LE expr_add { if ($1->type != $3->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '<='\n");
					exit(ERR_WRONG_TYPE);
				}
				$$ = asd_new("<=", TYPE_INTEIRO);
					asd_add_child($$, $1);
					asd_add_child($$, $3); } 
| expr_rel TK_OC_GE expr_add { if ($1->type !=  $3->type) {
					fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '>='\n");
					exit(ERR_WRONG_TYPE);
				}
				$$ = asd_new(">=", TYPE_INTEIRO);
					asd_add_child($$, $1);
					asd_add_child($$, $3); } 
| expr_add { $$ = $1; } ;

expr_add: 
  expr_add '+' expr_mul { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '+'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  $$ = asd_new("+", $1->type);
				  asd_add_child($$, $1);
				  asd_add_child($$, $3); } 
| expr_add '-' expr_mul { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '-'\n");
				exit(ERR_WRONG_TYPE);
			  }
			  $$ = asd_new("-", $1->type);
				asd_add_child($$, $1);
				asd_add_child($$, $3); } 
| expr_mul { $$ = $1; } ;

expr_mul:
  expr_mul '*' expr_unary { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '*'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    $$ = asd_new("*", $1->type);
				asd_add_child($$, $1); 
				asd_add_child($$, $3); } 
| expr_mul '/' expr_unary { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '/'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    $$ = asd_new("/", $1->type);
				asd_add_child($$, $1); 
				asd_add_child($$, $3); } 
| expr_mul '%' expr_unary { if ($1->type != $3->type) {
				fprintf(stderr, "Erro: incompatibilidade de tipos, na expressao '%%'\n");
				exit(ERR_WRONG_TYPE);
			    }
			    $$ = asd_new("%", $1->type);
				asd_add_child($$, $1);
				asd_add_child($$, $3); } 
| expr_unary { $$ = $1; } ;

expr_unary: 
  '+' expr_unary { $$ = asd_new("+", $2->type); asd_add_child($$, $2); }
| '-' expr_unary { $$ = asd_new("-", $2->type); asd_add_child($$, $2); }
| '!' expr_unary { $$ = asd_new("!", $2->type); asd_add_child($$, $2); }
| expr_primary { $$ = $1; };

expr_primary: TK_ID {   Symbol *sym = lookup_symbol($1->valor);
			if (!sym) {
				fprintf(stderr, "Erro: variável '%s' não declarada (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_UNDECLARED);
			}
			if (sym->nature != NATURE_ID) {
				fprintf(stderr, "Erro: o id '%s' foi declarado como funcao (linha %d)\n", $1->valor, $1->linha);
				exit(ERR_FUNCTION);	
			}
			$$ = asd_new($1->valor, sym->type);
				free($1->valor); free($1); }
            | literal { $$ = $1; } 
	    | '(' expressao ')' { $$ = $2; } 
	    | cs_chamada_funcao { $$ = $1; } ;


%%

void yyerror (char const *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}

