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

typedef struct{
	char* name;
	int birthYear;
	char* city;
}playerRoster;

int main(){
  char buffer[BUFFER_SIZE];
  char contInput[32] = "Y";
  
  playerRoster* playerInfo = malloc(3 * sizeof(*playerInfo));

  for(int i = 0; i < MAX_PLAYERS; ++i){

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
      }else{
          for(int j = 0; j < i; ++j ){
            free(playerInfo[j].name);
            free(playerInfo[j].city);
        }
        free(playerInfo);
      }
 
      if(*contInput == 'N'){
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