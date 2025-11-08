# Compiladores e flags
CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -Wextra

# Arquivos
TARGET = etapa1
SRC = main.c lex.yy.c
HDR = tokens.h

# Regras

all: $(TARGET)

# Geração do lex.yy.c a partir do scanner.l
lex.yy.c: scanner.l $(HDR)
	$(FLEX) scanner.l

# (Opcional) Se você tivesse gramática Bison, entraria aqui
# bison -d parser.y
# Isso geraria parser.tab.c e parser.tab.h

# Compilação do executável
$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) -o $@ $(SRC) -lfl

# Limpeza dos arquivos gerados
clean:
	rm -f lex.yy.c $(TARGET)

