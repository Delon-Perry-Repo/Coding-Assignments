

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_CITY_LEN 64
#define BUFFER_SIZE 1024
#define MAX_YEAR 2013
#define MIN_YEAR 2010


    enum{
    noInput = 0,
    Search = 1,
    Add = 2,
    End = 3
}mainMenu;

char buffer[BUFFER_SIZE];

typedef struct playerRoster{
    char *firstName;
    char *lastName;
	int birthYear;
	char *playerCity;
    struct playerRoster *next;
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
   memset(buffer, '\0', BUFFER_SIZE);
   fscanf(printRoster, "%d", &first->birthYear);
   fscanf(printRoster, " %[^\n]s", buffer);
   first->playerCity = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
   strcpy(first->playerCity, buffer);
   fgetc(printRoster);
}

void printRoster(playerNode *player){
    playerNode *team = player;
            printf("\n");
        while(team != NULL){
            printf("First:%s\tLast:%s\tD.O.B:%d\tCity:%s\n", team->firstName, team->lastName, team->birthYear, team->playerCity);
            team = team->next;
        }
    }
    
void searchPlayer(playerNode * player, char *name){
    playerNode *team = player;
    while(team != NULL){
    char *placeHolder = (team->lastName);
    if(strcmp(placeHolder, name) == 0){
        printf("First:%s\tLast:%s\tD.O.B:%d\tCity:%s\n", team->firstName, team->lastName, team->birthYear, team->playerCity);
        break;
    }else{
        team = team->next;
    }
  }
}


    
void saveRoster(FILE* fullRoster, playerNode *player, int numPlayers){
    fprintf(fullRoster, "%d\n", numPlayers);
    playerNode *team = player;
        while(team != NULL){
            fprintf(fullRoster, "%s\t%s\t%d\t%s\n", team->firstName, team->lastName, team->birthYear, team->playerCity);
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
       free(first->next->playerCity);
       free(first->next);
       first->next = NULL;
   }
    if(roster->next == NULL){
       free(roster->firstName);
       free(roster->playerCity);
       free(roster);
    }
}

int checkString (char * buffer, int maxChar){
    if(sscanf(buffer, "%d", &maxChar)){
        printf("Invalid Input\n");
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

void newPlayer(playerNode* player){
    playerNode* first = player;
    
    while(first->next != NULL){
     first = first->next;
 }
 
      do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's first name?: ");
		scanf("%s", buffer);
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->firstName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->firstName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
	 do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's last name?: ");
		scanf("%s", buffer);
	 }while(checkString(buffer, MAX_NAME_LEN) != 0);
	 first->lastName = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->lastName, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
	 
     
	do{
	  printf ("What is the Player's birth year?: ");
	  scanf("%d", &first->birthYear);
	  if(first->birthYear < MIN_YEAR || first->birthYear > MAX_YEAR){
	      printf ("Birth year must be between the years 2010 and 2013.\n");
	       scanf ("%*[^\n]");
	  }
	}while(first->birthYear < MIN_YEAR || first->birthYear > MAX_YEAR);
	
	
do{
        memset(buffer, '\0', BUFFER_SIZE);
		printf ("What is the Player's city?: ");
		scanf(" %[^\n]s", buffer);
	 }while(checkString(buffer, MAX_CITY_LEN) != 0);
	 first->playerCity = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
	 strcpy (first->playerCity, buffer);
	 memset(buffer, '\0', BUFFER_SIZE);
}

int main(){
 FILE* fullRoster;   
 int count = 0;
 int mainInput;
 char userInput = 'N';
 

playerNode* team = NULL;
   team = (playerNode*) malloc(sizeof(playerNode));
   if (team == NULL){
      return 1;
   }
   team->next = NULL;
    
do{
memset(buffer, '\0', BUFFER_SIZE);
printf("Would you like to load a previous roster? (Y - Yes or N - No): ");
  scanf("%s", buffer);
  if(buffer[0] == 'Y' || buffer[0] == 'N'){
      break;
printf("Invalid Input\n");
    }
}while(1);

   if(buffer[0] == 'Y'){
       fullRoster = fopen("roster.txt", "r");
        if(fullRoster == NULL){
         printf("Error Opening File");
         return -1;
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
      }
	  
      do{
       
  printf("\nWhat would you like to do?: 1 - Search player by name\t2 - Enter more players\t3 - End: ");
  scanf("%d", &mainInput);
  switch(mainInput){
      case Search:
      memset(buffer, '\0', BUFFER_SIZE);
      printf("Please enter a player's name: ");
      scanf("%s", buffer);
      printf("\n");
      searchPlayer(team, buffer);
      break;
      
      case Add:    
   do{
       if(count >= MAX_PLAYERS)
       break;
       
   newPlayer(team);
	 ++count;
	 
	 if(count >= MAX_PLAYERS)
       break;
	 
	 do{
	 memset(buffer, '\0', BUFFER_SIZE);
	 printf ("Would you like to continue user input? (%d of 10) (Y - Yes or N - No): ", count);
     scanf("%s", buffer);
     userInput = buffer[0];
     if(buffer[0] == 'Y' || buffer[0] == 'N')
     break;
	 }while(1);
    
     addPlayer(team);
     
    }while(userInput != 'N');
    break;
    
    case End: 
    printRoster(team);
         do{
         memset(buffer, '\0', BUFFER_SIZE);
         printf("Would you like to save this roster? (Y - Yes or N - No): ");
         scanf("%s", buffer);
         if(buffer[0] == 'Y' || buffer[0] == 'N')
         break;
         }while(1);
         
         if(buffer[0] == 'Y')
             memset(buffer, '\0', BUFFER_SIZE);
             fullRoster = fopen("roster.txt", "w");
             saveRoster(fullRoster, team, count);
             fclose(fullRoster);
        clearRoster(team);
        break;
        
    default:
        printf("Invalid input\n");
        scanf ("%*[^\n]");
  }
      }while(mainInput != 3);
}




     




     
     

    
	
 