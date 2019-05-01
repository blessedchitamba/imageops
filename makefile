#makefile for assignment4
#Blessed Chitamba


CC=g++       #compiler
LIBS=-lm     #libraries that are going to be refferenced


imageops: Image.o imageops.o
	$(CC) -o imageops Image.o imageops.o -std=c++11

Image.o: Image.cpp Image.h
	$(CC) -c -o Image.o Image.cpp -std=c++11

imageops.o: imageops.cpp
	$(CC) -c -o imageops.o imageops.cpp -std=c++11

run:
	./imageops

clean:
	rm -f -r *.o imageops
