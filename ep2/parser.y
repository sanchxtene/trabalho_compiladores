%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *mensagem);
extern int yylineno;
%}

%define parse.error verbose
%token TK_TIPO
%token TK_VAR
%token TK_SENAO
%token TK_DECIMAL
%token TK_SE
%token TK_INTEIRO
%token TK_ATRIB
%token TK_RETORNA
%token TK_SETA
%token TK_ENQUANTO
%token TK_COM
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_ID
%token TK_LI_INTEIRO
%token TK_LI_DECIMAL
%token TK_ER

%%

programa: lista ';';
programa: %empty;

lista: elemento;
lista: lista ',' elemento;

elemento: declaracao_variavel_top;
elemento: declaracao_funcao;

tipo: TK_DECIMAL | TK_INTEIRO;
literal: TK_LI_DECIMAL | TK_LI_INTEIRO;

	// DECLARACAO DE FUNCAO
declaracao_funcao: cabecalho corpo;
	// CABECALHO
cabecalho: TK_ID TK_SETA tipo lista_opcional_parametros TK_ATRIB;
lista_opcional_parametros: %empty | com_opcional lista_parametros;
lista_parametros: parametro | lista_parametros ',' parametro;
parametro: TK_ID TK_ATRIB tipo;
com_opcional: TK_COM | %empty;
	// CORPO
corpo: cs_bloco_de_comandos;


	// COMANDOS SIMPLES (cs = comando simples)
comando_simples: cs_bloco_de_comandos 
		| cs_declaracao_variavel
		| cs_comando_atribuicao
		| cs_chamada_funcao
		| cs_retorno
		| cs_controle_fluxo;
sequencia: %empty | sequencia comando_simples;

	// Bloco de Comandos
cs_bloco_de_comandos: '[' sequencia ']';

	// Declaracao Variavel
declaracao_variavel_top: TK_VAR TK_ID TK_ATRIB tipo;
cs_declaracao_variavel: TK_VAR TK_ID TK_ATRIB tipo inicializar_opcional;
inicializar_opcional: TK_COM literal | %empty;

	// Comando de Atribuicao
cs_comando_atribuicao: TK_ID TK_ATRIB expressao;

	// Chamada de Funcao
cs_chamada_funcao: TK_ID '(' argumentos ')';
argumentos: lista_expressoes | %empty;
lista_expressoes: expressao | lista_expressoes ',' expressao;

	// Comando de Retorno
cs_retorno: TK_RETORNA expressao TK_ATRIB tipo;

	// Construcoes de Fluxo de Controle
cs_controle_fluxo: condicional | repeticao;
	// IF
condicional: TK_SE '(' expressao ')' cs_bloco_de_comandos senao_opcional;    
senao_opcional: TK_SENAO cs_bloco_de_comandos | %empty;
	// WHILE
repeticao: TK_ENQUANTO '(' expressao ')' cs_bloco_de_comandos;

	// EXPRESSOES
expressao: expr_or;
expr_or: expr_or '|' expr_and | expr_and;
expr_and: expr_and '&' expr_eq | expr_eq;
expr_eq: expr_eq TK_OC_EQ expr_rel | expr_eq TK_OC_NE expr_rel | expr_rel;
expr_rel: expr_rel '<' expr_add | expr_rel '>' expr_add | expr_rel TK_OC_LE expr_add | expr_rel TK_OC_GE expr_add | expr_add;
expr_add: expr_add '+' expr_mul | expr_add '-' expr_mul | expr_mul;
expr_mul: expr_mul '*' expr_unary | expr_mul '/' expr_unary | expr_mul '%' expr_unary | expr_unary;
expr_unary: '+' expr_unary | '-' expr_unary | '!' expr_unary | expr_primary;
expr_primary: TK_ID | literal | cs_chamada_funcao | '(' expressao ')';

%%

void yyerror (char const *mensagem) {
    fprintf(stderr, "Erro sintático na linha %d: %s\n", yylineno, mensagem);
}
