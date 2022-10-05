#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

struct{
	char* name;
	int birthYear;
	char* city;
}playerRoster;

int readReturns(playerRoster *players){
FILE* roster = fopen("roster.txt", "r");
int i = 0;
while(fscanf(roster, "%s %d %s", players[i].name,&players[i].birthYear, players[i].city) == 3)
++i;
fclose(roster);
return i;
}

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
  char buffer[BUFFER_SIZE];
  char contInput[32];
  char saveRoster[32];
  char loadRoster[32];
  int playerCount = 0;
  char placeHolder;
  
  playerRoster* playerInfo = malloc(MAX_PLAYERS * sizeof(*playerInfo));
  
  printf("Would you like to load a previous roster? (Y - Yes or N - No): ");
  scanf(" %c", loadRoster);
  
  if(*loadRoster == 'Y'){
  FILE* roster = fopen("roster.txt", "r");
  placeHolder = fgetc(roster);
  while(placeHolder != EOF){
      if(placeHolder == '\n')
      playerCount += 1;
      placeHolder = fgetc(roster);
    }
    readReturns(playerInfo);
    fclose(roster);
  }

  for(int i = playerCount; i < MAX_PLAYERS; ++i){

      do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's first name?: ", i + 1);
		scanf ("%s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	  playerInfo[i].name = (char*)malloc(strlen(buffer) * sizeof(char));
	  strcpy (playerInfo[i].name, buffer);
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
		printf ("What is Player %d's city of residence?: ", i + 1);
		scanf (" %[^\n]s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	  playerInfo[i].city = (char*)malloc(strlen(buffer) * sizeof(char));
	  strcpy (playerInfo[i].city, buffer);
	  memset(buffer, '\0', BUFFER_SIZE);
      
      if(i != 9){
      printf ("Would you like to continue user input? (Y - Yes or N - No): ");
      scanf (" %c", contInput);
      printf("\n");
      }else{
          printf("\n");
          printf("\t\tPlayer Roster\n\n");
          printf("          \tName:\tD-O-B:\tCity:\n");
          for(int k = 0; k < 10; ++k){
              printf("Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          
          printf("\n");
          printf("Would you like to save this roster? (Y - Yes or N - No): ");
          scanf(" %c", saveRoster);
          
          if(*saveRoster == 'Y'){
              if(*loadRoster == 'Y'){
                  FILE* roster = fopen("roster.txt", "a");
          for(int k = playerCount; k < (i + 1); ++k){
              fprintf(roster, "Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          fclose(roster);
              }
              FILE* roster = fopen("roster.txt", "w");
          for(int k = 0; k < (i + 1); ++k){
              fprintf(roster, "Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          fclose(roster);
        }else{
          for(int j = 0; j < i; ++j ){
            free(playerInfo[j].name);
            free(playerInfo[j].city);
        }
        free(playerInfo);
        }
      }
 
      if(*contInput == 'N'){
          printf("\t\tPlayer Roster\n\n");
          printf("          \tName:\tD-O-B:\tCity:\n");
          for(int k = 0; k < (i + 1); ++k){
              printf("Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          
          printf("\n");
          printf("Would you like to save this roster? (Y - Yes or N - No): ");
          scanf(" %c", saveRoster);
          
          if(*saveRoster == 'Y'){
              if(*loadRoster == 'Y'){
                  FILE* roster = fopen("roster.txt", "a");
          for(int k = playerCount; k < (i + 1); ++k){
              fprintf(roster, "Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          fclose(roster);
              }
              FILE* roster = fopen("roster.txt", "w");
          for(int k = 0; k < (i + 1); ++k){
              fprintf(roster, "Player %d:\t%s\t%d\t%s\n", k + 1, playerInfo[k].name, playerInfo[k].birthYear, playerInfo[k].city);
          }
          fclose(roster);
        }else
         break;
          
          for(int j = 0; j < i; ++j ){
            free(playerInfo[j].name);
            free(playerInfo[j].city);
        }
        free(playerInfo);
        break;
    }
   }
  return 0;
}