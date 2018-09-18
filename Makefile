run: main.o heap.o 
	g++ main.o heap.o -o run

main.o: main.cpp main.h 
	g++ -c main.cpp 

heap.o: heap.cpp heap.h
	g++ -c heap.cpp
clean:
	rm *.o
cleanAll: 
	rm *.o run