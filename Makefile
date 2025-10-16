CC := gcc
FLAGS := -std=c99 -Werror -Wall -Wextra

build:
	$(CC) $(FLAGS) -c main.c 
	$(CC) $(FLAGS) -c start.c
	$(CC) $(FLAGS) -c shapes.c
	$(CC) $(FLAGS) -c input_valid.c
	$(CC) $(FLAGS) -c free_shapes.c
	$(CC) $(FLAGS) -c menu.c
	$(CC) $(FLAGS) -o bin/main start.o main.o shapes.o input_valid.o free_shapes.o menu.o