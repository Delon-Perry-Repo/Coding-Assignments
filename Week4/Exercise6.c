#include <stdio.h>
#include <string.h>
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
  char name[MAX_PLAYERS][MAX_NAME_LEN];
  char city[MAX_PLAYERS][MAX_CITY_LEN];
  char buffer[BUFFER_SIZE];
  unsigned short birthYear[MAX_PLAYERS];
  unsigned short i = 0;
  char contInput[32] = "Y";

  while (*contInput == 'Y'){

      do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's first name?: ", i);
		scanf ("%s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	  strcpy (name[i], buffer);
	  memset(buffer, '\0', BUFFER_SIZE);
      
      do{
	  printf ("What is Player %d's birth year?: ", i);
	  scanf ("%hu", &birthYear[i]);
	  if (birthYear[i] < 2010 || birthYear[i] > 2013)
	    printf ("Birth year must be between the years 2010 and 2013.\n");
	    scanf ("%*[^\n]");
	}while (birthYear[i] < 2010 || birthYear[i] > 2013);

     do{
		memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's city of residence?: ", i);
		scanf ("%s", buffer);
		scanf ("%*[^\n]");
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	  strcpy (city[i], buffer);
	  memset(buffer, '\0', BUFFER_SIZE);

      ++i;
      if (i > 10)
	break;
      printf ("Would you like to continue user input? (Y - Yes or N - No): ");
      scanf (" %c", contInput);
    }
  return 0;
}