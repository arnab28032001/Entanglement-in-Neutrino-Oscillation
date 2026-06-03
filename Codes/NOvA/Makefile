CC = gcc

CFLAGS = -O2

LIBS = `globes-config --libs`

INC = `globes-config --cflags`

all:
	$(CC) nova_triality.c -o nova_triality $(INC) $(LIBS) -lm
