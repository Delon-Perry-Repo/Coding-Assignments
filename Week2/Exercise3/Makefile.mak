pgm: Exercise3.c
     gcc -o pgm Exercise3.c
	 
output: Exercise3.o
     g++ Exercise3.o -o output
	 
Exercise3.o: Exercise3.c
     g++ -c Exercise3.c

clean:
     rm *.o output	 