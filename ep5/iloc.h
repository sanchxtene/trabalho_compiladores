#ifndef _ILOC_H_
#define _ILOC_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct ILOCInstr {
    char *op;
    char *arg1;
    char *arg2;
    char *arg3;

    char *label;

    struct ILOCInstr *next;
} ILOCInstr;

typedef struct ILOCList {
    ILOCInstr *head;
    ILOCInstr *tail;
} ILOCList;

typedef struct ExprResult {
    ILOCList *code;
    char *temp;
} ExprResult;


ILOCList *iloc_new_list();
ILOCList *concat(ILOCList *a, ILOCList *b);

ILOCInstr *new_instr(char *op, char *a1, char *a2, char *a3);
void append_instr(ILOCList *list, ILOCInstr *instr);
ILOCInstr *new_label_instr(char *label);

void print_iloc(ILOCList *list);

extern int temp_counter;
extern int label_counter;
char *new_temp();
char *new_label();

#endif
