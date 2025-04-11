CC = gcc -Wall
PRG = ueb03 
OBJ = ueb03.o

$(PRG): $(OBJ)
	$(CC) -o $@ $^

ueb03.o: ueb03.c
	$(CC) -c $<

clean:
	rm -f $(OBJ) $(PRG)

run:
	./$(PRG)

all: clean $(PRG) run
	
