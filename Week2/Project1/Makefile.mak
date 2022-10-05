Baseball: Project1.o
        gcc Project1.o -o Baseball

Project.o: Project1.c
        gcc Project1.c -c -o Project1.o

clean:
        rm Walmart
        rm *.o

