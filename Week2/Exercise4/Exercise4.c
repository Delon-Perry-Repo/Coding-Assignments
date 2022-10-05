#include <stdio.h>
#include <string.h>

int main()
{
    char name1[32],name2[32],name3[32],name4[32],name5[32],name6[32],name7[32],name8[32],name9[32],name10[32];
	char city1[64],city2[64],city3[64],city4[64],city5[64],city6[64],city7[64],city8[64],city9[64],city10[64];
	unsigned short birthYear1,birthYear2,birthYear3,birthYear4,birthYear5,birthYear6,birthYear7,birthYear8,birthYear9,birthYear10;;
	unsigned short i = 1, j = 1, k = 1;
	char contInput[32];
	
do{
	if(i == 1){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name1);
			if(strlen(name1) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name1) > 32);
	}else if(i == 2){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name2);
			if(strlen(name2) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name2) > 32);
	}else if(i == 3){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name3);
			if(strlen(name3) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name3) > 32);
	}else if(i == 4){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name4);
			if(strlen(name4) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name4) > 32);
	}else if(i == 5){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name5);
			if(strlen(name5) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name5) > 32);
	}else if(i == 6){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name6);
			if(strlen(name6) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name6) > 32);
	}else if(i == 7){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name7);
			if(strlen(name7) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name7) > 32);
	}else if(i == 8){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name8);
			if(strlen(name8) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name8) > 32);
	}else if(i == 9){
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name9);
			if(strlen(name9) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name9) > 32);
	}else{
		do{
			printf("What is your first name? (Enter 'N' To Cancel): " );
			scanf("%s", name10);
			if(strlen(name10) > 32)
				printf("Name cannot be longer than 32 characters.\n");
		}while(strlen(name10) > 32);
	}
	++i;
	if(*name1 == 'N'){
	    break;
	}else if(*name2 == 'N'){
	    break;
	}else if(*name3 == 'N'){
	    break;
	}else if(*name4 == 'N'){
	    break;
	}else if(*name5 == 'N'){
	    break;
	}else if(*name6 == 'N'){
	    break;
	}else if(*name7 == 'N'){
	    break;
	}else if(*name8 == 'N'){
	    break;
	}else if(*name9 == 'N'){
	    break;
	}else if(*name10 == 'N'){
	    break;
	}
}while(i < 11);
	
		
	
do{
	if(j == 1){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear1, contInput);
			if(birthYear1 < 2010 || birthYear1 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear1 < 2010 || birthYear1 > 2013);
}else if(j == 2){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear2, contInput);
			if(birthYear2 < 2010 || birthYear2 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear2 < 2010 || birthYear2 > 2013);
}else if(j == 3){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear3, contInput);
			if(birthYear3 < 2010 || birthYear3 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear3 < 2010 || birthYear3 > 2013);
}else if(j == 4){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear4, contInput);
			if(birthYear4 < 2010 || birthYear4 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear4 < 2010 || birthYear4 > 2013);
}else if(j == 5){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear5, contInput);
			if(birthYear5 < 2010 || birthYear5 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear5 < 2010 || birthYear5 > 2013);
}else if(j == 6){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear6, contInput);
			if(birthYear6 < 2010 || birthYear6 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear6 < 2010 || birthYear6 > 2013);
}else if(j == 7){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear7, contInput);
			if(birthYear7 < 2010 || birthYear7 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear1 < 2010 || birthYear1 > 2013);
}else if(j == 8){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear8, contInput);
			if(birthYear8 < 2010 || birthYear8 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear8 < 2010 || birthYear8 > 2013);
}else if(j == 9){
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear9, contInput);
			if(birthYear9 < 2010 || birthYear9 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear9 < 2010 || birthYear9 > 2013);
}else{
		do{
			printf("What is your birth year? (Enter 'N' After The Final Input To Cancel Ex. 2010N): ");
			scanf("%hu%c", &birthYear10, contInput);
			if(birthYear10 < 2010 || birthYear10 > 2013)
				printf("Birth year must be between the years 2010 and 2013.\n");
	}while(birthYear10 < 2010 || birthYear10 > 2013);
}
	++j;
	if(*contInput == 'N'){
		break;
	}
}while(j < 11);
	
do{
	if(k == 1){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city1, 64, stdin);
		if(strlen(city1) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city1) > 64);
}else if(k == 2){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city2, 64, stdin);
		if(strlen(city2) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city2) > 64);
}else if(k == 3){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city3, 64, stdin);
		if(strlen(city3) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city3) > 64);
}else if(k == 4){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city4, 64, stdin);
		if(strlen(city4) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city4) > 64);
}else if(k == 5){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city5, 64, stdin);
		if(strlen(city5) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city5) > 64);
}else if(k == 6){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city6, 64, stdin);
		if(strlen(city6) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city6) > 64);
}else if(k == 7){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city7, 64, stdin);
		if(strlen(city7) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city7) > 64);
}else if(k == 8){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city8, 64, stdin);
		if(strlen(city8) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city8) > 64);
}else if(k == 9){
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city9, 64, stdin);
		if(strlen(city9) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city9) > 64);
}else{
		do{
		printf("What is your city of residence? (Enter 'N' To Cancel): ");
		fgets(city10, 64, stdin);
		if(strlen(city10) > 64)
			printf("City cannot be longer than 64 characters.\n");
	}while(strlen(city10) > 64);
}
	++k;
	if(*city1 == 'N'){
	    break;
	}else if(*city2 == 'N'){
	    break;
	}else if(*city3 == 'N'){
	    break;
	}else if(*city4 == 'N'){
	    break;
	}else if(*city5 == 'N'){
	    break;
	}else if(*city6 == 'N'){
	    break;
	}else if(*city7 == 'N'){
	    break;
	}else if(*city8 == 'N'){
	    break;
	}else if(*city9 == 'N'){
	    break;
	}else if(*city10 == 'N'){
	    break;
	}
}while(k < 11);
		
	
	
	return 0;
}