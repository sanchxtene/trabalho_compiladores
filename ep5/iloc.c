#include "iloc.h"

int temp_counter = 0;
int label_counter = 0;

ILOCList *iloc_new_list() {
    ILOCList *list = malloc(sizeof(ILOCList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

ILOCList *concat(ILOCList *a, ILOCList *b) {
    if (!a || !a->head) return b;
    if (!b || !b->head) return a;

    a->tail->next = b->head;
    a->tail = b->tail;

    return a;
}

ILOCInstr *new_instr(char *op, char *a1, char *a2, char *a3) {
    ILOCInstr *i = malloc(sizeof(ILOCInstr));
    i->op = strdup(op);

    i->arg1 = a1 ? strdup(a1) : NULL;
    i->arg2 = a2 ? strdup(a2) : NULL;
    i->arg3 = a3 ? strdup(a3) : NULL;

    i->label = NULL; //Inicia com NULL, se precisar é adicionado depois

    i->next = NULL;
    return i;
}

ILOCInstr *new_label_instr(char *label) {
    ILOCInstr *i = malloc(sizeof(ILOCInstr));
    i->label = strdup(label);
    i->op = strdup("nop");
    i->arg1 = NULL;
    i->arg2 = NULL;
    i->arg3 = NULL;
    i->next = NULL;
    return i;
}

void append_instr(ILOCList *list, ILOCInstr *instr) {
    instr->next = NULL;   // segurança extra!

    if (list->tail == NULL) {
        list->head = instr;
        list->tail = instr;
    } else {
        list->tail->next = instr;
        list->tail = instr;
    }
}

char *new_temp() {
    char buffer[32];
    sprintf(buffer, "r%d", temp_counter++);
    return strdup(buffer);
}

char *new_label() {
    char buffer[32];
    sprintf(buffer, "L%d", label_counter++);
    return strdup(buffer);
}

void print_iloc(ILOCList *list) {
    for (ILOCInstr *i = list->head; i != NULL; i = i->next) {
        if (i->label != NULL) printf("%s: ", i->label);

        printf("%s", i->op);

        if (strcmp(i->op, "loadI") == 0){
            printf(" %s => %s", i->arg1, i->arg3);
        } else if (strcmp(i->op, "loadAI") == 0) {
            printf(" %s, %s => %s", i->arg1, i->arg2, i->arg3);
        } else if (strcmp(i->op, "storeAI") == 0) {
            printf(" %s => %s, %s", i->arg1, i->arg2, i->arg3);
        } else if (strcmp(i->op, "cbr") == 0) {
            printf(" %s => %s, %s", i->arg1, i->arg2, i->arg3);
        } else if (strcmp(i->op, "jumpI") == 0) {
            printf(" => %s", i->arg3);
        } else if (strcmp(i->op, "nop") == 0) {

        } else {
            printf(" %s, %s => %s", i->arg1, i->arg2, i->arg3);
        }
        printf("\n");
    }
}
