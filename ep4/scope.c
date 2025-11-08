#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scope.h"
#include "errors.h"

SymbolTable *scope_stack = NULL;
char *current_function_name = NULL;

// Cria um novo escopo (push na pilha)
void push_scope() {
    SymbolTable *new_scope = (SymbolTable *) malloc(sizeof(SymbolTable));
    if (!new_scope) {
        fprintf(stderr, "Erro: falha ao alocar novo escopo.\n");
        exit(EXIT_FAILURE);
    }
    new_scope->symbols = NULL;
    new_scope->next = scope_stack;
    scope_stack = new_scope;
	fprintf(stderr, "Alocando novo escopo.\n");
}

// Remove o escopo atual (pop da pilha)
void pop_scope() {
    if (!scope_stack) return;

    SymbolTable *temp = scope_stack;
    scope_stack = scope_stack->next;

    // Libera símbolos do escopo removido
    Symbol *sym = temp->symbols;
    while (sym) {
        Symbol *next = sym->next;

        free(sym->name);
        // argumentos
        Argument *arg = sym->args;
        while (arg) {
            Argument *next_arg = arg->next;
            free(arg->name);
            free(arg);
            arg = next_arg;
        }
        free(sym);
        sym = next;
    }

    free(temp);
	fprintf(stderr, "Removendo escopo.\n");
}

// =====================================
// 🔹 Manipulação da tabela de símbolos
// =====================================

// Cria um novo símbolo e insere no escopo atual
void insert_symbol(char *name, Nature nature, Type type, Argument *args) {
    if (!scope_stack)
        push_scope(); // garante que há escopo ativo

    // Verifica redefinição no mesmo escopo
    Symbol *check = scope_stack->symbols;
    while (check) {
        if (strcmp(check->name, name) == 0) {
            fprintf(stderr, "Erro: símbolo '%s' já foi declarado neste escopo.\n", name);
            exit(ERR_DECLARED);
        }
        check = check->next;
    }

    Symbol *sym = (Symbol *) malloc(sizeof(Symbol));
    if (!sym) {
        fprintf(stderr, "Erro: falha ao alocar símbolo.\n");
        exit(EXIT_FAILURE);
    }


    sym->name = strdup(name);
    sym->nature = nature;
    sym->type = type;
    sym->args = args;
    sym->next = scope_stack->symbols;
    scope_stack->symbols = sym;
	fprintf(stderr, "Inserindo simbolo: %s - Tipo: %s - Nature: %s.\n", name, type_to_string(type), nature_to_string(nature));
}

// Busca símbolo do topo da pilha até o escopo global
Symbol *lookup_symbol(char *name) {
    SymbolTable *table = scope_stack;
    while (table) {
        Symbol *sym = table->symbols;
        while (sym) {
            if (strcmp(sym->name, name) == 0)
                return sym;
            sym = sym->next;
        }
        table = table->next;
    }
    return NULL; // não encontrado
}

// =================================
// 🔹 Criação e manipulação de args
// =================================

// Cria um argumento novo
Argument *create_argument(char *name, Type type) {
    Argument *arg = (Argument *) malloc(sizeof(Argument));
    if (!arg) {
        fprintf(stderr, "Erro: falha ao alocar argumento.\n");
        exit(EXIT_FAILURE);
    }
    arg->name = strdup(name);
    arg->type = type;
    arg->next = NULL;
    return arg;
}

// Adiciona um argumento ao final da lista
Argument *append_argument(Argument *list, Argument *new_arg) {
    if (!list) return new_arg;
    Argument *temp = list;
    while (temp->next)
        temp = temp->next;
    temp->next = new_arg;
    return list;
}


// =================================
// 🔹 Função de debug / impressão
// ================================

// Converte enum Nature em string
const char *nature_to_string(Nature n) {
    switch (n) {
        case NATURE_LITERAL: return "literal";
        case NATURE_ID: return "variável";
        case NATURE_FUNCAO: return "função";
        default: return "desconhecido";
    }
}

// Imprime a pilha de escopos
void print_scope_stack() {
    printf("\n===== PILHA DE ESCOPO =====\n");
    SymbolTable *table = scope_stack;
    int depth = 0;

    if (!table) {
        printf("(vazia)\n");
    }

    while (table) {
        printf("Escopo #%d:\n", depth);
        Symbol *sym = table->symbols;
        if (!sym)
            printf("  (sem símbolos)\n");

        while (sym) {
            printf("  %s | natureza: %s | tipo: %s\n",
                sym->name,
                nature_to_string(sym->nature),
                type_to_string(sym->type)
            );

            // Se for função, imprime argumentos
            if (sym->nature == NATURE_FUNCAO && sym->args) {
                printf("    Argumentos:\n");
                Argument *arg = sym->args;
                while (arg) {
                    printf("      - %s : %s\n",
                        arg->name,
                        type_to_string(arg->type)
                    );
                    arg = arg->next;
                }
            }
            sym = sym->next;
        }
        table = table->next;
        depth++;
    }
    printf("===========================\n\n");
}
