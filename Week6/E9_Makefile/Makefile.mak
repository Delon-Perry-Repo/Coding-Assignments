Exercise9: Exercise9.c
        gcc Exercise9.o -o Exercise9
	 
Exercise9.o: Exercise9.c
        gcc Exercise9.c -c -o Exercise9.o
	 
clean:
        rm Exercise9
        rm *.o 	 