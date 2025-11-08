#ifndef _SCOPE_H
#define _SCOPE_H
#include "types.h"

typedef enum {
    NATURE_LITERAL,
    NATURE_ID,
    NATURE_FUNCAO
} Nature;


typedef struct Argument {
    char *name;
    Type type;
    struct Argument *next;   	// próximo argumento na lista de argumentos
} Argument;

typedef struct Symbol {
    char *name;			// valor do token pelo yyval
    Nature nature;  		// literal, identificador ou função
    Type type;  		// inteiro ou decimal
    struct Argument *args;	// caso seja função pode ter (opcional) uma lista encadeade de argumentos
    struct Symbol *next;	// próximo símbolo na pilha de escopo
} Symbol;

typedef struct SymbolTable {
    struct Symbol *symbols;	// lista encadeada apontando para o primeiro símbolo do escopo
    struct SymbolTable *next;  	// próxima tabela na pilha (escopo anterior)
} SymbolTable;



// pilha global de escopos
extern SymbolTable *scope_stack;

// função atual
extern char *current_function_name;

// funções de escopo
void push_scope();
void pop_scope();
void print_scope_stack();

// símbolos
void insert_symbol(char *name, Nature nature, Type type, Argument *args);
Symbol *lookup_symbol(char *name);

// argumentos
Argument *create_argument(char *name, Type type);
Argument *append_argument(Argument *list, Argument *new_arg);

const char *nature_to_string(Nature n);

#endif
