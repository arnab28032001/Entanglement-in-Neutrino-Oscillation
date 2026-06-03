CC = gcc

CFLAGS = -O2

LIBS = `globes-config --libs`

INC = `globes-config --cflags`

all:
	$(CC) t2k_triality.c -o t2k_triality $(INC) $(LIBS) -lm
