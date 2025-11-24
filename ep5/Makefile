LEX=flex
YACC=bison
CC=gcc
CFLAGS=-Wall -g -fsanitize=address

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: etapa5

parser.c parser.tab.h: parser.y
	$(YACC) -d -o parser.c parser.y --report-file=parser.output --header=parser.tab.h

scanner.c: scanner.l
	$(LEX) -o scanner.c scanner.l

etapa5: parser.c scanner.c main.c asd.c scope.c iloc.c
	$(CC) $(CFLAGS) -I. -o $@ parser.c scanner.c main.c asd.c scope.c iloc.c -lfl

clean:
	rm -f parser.c parser.tab.h parser.output scanner.c etapa5 *.o
