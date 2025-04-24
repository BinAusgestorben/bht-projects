CC = gcc -Wall
PRG = ueb04
OBJ = ueb04.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb04.o: ueb04.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
