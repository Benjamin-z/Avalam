# makefile

ARCH		= $(shell uname -s)-$(shell uname -m)

HOME		= .
BIN		= $(HOME)/bin/$(ARCH)
SRC		= $(HOME)/src
PROG		= $(BIN)/mon_prog

#DEFS		= -DDEBUG
CFLAGS		= -g
CC		= gcc
LD		= gcc
LDFLAGS	= 
RM 		= rm

OBJS    	= $(BIN)/main.o $(BIN)/outil.o


$(PROG) : $(OBJS)
	@echo --- Edition des liens du programme prog ---
	$(LD) $(LDLAGS) $(OBJS) -o $(PROG)

$(BIN)/main.o : $(SRC)/main.c
	@echo --- Compile main.c ---
	$(CC) $(CFLAGS) $(DEFS) -c $(SRC)/main.c -o $(BIN)/main.o

$(BIN)/outil.o : $(SRC)/outil.c 
	@echo --- Compile outil.c ---
	$(CC) $(CFLAGS) -c $(SRC)/outil.c -o $(BIN)/outil.o
clean : 
	@echo --- Nettoyage des fichiers temporaires --- 
	@-$(RM) $(BIN)/*
