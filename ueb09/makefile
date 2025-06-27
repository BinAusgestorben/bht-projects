CC = gcc -Wall
PRG = ueb09
OBJ = ueb09.o matrix.o tools.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb09.o: ueb09.c matrix.h tools.h
	$(CC) -c $<

matrix.o: matrix.c matrix.h tools.h
	$(CC) -c $<

tools.o: tools.c tools.h
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
