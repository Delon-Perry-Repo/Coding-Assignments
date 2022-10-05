Exercise8: Exercise8.c
        gcc Exercise8.o -o Exercise8
	 
Exercise8.o: Exercise8.c
        gcc Exercise8.c -c -o Exercise8.o
	 
clean:
        rm Exercise8
        rm *.o 	 