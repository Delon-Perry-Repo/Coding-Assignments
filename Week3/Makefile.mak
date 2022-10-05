Exercise5: Exercise5.c
        gcc Exercise5.o -o Exercise5
	 
Exercise5.o: Exercise5.c
        gcc Exercise5.c -c -o Exercise5.o
	 
clean:
        rm Exercise5
        rm *.o 	 