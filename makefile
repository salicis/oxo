CC = g++
CFLAGS = -Wall

all: ttt

ttt: ttt.o Board.o
	$(CC) $(CFLAGS) -o ttt ttt.o Board.o

ttt.o: ttt.cpp
	$(CC) $(CFLAGS) -c ttt.cpp

Board.o: Board.cpp
	$(CC) $(CFLAGS) -c Board.cpp

clean:
	rm -f ttt *.o

