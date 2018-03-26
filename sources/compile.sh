#!/bin/bash
gcc -c interface.c plateau.c partie.c alea.c IA.c main.c -c -Wall -g
gcc interface.o plateau.o partie.o alea.o IA.o main.o -o avalam
rm *.o
