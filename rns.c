#include "node.h"
#include "rns.h"
#include "utility.h"

char stripComment(char* tempString){
    
    char *ptr;
    char *newLine = "\n";

    ptr = strchr(tempString, MARKER);
    if(ptr != NULL){
        *ptr = '\0';
    }
    if(strchr(tempString, '\n') == NULL)
    if(*tempString != '\0')
    strncat(tempString, newLine, 1);
    
    return *tempString;
}

void printString(char* stringValue, int index){
      switch(index){
    
          case 0: printf("Node ID: %s\n", stringValue); break;
          case 1: printf("Connection Count: %s", stringValue); break;
          case CYCLE_LIMIT: printf("Connection %d: %s", j, stringValue); j++; break;
      }
  }
  
unsigned int LoadNetwork(const char* fileName){
    return 0;
}

unsigned int ParseCmdLine(int argCount, char* argVal[], NetworkCmdLine* cmdLineOut){
    if(cmdLineOut == NULL){
        return ERR_CMD_LINE_MEMORY;
    }
    
    strcpy(cmdLineOut->fileName, CMD_LINE_DEF_FILENAME);
    
    int idx = 1;

        switch(argVal[idx][1]){
            
            case 'f':
                strcpy(cmdLineOut->fileName, argVal[idx + 1]);
                ++idx;
                break;
                
            case 'h': 
            default:
                return ERR_CMD_LINE; 
                break;
        }
  
    
    return ERR_OK;
}
  
int main (int argc, char* argv[]){
  
  char fileLine[BUFFER_SIZE];
  char *tempString;
  
  NetworkCmdLine params;
  unsigned int status = ParseCmdLine(argc, argv, &params);
  
  if(status != 0){
      
      getHelp(argv[0]);
      return status;
  }
  
  FILE *nodeInfo = fopen(params.fileName, "r");
  if(nodeInfo == NULL){
      printf("Error Reading File.");
      return errno;
  }
  
  _NODES *netConnection = malloc(NETWORK_SIZE * sizeof (*netConnection));

  while(!feof(nodeInfo)){
      tempString = fgets(fileLine, sizeof (fileLine), nodeInfo);
	  stripComment(tempString);
	  storeNodes(tempString, netConnection);
	 }
	 
	  clearNodes(netConnection);  
      fclose (nodeInfo);
      return 0;
}

void getHelp(char* pgmName){
    
    printf("Proper usage:\n\n");
    printf("%s -f {filename} -h\n", pgmName);
    
}