IDIR = ./include

SRCDIR = ./src

CC = gcc

CFLAGS =	-Wall	-I$(IDIR)	-g	-O2	-O3	-Ofast	-fno-stack-protector	-funroll-loops	-flto	-finline-functions -std=c99

OBJDIR = objects

BINDIR = bin


SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

all: objfolder binfolder bin/main

binfolder:
	mkdir -p $(BINDIR)

objfolder:
	mkdir -p $(OBJDIR)

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@ 

$(OBJDIR)/main.o: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run 

clean:
	 rm -rf $(OBJDIR) $(BINDIR)
