Project2: Project2.c
        gcc Project2.o -o Project2
	 
Project2.o: Project2.c
        gcc Project2.c -c -o Project2.o
	 
clean:
        rm Project2
        rm *.o 	 