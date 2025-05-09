CC = gcc -Wall
PRG = ueb05
OBJ = ueb05.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb05.o: ueb05.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
