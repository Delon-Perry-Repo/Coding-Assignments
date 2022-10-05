#include <stdio.h>

int main(){
	
	char name[32];
	char city[32];
	unsigned short birthYear;
	
	printf("What is your first name?: \n");
	scanf("%s", name);
	printf("What is your birth year?: \n");
	scanf("%hu", &birthYear);
	printf("What is your city of residence?: \n");
	scanf(" [^\n]%s", city);
	
	return 0;
}