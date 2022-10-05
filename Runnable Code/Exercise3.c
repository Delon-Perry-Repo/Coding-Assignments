include <stdio.h>

int main(){
	
	char name[32];
	char city[64];
	unsigned short birthYear;
	
	printf("What is your first name?: ");
	scanf("%s", name);
	if(name > 32){
	printf("Name cannot be longer than 32 characters.");
	}
	printf("What is your birth year?: ");
	scanf("%hu", &birthYear);
	printf("What is your city of residence?: ");
	scanf(" [^\n]%s", city);
	
	return 0;
}