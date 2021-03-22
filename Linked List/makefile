CC = gcc

objects = linkedList.o functions.o

LinkedList: $(objects)
	$(CC) -o linkedList $(objects)

LinkedList.o: linkedList.h

functions.o: linkedList.h

.PHONY: clean
clean:
	rm $(objects) linkedList