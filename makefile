CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: ttt1.o ttt2.o show_node count_nodes alphatoe

ttt1.o: ttt1.c ttt.h
	$(CC) $(CFLAGS) -c ttt1.c -o ttt1.o

ttt2.o: ttt2.c ttt.h
	$(CC) $(CFLAGS) -c ttt2.c -o ttt2.o

show_node.o: show_node.c ttt.h ttt1.o
	$(CC) $(CFLAGS) -c show_node.c -o show_node.o

show_node: show_node.o ttt2.o ttt1.o ttt.h
	$(CC) $(CFLAGS) -o show_node show_node.o ttt2.o ttt1.o

count_nodes.o: count_nodes.c ttt.h ttt1.o
	$(CC) $(CFLAGS) -c count_nodes.c -o count_nodes.o

count_nodes: count_nodes.o ttt2.o ttt1.o ttt.h
	$(CC) $(CFLAGS) -o count_nodes count_nodes.o ttt2.o ttt1.o

alphatoe.o: alphatoe.c ttt.h ttt1.o
	$(CC) $(CFLAGS) -c alphatoe.c -o alphatoe.o

alphatoe: alphatoe.o ttt2.o ttt1.o ttt.h
	$(CC) $(CFLAGS) -o alphatoe alphatoe.o ttt2.o ttt1.o

clean:
	rm *.o show_node count_nodes alphatoe
