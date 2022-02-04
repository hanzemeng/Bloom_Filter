FLAGS = -Wall -std=c++17

PA1: LinkedList.o HashTable.o BloomFilter.o main.o 
	g++ ${FLAGS} LinkedList.o HashTable.o BloomFilter.o main.o -o PA1

LinkedList.o: LinkedList.h LinkedList.cpp
	g++ ${FLAGS} LinkedList.cpp -c

HashTable.o: LinkedList.h HashTable.h HashTable.cpp
	g++ ${FLAGS} HashTable.cpp -c

BloomFilter.o: HashTable.h BloomFilter.h BloomFilter.cpp
	g++ ${FLAGS} BloomFilter.cpp -c

main.o: main.cpp BloomFilter.h
	g++ ${FLAGS} main.cpp -c

clean:
	rm -f *.o PA1


run:
	./PA1 setup.txt input.txt successfulSearch.txt failedSearch.txt remove.txt