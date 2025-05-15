CC = gcc -Wall
PRG = ueb07
OBJ = ueb07.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb07.o: ueb07.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
