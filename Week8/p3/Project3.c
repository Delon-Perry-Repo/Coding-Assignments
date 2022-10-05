#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PLAYERS 12
#define MIN_PLAYERS 9
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024
#define MAX_YEAR 2014
#define MIN_YEAR 2009
#define MAX_STREET 9999
#define MIN_STREET 1
#define MAX_PHONE 12
#define LOADING_TIME 50


    enum{
        noSort = 0,
        Unsorted = 1,
        Age = 2,
        Last = 3
    }sortTypes;

    enum{
    noInput = 0,
    Search = 2,
    Add = 1,
    Print = 3,
    Save = 4,
    Load = 5,
    Clear = 6,
    Display = 7
}mainMenu;

char buffer[BUFFER_SIZE];

typedef struct playerRoster{
    char *firstName;
    char *lastName;
    char* firstParentName;
	char* lastParentName;
	char* streetName;
	char* phoneNumber;
	char* teamName;
	int birthYear;
	int streetNumber;
	char *playerCity;
    struct playerRoster *next;
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
}playerNode;


void addPlayer(playerNode* player){
    playerNode* first = player;
    
    while(first->next != NULL){
             first = first->next;
         }
         
         first->next = (playerNode*)malloc(sizeof(playerNode));
         first->next->next = NULL;
}

void readReturns(FILE* printRoster, playerNode* team){
    playerNode* first = team;
    
    while(first->next != NULL){
        first = first->next;
    }
    
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%s", buffer);
   first->firstName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->firstName, buffer);
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%s", buffer);
   first->lastName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->lastName, buffer);
   fscanf(printRoster, "%d", &first->streetNumber);
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, " %[^\n]s", buffer);
   first->streetName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->streetName, buffer);
   fscanf(printRoster, "%d", &first->birthYear);
   fscanf(printRoster, " %[^\n]s", buffer);
   first->playerCity = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->playerCity, buffer);
   fgetc(printRoster);
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%s", buffer);
   first->firstParentName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->firstParentName, buffer);
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%s", buffer);
   first->lastParentName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->lastParentName, buffer);
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%s", buffer);
   first->phoneNumber = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->phoneNumber, buffer);
   fscanf(printRoster, "%u", &first->phoneType);
   fscanf(printRoster, "%u", &first->guardianType);
}

void printRoster(playerNode *player){
    playerNode *team = player;
          while(team != NULL){
                if(team->next == NULL)
                break;
            printf("First:%s\t\tLast:%s\t\tStreet#:%d\tStreet:%s\tCity:%s\tD.O.B:%d\tParentF:%s\tParentL:%s\n", team->firstName, team->lastName, team->streetNumber, team->streetName,team->playerCity, team->birthYear, team->firstParentName, team->lastParentName);
            printf("Phone#:%s\tType:", team->phoneNumber);
            switch(team->phoneType){
                case 1: printf("Home\t"); break;
                case 2: printf("Work\t"); break;
                default: printf("Cell\t"); break;
            }
            printf("Parent-Type:");
            switch(team->guardianType){
                case 1: printf("Mother\n\n"); break;
                case 2: printf("Father\n\n"); break;
                case 3: printf("Grandmother\n\n"); break;
                case 4: printf("Grandfather\n\n"); break;
                default: printf("Other\n\n"); break;
            }
            team = team->next;
          }
        }
    
void searchPlayer(playerNode * player, char *name){
    playerNode *team = player;
    do{
    char *placeHolder = (team->lastName);
    if(strcmp(placeHolder, name) != 0){
        printf("No player found.\n\n");
        break;
    }else if(strcmp(placeHolder, name) == 0){
       printf("First:%s\t\t\tLast:%s\t\tStreet#:%d\tStreet:%s\tCity:%s\tD.O.B:%d\tParentF:%s\tParentL:%s\n", team->firstName, team->lastName, team->streetNumber, team->streetName,team->playerCity, team->birthYear, team->firstParentName, team->lastParentName);
            printf("Phone#:%s\tType:", team->phoneNumber);
            switch(team->phoneType){
                case 1: printf("Home\t"); break;
                case 2: printf("Work\t"); break;
                default: printf("Cell\t"); break;
            }
            printf("Parent-Type:");
            switch(team->guardianType){
                case 1: printf("Mother\n\n"); break;
                case 2: printf("Father\n\n"); break;
                case 3: printf("Grandmother\n\n"); break;
                case 4: printf("Grandfather\n\n"); break;
                default: printf("Other\n\n"); break;
            }
        break;
    } else{
        team = team->next;
    }
  }while(team != NULL);

}

void printTeam(playerNode * player){
    int count = 0;
    printf("Team Names\n\n");
    playerNode *team = player;
    while(team != NULL){
        if(team->next == NULL)
                break;
        ++count;
        printf("%d.\t%s\n", count, team->teamName);
        team = team->next;
    }
}

    
void saveRoster(FILE* fullRoster, playerNode *player, int numPlayers){
    fprintf(fullRoster, "%d\n", numPlayers);
    playerNode *team = player;
        while(team != NULL){
            if(team->next == NULL)
                break;
            fprintf(fullRoster, "%s\t%s\t%d\t%s\t%s\t%d\t%s\t%s\t%s\t%u\t%u\n", team->firstName, team->lastName, team->streetNumber, team->streetName,team->playerCity, team->birthYear, team->firstParentName, team->lastParentName, team->phoneNumber, team->phoneType, team->guardianType);
            team = team->next;
        }
    }    


void clearRoster(playerNode *roster){
   while(roster->next != NULL){
       playerNode *first = roster;
       
       while(first->next != NULL){
           first = first->next;
       }
       free(first->next->firstName);
       free(first->next->lastName);
       free(first->next->firstParentName);
       free(first->next->lastParentName);
       free(first->next->playerCity);
       free(first->next->phoneNumber);
       free(first->next->streetName);
       free(first->next->teamName);
       free(first->next);
       first->next = NULL;
   }
    if(roster->next == NULL){
       free(roster->firstName);
       free(roster->lastName);
       free(roster->firstParentName);
       free(roster->lastParentName);
       free(roster->playerCity);
       free(roster->phoneNumber);
       free(roster->streetName);
       free(roster->teamName);
       free(roster);
    }
}

int checkString (char * buffer, int maxChar){
    if(sscanf(buffer, "%d", &maxChar)){
        printf("Invalid Input\n\n");
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

void yearSort(playerNode* player, int count){
 }

void newPlayer(playerNode* player){
    playerNode* first = player;
    int playerNumber;
    int playerRelation;
    
    while(first->next != NULL){
     first = first->next;
 }
 
 
      do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's first name?: ");
		scanf("%s", buffer);
		printf ("\n");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->firstName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->firstName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	  do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's last name?: ");
		scanf("%s", buffer);
		printf ("\n");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->lastName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->lastName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	 do{
	  printf ("What is the Player's street number?: ");
	  scanf("%d", &first->streetNumber);
	  printf ("\n");
	  if(first->streetNumber < MIN_STREET || first->birthYear > MAX_STREET){
	      printf ("Street number must be between the numbers 1 and 9999.\n");
	       scanf ("%*[^\n]");
	       	printf ("\n");
	  }
	}while(first->streetNumber < MIN_STREET || first->streetNumber > MAX_STREET);
	

    do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's street name?: ");
		scanf(" %[^\n]s", buffer);
			printf ("\n");
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	 first->streetName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->streetName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);

    
    do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's city?: ");
		scanf(" %[^\n]s", buffer);
			printf ("\n");
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	 first->playerCity = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->playerCity, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);


	do{
	  printf ("What is the Player's birth year?: ");
	  scanf("%d", &first->birthYear);
	  printf ("\n");
	  if(first->birthYear < MIN_YEAR || first->birthYear > MAX_YEAR){
	      printf ("Birth year must be between the years 2009 and 2014.\n");
	       scanf ("%*[^\n]");
	       	printf ("\n");
	  }
	}while(first->birthYear < MIN_YEAR || first->birthYear > MAX_YEAR);
	
	 do{
	 memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the first name of the Player's guardian?: ");
		scanf("%s", buffer);
		printf ("\n");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->firstParentName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->firstParentName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	 do{
	 memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the last name of the Player's guardian?: ");
		scanf("%s", buffer);
		printf ("\n");
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->lastParentName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->lastParentName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	 do{
	 memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the phone number of the Player's guardian? (XXX-XXX-XXXX): ");
		scanf("%s", buffer);
		printf ("\n");
		if(strlen(buffer) > MAX_PHONE || strlen(buffer) < MAX_PHONE)
		printf("Invalid Phone Number\n\n");
	 }while(strlen(buffer) > MAX_PHONE || strlen(buffer) < MAX_PHONE);
	 first->phoneNumber = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->phoneNumber, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	 do{
	  printf ("What is the guardian's phone type? (1-Home, 2-Work, 3-Cell): ");
	  scanf("%u", &first->phoneType);
	  printf ("\n");
	  if(first->phoneType < Home || first->phoneType > Cell){
	      printf ("Invaild Phone Type.\n");
	       scanf ("%*[^\n]");
	       	printf ("\n");
	  }
	}while(first->phoneType < Home || first->phoneType > Cell);
	
	do{
	  printf ("What is the guardian's relation to the player? (1-Mother, 2-Father, 3-Grandmother, 4-Grandfather, 5-Other): ");
	  scanf("%u", &first->guardianType);
	  printf ("\n");
	  if(first->guardianType < Mother || first->guardianType > Other){
	      printf ("Invaild Guardian Type.\n");
	       scanf ("%*[^\n]");
	       	printf ("\n");
	  }
	}while(first->guardianType < Mother || first->guardianType > Other);
}


int main(){
 FILE* fullRoster;   
 int count = 0;
 int mainInput;
 int sortInput;
 char userInput = 'N';
 int loadedRoster = 0;
 int savedRoster = 0;
 

playerNode* team = NULL;
   team = (playerNode*) malloc(sizeof(playerNode));
   if (team == NULL){
      return 1;
   }
   team->next = NULL;
   
   do{
printf("\t\tWelcome to the Summer 2021 Little League Roster Filler\n");
printf("\t\t\t    Please choose an application:\n\n");
printf("\t(1 - ADD PLAYERS\t2 - SEARCH PLAYERS\t3 - DISPLAY ROSTER)\t\n");
if(savedRoster == 0){
    if(loadedRoster == 0){
printf("\t(5 - LOAD ROSTER\t6 - CLEAR ROSTER\t7 - DISPLAY TEAMS)\n");
printf("\t(0 - QUIT)\n");
   }else{
printf("\t(7 - DISPLAY TEAMS\t6 - CLEAR ROSTER\t0 - QUIT)\n");
}
}else if(savedRoster == 1){
    if(loadedRoster == 0){
printf("\t(4 - SAVE ROSTER\t5 - LOAD ROSTER\t\t6 - CLEAR ROSTER)\n");
printf("\t(7 - DISPLAY TEAMS\t0 - QUIT)\n");
}else{
printf("\t(4 - SAVE ROSTER\t6 - CLEAR ROSTER\t7 - DISPLAY TEAMS)\n");
printf("\t(0 - QUIT)\n");
}
}
scanf("%d", &mainInput);
printf("\n");
switch(mainInput){
    
    case Add:
    if(savedRoster == 1){
        printf("Please save before adding new players.\n\n");
    }else{
    do{
       if(count >= MAX_PLAYERS)
       break;
       
   newPlayer(team);
	 ++count;
	 
	 if(count >= MAX_PLAYERS)
       break;
	 
	 do{
	 memset(buffer, '\0', BUFFER_SIZE);
	 printf ("Would you like to add more players? (%d of 10) (Y - Yes or N - No): ", count);
     scanf("%s", buffer);
     userInput = buffer[0];
     if(buffer[0] == 'Y' || buffer[0] == 'N')
     break;
	 }while(1);
    
     addPlayer(team);
     
    }while(userInput != 'N');
    ++savedRoster;
    printf ("\n");
    break;


    case Search: 
    if(team->firstName == NULL){
        printf("The roster is empty. No players to search.\n\n");
    }else{
    memset(buffer, '\0', BUFFER_SIZE);
      printf("Please enter a player's name to search: ");
      scanf("%s", buffer);
      printf("\n");
      searchPlayer(team, buffer);
        }
    }
      break;
      
    case Print:
    if(team->firstName == NULL){
          printf("The roster is empty. No players to display\n\n");
    }else{
        printf("How would you like to sort the roster? (1 - Unsorted, 2 - By age, 3 - By last name): ");
        printf("\n");
        scanf("%d", &sortInput);
        switch(sortInput){
            case Unsorted: 
            printRoster(team);
            break;
            
            case Age:
            break;
            
            case Last:
            break;
        }
    
    printf("\n");
    }
    break;
    
    case Save:
    // if(count < MIN_PLAYERS){
    // printf("You need a minimum of nine players to save a roster. (%d of 12)\n\n", count);
    // }else{
  do{
      if(loadedRoster == 1)
          addPlayer(team);
	 memset(buffer, '\0', BUFFER_SIZE);
		printf ("What would you like to name this team? (teamname.txt): ");
		scanf("%s", buffer);
		printf ("\n");
		if(strlen(buffer) > MAX_NAME_LEN)
		printf("Invalid Team Name\n\n");
	 }while(strlen(buffer) > MAX_NAME_LEN);
	 team->teamName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (team->teamName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
    savedRoster -= 1;    
    fullRoster = fopen(team->teamName, "w");
    saveRoster(fullRoster, team, count);
    fclose(fullRoster);
    printf("Roster Saved!\n");
    if(loadedRoster == 0)
    addPlayer(team);
    // }
    break;
    
    case Load:
        do{
	 memset(buffer, '\0', BUFFER_SIZE);
		printf ("Enter team you would like to load (teamname.txt): ");
		scanf("%s", buffer);
		printf ("\n");
		if(strlen(buffer) > MAX_NAME_LEN)
		printf("Invalid Team Name\n\n");
	 }while(strlen(buffer) > MAX_NAME_LEN);
	 team->teamName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (team->teamName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
        fullRoster = fopen(team->teamName, "r");
        if(fullRoster == NULL){
         printf("Error Opening File\n\n");
         continue;
      }else{
       fscanf(fullRoster, "%d", &count);
       fgetc(fullRoster);
      }
       for(int i = 0; i < count; ++i){
           readReturns(fullRoster, team);
           if(i < count && i != MAX_PLAYERS - 1)
           addPlayer(team);
       }
       fclose(fullRoster);
printf("Loading Complete!\n\n");
++loadedRoster;
break;


    case Clear:
    printf("Roster Cleared.\n");
    clearRoster(team);
    break;
    
    case Display:
    if(team->teamName == NULL){
    printf("There are no teams.\n\n");
    break;
    }
    printTeam(team);
    break;
    

    
    case noInput: 
    break;break;
        
        
    default:
        printf("Please Try Again.\n\n");
        scanf ("%*[^\n]");
    }
  }while(mainInput != 0);
}