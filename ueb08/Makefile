CC = gcc -Wall
PRG = ueb08
OBJ = ueb08.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb08.o: ueb08.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
