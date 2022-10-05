#include <stdio.h>
#include <string.h>
#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

int main(){
  char name[MAX_PLAYERS][MAX_NAME_LEN];
  char city[MAX_PLAYERS][MAX_CITY_LEN];
  char buffer[BUFFER_SIZE];
  unsigned short birthYear[MAX_PLAYERS];
  unsigned short i = 0;
  char contInput[32] = "Y";

  while (*contInput == 'Y'){

      do{
	  strcpy (buffer, "");
	  printf ("What is Player %d's first name?: ", i);
	  scanf ("%s", buffer);
	  if (strlen (buffer) > 32)
	    printf ("Name cannot be longer than 32 characters.\n");
	  scanf ("%*[^\n]");
	} while (strlen (buffer) > 32);
      strcpy (name[i], buffer);

      do{
	  printf ("What is Player %d's birth year?: ", i);
	  scanf ("%hu", &birthYear[i]);
	  if (birthYear[i] < 2010 || birthYear[i] > 2013)
	    printf ("Birth year must be between the years 2010 and 2013.\n");
	  scanf ("%*[^\n]");
	}while (birthYear[i] < 2010 || birthYear[i] > 2013);

      do{
	  strcpy (buffer, "");
	  printf ("What is Player %d's city of residence?: ", i);
	  scanf (" %[^\n]s", buffer);
	  if (strlen (buffer) > 64)
	    printf ("City cannot be longer than 64 characters.\n");
	  scanf ("%*[^\n]");
	}while (strlen (buffer) > 64);
      strcpy (city[i], buffer);

      ++i;
      if (i > 10)
	break;
      printf ("Would you like to continue user input? (Y - Yes or N - No): ");
      scanf (" %c", contInput);
    }
  return 0;
}