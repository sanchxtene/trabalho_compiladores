// types.h
#ifndef TYPES_H
#define TYPES_H

typedef enum {
    TYPE_INTEIRO,
    TYPE_DECIMAL,
    TYPE_FUNCTION
} Type;

static inline const char *type_to_string(Type type) {
    switch (type) {
        case TYPE_INTEIRO: return "inteiro";
        case TYPE_DECIMAL: return "decimal";
        default: return "desconhecido";
    }
}

#endif
