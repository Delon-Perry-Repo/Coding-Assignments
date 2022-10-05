Exercise7: Exercise7.c
        gcc Exercise7.o -o Exercise7
	 
Exercise7.o: Exercise7.c
        gcc Exercise7.c -c -o Exercise7.o
	 
clean:
        rm Exercise7
        rm *.o 	 