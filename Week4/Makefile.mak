Exercise6: Exercise6.c
        gcc Exercise6.o -o Exercise6
	 
Exercise6.o: Exercise6.c
        gcc Exercise6.c -c -o Exercise6.o
	 
clean:
        rm Exercise6
        rm *.o 	 