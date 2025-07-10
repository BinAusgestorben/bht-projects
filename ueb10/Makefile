CC = gcc -Wall
PRG = ueb10
OBJ = ueb10.o tools.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^ -lm

ueb10.o: ueb10.c tools.h
	$(CC) -c $<

tools.o: tools.c tools.h
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run: 
	./$(PRG)

all: clean $(PRG) run
