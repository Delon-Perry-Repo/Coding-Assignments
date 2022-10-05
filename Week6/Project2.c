#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

int checkString ( char * buffer, int maxChar){
    unsigned short length = 0;
    length = strlen(buffer);
	if((length) <= maxChar){
		return 0;
	}else{
		printf("String out of range. A max of %d characters are allowed.\n", maxChar);
		return length - maxChar;
	}
}

int main(){
	
	typedef struct{
		char* firstName;
		char* lastName;
		char* firstParentName;
		char* lastParentName;
		char* streetName;
		char* phoneNumber;
		char* cityName;
		int streetNumber;
		int birthYear;
		
	enum{
		noGuardian = 0,
		Mother,
		Father,
		Grandmother,
		Grandfather,
		Other
	}guardianType;
	
	enum{
		noPhone = 0,
		Home,
		Work,
		Cell
	}phoneType;
	
	}playerRoster;
	
  char buffer[BUFFER_SIZE];
  char contInput[32];
  char saveRoster[32];
  char loadRoster[32];
  int playerCount = 0;
  char placeHolder;
  
  playerRoster* playerInfo = malloc(MAX_PLAYERS * sizeof(*playerInfo));

  for(int i = playerCount; i < MAX_PLAYERS; ++i){

      do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's first name?: ", i + 1);
		scanf ("%s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	  playerInfo[i].firstName = (char*)malloc(strlen(buffer) * sizeof(char));
	  strcpy (playerInfo[i].firstName, buffer);
	  memset(buffer, '\0', BUFFER_SIZE);
	  
	  do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's last name?: ", i + 1);
		scanf ("%s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	  playerInfo[i].lastName = (char*)malloc(strlen(buffer) * sizeof(char));
	  strcpy (playerInfo[i].lastName, buffer);
	  memset(buffer, '\0', BUFFER_SIZE);
	  
	   do{
		 printf("What is Player %d's street number?: ", i + 1);
		 scanf("%d", &playerInfo[i].streetNumber);
		 if(playerInfo[i].streetNumber< 1 || playerInfo[i].streetNumber > 9999){
				printf("Invalid street number.\n");
				scanf("%*[^\n]");
		 }
	   }while(playerInfo[i].streetNumber < 1 || playerInfo[i].streetNumber > 9999);
		 
		 do{
			 memset(buffer, '\0', BUFFER_SIZE);
			 printf("What is Player %d's street name?: ", i + 1);
			 scanf(" %[^\n]s", buffer);
			 scanf ("%*[^\n]");
		 }while(checkString(buffer, MAX_NAME_LEN) != 0);
		 playerInfo[i].streetName = (char*)malloc(strlen(buffer) * sizeof(char));
		 strcpy(playerInfo[i].streetName, buffer);
		 memset(buffer, '\0', BUFFER_SIZE);
      

     do{
		memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's city of residence?: ", i + 1);
		scanf (" %[^\n]s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	  playerInfo[i].cityName = (char*)malloc(strlen(buffer) * sizeof(char));
	  strcpy (playerInfo[i].cityName, buffer);
	  memset(buffer, '\0', BUFFER_SIZE);
	  
	  do{
	  printf ("What is Player %d's birth year?: ", i + 1);
	  scanf ("%d", &playerInfo[i].birthYear);
	  if (playerInfo[i].birthYear < 2010 || playerInfo[i].birthYear > 2013)
	    printf ("Birth year must be between the years 2010 and 2013.\n");
	    scanf ("%*[^\n]");
	}while (playerInfo[i].birthYear < 2010 || playerInfo[i].birthYear > 2013);
	
	 do{
		 memset(buffer, '\0', BUFFER_SIZE);
		 printf("What is the first name of Player %d's guardian?: ", i + 1);
		 scanf("%s", buffer);
		 scanf ("%*[^\n]");
		 }while(checkString(buffer, MAX_NAME_LEN) != 0 );
		 playerInfo[i].firstParentName = (char*)malloc(strlen(buffer) * sizeof(char));
	     strcpy (playerInfo[i].firstParentName, buffer);
	     memset(buffer, '\0', BUFFER_SIZE);
		 
		 do{
	     memset(buffer, '\0', BUFFER_SIZE);
		 printf("What is the last name of Player %d's guardian?: ", i + 1);
		 scanf("%s", buffer);
		 scanf ("%*[^\n]");
		 }while(checkString(buffer, MAX_NAME_LEN) != 0 );
		 playerInfo[i].lastParentName = (char*)malloc(strlen(buffer) * sizeof(char));
	     strcpy (playerInfo[i].lastParentName, buffer);
	     memset(buffer, '\0', BUFFER_SIZE);
		 
		 do{
		 memset(buffer, '\0', BUFFER_SIZE);   
		 printf("What is the phone number of Player %d's guardian? (XXX-XXX-XXXX): ", i + 1);
		 scanf("%s", buffer);
		 scanf ("%*[^\n]");
		 if(strlen(buffer) < 12 || strlen(buffer) > 12)
		     printf("Invalid phone pumber.");
		 }while(strlen(buffer) < 12 || strlen(buffer) > 12);
		 playerInfo[i].phoneNumber = (char*)malloc(strlen(buffer) * sizeof(char));
	     strcpy (playerInfo[i].phoneNumber, buffer);
	     memset(buffer, '\0', BUFFER_SIZE);
		 
		 do{
		 printf("What is the phone type of Player %d's guardian? (1-Home, 2-Work, 3-Cell): ", i + 1);
		 scanf("%u", &playerInfo[i].phoneType);
		  if(playerInfo[i].phoneType < Home || playerInfo[i].phoneType > Cell){
				printf("Invalid phone type.\n");
				scanf("%*[^\n]");
		  }
		  
		 }while(playerInfo[i].phoneType < Home || playerInfo[i].phoneType > Cell);
			 
		 do{
		 printf("What is the guardian's relation to Player %d? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ", i + 1);
		 scanf("%u", &playerInfo[i].guardianType);
		  if(playerInfo[i].guardianType > Other || playerInfo[i].guardianType < Mother){
				printf("Invalid guardian type.\n");
				scanf("%*[^\n]");
		  }
		 }while(playerInfo[i].guardianType > Other || playerInfo[i].guardianType < Mother);
      
      if(i != 9){
      printf ("Would you like to continue user input? (Y - Yes or N - No): ");
      scanf (" %c", contInput);
      printf("\n");
      }else{
          printf("\n");
          printf("\t\tPlayer Roster\n\n");
          for(int k = 0; k < 10; ++k){
              printf("Player %d:\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t", k + 1, playerInfo[k].firstName, playerInfo[k].lastName, playerInfo[k].streetNumber, playerInfo[k].streetName, playerInfo[k].cityName, playerInfo[k].birthYear, playerInfo[k].firstParentName, playerInfo[k].lastParentName, playerInfo[k].phoneNumber);
              switch(playerInfo[k].phoneType){
                  case 1: printf("Home\t"); break;
                  case 2: printf("Work\t"); break;
                  default: printf("Cell\t"); break;
              }
              switch(playerInfo[k].guardianType){
                  case 1: printf("Mother\n"); break;
                  case 2: printf("Father\n"); break;
                  case 3: printf("Grandmother\n"); break;
                  case 4: printf("Grandfather\n"); break;
                  default: printf("Other\n"); break;
              }
          }
          
          printf("\n");
          printf("Would you like to save this roster? (Y - Yes or N - No): ");
          scanf(" %c", saveRoster);
          
          if(*saveRoster == 'Y'){
              FILE* roster = fopen("roster.txt", "w");
          for(int k = 0; k < 10; ++k){
              fprintf(roster, "Player %d:\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t", k + 1, playerInfo[k].firstName, playerInfo[k].lastName, playerInfo[k].streetNumber, playerInfo[k].streetName, playerInfo[k].cityName, playerInfo[k].birthYear, playerInfo[k].firstParentName, playerInfo[k].lastParentName, playerInfo[k].phoneNumber);
              switch(playerInfo[k].phoneType){
                  case 1: fprintf(roster, "Home\t"); break;
                  case 2: fprintf(roster, "Work\t"); break;
                  default: fprintf(roster, "Cell\t"); break;
              }
              switch(playerInfo[k].guardianType){
                  case 1: fprintf(roster, "Mother\n"); break;
                  case 2: fprintf(roster, "Father\n"); break;
                  case 3: fprintf(roster, "Grandmother\n"); break;
                  case 4: fprintf(roster, "Grandfather\n"); break;
                  default: fprintf(roster, "Other\n"); break;
              }
          }
          fclose(roster);
        }else{
          for(int j = 0; j < i; ++j ){
            free(playerInfo[j].firstName);
            free(playerInfo[j].lastName);
            free(playerInfo[j].streetName);
            free(playerInfo[j].cityName);
            free(playerInfo[j].firstParentName);
            free(playerInfo[j].lastParentName);
            free(playerInfo[j].phoneNumber);
        }
        free(playerInfo);
        }
      }
 
      if(*contInput == 'N'){
          printf("\n");
          printf("\t\tPlayer Roster\n\n");
          for(int k = 0; k < (i + 1); ++k){
              printf("Player %d:\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t", k + 1, playerInfo[k].firstName, playerInfo[k].lastName, playerInfo[k].streetNumber, playerInfo[k].streetName, playerInfo[k].cityName, playerInfo[k].birthYear, playerInfo[k].firstParentName, playerInfo[k].lastParentName, playerInfo[k].phoneNumber);
              switch(playerInfo[k].phoneType){
                  case 1: printf("Home\t"); break;
                  case 2: printf("Work\t"); break;
                  default: printf("Cell\t"); break;
              }
              switch(playerInfo[k].guardianType){
                  case 1: printf(" Mother\n"); break;
                  case 2: printf(" Father\n"); break;
                  case 3: printf(" Grandmother\n"); break;
                  case 4: printf(" Grandfather\n"); break;
                  default: printf(" Other\n"); break;
              }
          }
          
          printf("\n");
          printf("Would you like to save this roster? (Y - Yes or N - No): ");
          scanf(" %c", saveRoster);
          
          if(*saveRoster == 'Y'){
              FILE* roster = fopen("roster.txt", "w");
          for(int k = 0; k < (i + 1); ++k){
              fprintf(roster, "Player %d:\t%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t", k + 1, playerInfo[k].firstName, playerInfo[k].lastName, playerInfo[k].streetNumber, playerInfo[k].streetName, playerInfo[k].cityName, playerInfo[k].birthYear, playerInfo[k].firstParentName, playerInfo[k].lastParentName, playerInfo[k].phoneNumber);
              switch(playerInfo[k].phoneType){
                  case 1: fprintf(roster, "Home\t"); break;
                  case 2: fprintf(roster, "Work\t"); break;
                  default: fprintf(roster, "Cell\t"); break;
              }
              switch(playerInfo[k].guardianType){
                  case 1: fprintf(roster, "Mother\n"); break;
                  case 2: fprintf(roster, "Father\n"); break;
                  case 3: fprintf(roster, "Grandmother\n"); break;
                  case 4: fprintf(roster, "Grandfather\n"); break;
                  default: fprintf(roster, "Other\n"); break;
              }
          }
          fclose(roster);
        }else
         break;
          
          for(int j = 0; j < i; ++j ){
            free(playerInfo[j].firstName);
            free(playerInfo[j].lastName);
            free(playerInfo[j].streetName);
            free(playerInfo[j].cityName);
            free(playerInfo[j].firstParentName);
            free(playerInfo[j].lastParentName);
            free(playerInfo[j].phoneNumber);
        }
        free(playerInfo);
        break;
    }
   }
  return 0;
}