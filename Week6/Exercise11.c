#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024

struct playerRoster{
    char *firstName;
	int birthYear;
	char *playerCity;
    struct playerRoster *next;
};

struct playerRoster *getNewPlayer(char *firstName, const int birthYear, char *playerCity){
		struct playerRoster *newPlayer = NULL;
		newPlayer = malloc(sizeof(struct playerRoster));
		if(newPlayer != NULL){
			newPlayer->next = NULL;
			newPlayer->firstName = firstName;
			newPlayer->birthYear = birthYear;
			newPlayer->playerCity = playerCity;
		}
		return newPlayer;
}

void printPlayer(const struct playerRoster *player){
    printf("Name:%s\tD.O.B:%d\tCity:%s\n", player->firstName, player->birthYear, player->playerCity);
}

void printRoster(const struct playerRoster *roster){
    const struct playerRoster *team;
    team = roster;
    if(team == NULL){
        printf("Roster is empty.\n");
    }else{
        while(team){
            printPlayer(team);
            team = team->next;
        }
    }
}

void savePlayer(FILE* fullRoster, const struct playerRoster *player){
    fprintf(fullRoster, "Name:%s\tD.O.B:%d\tCity:%s\n", player->firstName, player->birthYear, player->playerCity);
}

void saveRoster(const struct playerRoster *roster){
    FILE* fullRoster = fopen("roster.txt", "w");
    const struct playerRoster *team;
    team = roster;
        while(team){
            savePlayer(fullRoster, team);
            team = team->next;
        }
        fclose(fullRoster);
    }


void clearRoster(struct playerRoster *roster){
    struct playerRoster *next;
    while(roster){
        next = roster->next;
        free(roster);
        roster = next;
    }
}

int checkString (char * buffer, int maxChar){
    if(sscanf(buffer, "%d", &maxChar)){
        printf("Invalid Name\n");
        return 1;
    }
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

 int i = 0;
 struct playerRoster *first = NULL;
 struct playerRoster *added = NULL;
 
 char buffer[BUFFER_SIZE];
 char command[BUFFER_SIZE];
 int birthYear;
 char firstName[MAX_PLAYERS][MAX_NAME_LEN];
 char playerCity[MAX_PLAYERS][MAX_CITY_LEN];
 
 for(int i = 0; i < MAX_PLAYERS; ++i){
     
      while(1){
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's first name?: ", i + 1);
		fgets (buffer, BUFFER_SIZE, stdin);
		if(checkString(buffer, MAX_NAME_LEN) == 0)
		break;
	 }
	 strcpy (firstName[i], buffer);
	 
     
	while(1){
	  printf ("What is Player %d's birth year?: ", i + 1);
	  fgets(command, BUFFER_SIZE, stdin);
	  if(strcmp("2010\n", command) == 0 || strcmp("2011\n", command) == 0 || strcmp("2012\n", command) == 0 || strcmp("2013\n", command) == 0){
	    if(sscanf(command, "%d", &birthYear) != 0){
	        	break;
	    }
	  }else{
	      printf ("Birth year must be between the years 2010 and 2013.\n");
	  }
	}
	
	while(1){
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is Player %d's city?: ", i + 1);
		fgets (buffer, BUFFER_SIZE, stdin);
		if(checkString(buffer, MAX_CITY_LEN) == 0)
		break;
	 }
	 strcpy (playerCity[i], buffer);
	
	
	 if(first == NULL){
	        	    first = getNewPlayer(firstName[i], birthYear, playerCity[i]);
	        	    if(first != NULL){
	        	        added = first;
	        	    }
	        	}else{
	        	    added->next = getNewPlayer(firstName[i], birthYear, playerCity[i]);
	        	    if(added->next != NULL){
	        	        added = added->next;
	        	    }
	        	}

	 
	 printf ("Would you like to continue user input? (Y - Yes or N - No): ");
     fgets(command, 64, stdin);
     if(strcmp("N\n", command) == 0 || strcmp("No\n", command) == 0){
         printRoster(first);
         printf("Would you like to save this roster? (Y - Yes or N - No): ");
         fgets(command, 64, stdin);
         if(strcmp("Y\n", command) == 0 || strcmp("Yes\n", command) == 0){
             saveRoster(first);
             break;
         }else{
         break;
         }
     }
     
 }
 clearRoster(first);
 first = NULL;
 added = NULL;
 return 0;
}
     

    
	
 