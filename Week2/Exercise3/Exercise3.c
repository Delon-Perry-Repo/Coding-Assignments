#include <stdio.h>
#include <string.h>

int main(){
	
	char name[32];
	char city[64];
	unsigned short birthYear;
	
	do{
	printf("What is your first name?: ");
	scanf("%s", name);
	if(strlen(name) > 32)
	printf("Name cannot be longer than 32 characters.\n");
	}while(strlen(name) > 32);
	
	do{
	printf("What is your birth year?: ");
	scanf("%hu", &birthYear);
	if(birthYear < 2010 || birthYear > 2013)
	printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear < 2010 || birthYear > 2013);
	
	do{
	printf("What is your city of residence?: ");
	scanf(" [^\n]%s", city);
	if(strlen(city) > 64)
	printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city) > 64);
	
	return 0;
}