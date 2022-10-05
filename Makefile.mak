all: rns node

rns: rns.c
	gcc -o rns rns.c
	
node: node.c
	gcc -o node node.c