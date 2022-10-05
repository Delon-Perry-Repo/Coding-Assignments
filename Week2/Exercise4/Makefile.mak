Project1: Project1.c
        gcc Project1.o -o Project1
	 
Project1.o: Project1.c
        gcc Project1.c -c -o Project1.o
	 
clean:
        rm Project1
        rm *.o 	 