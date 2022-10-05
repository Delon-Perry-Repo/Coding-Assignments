#include "header.h"
  
int main (int argc, char* argv[]){
  
  char fileLine[BUFFER_SIZE];
  char *tempString;
  int errorCode;
  
  NetworkCmdLine params;
  unsigned int status = ParseCmdLine(argc, argv, &params);
  
  if(status != 0){
      
      getNetErrorString(status);
      getHelp(argv[0]);
      return status;
  }
  
  FILE *nodeInfo = fopen(params.fileName, "r");
  if(nodeInfo == NULL){
      errorCode = 2;
      getNetErrorString(errorCode);
  }
  
  _NODES *netConnection = malloc(NETWORK_SIZE * sizeof (*netConnection));

  while(!feof(nodeInfo)){
      tempString = fgets(fileLine, sizeof (fileLine), nodeInfo);
	  stripComment(tempString);
	  errorCode = storeNodes(tempString, netConnection);
	  if(errorCode != 0){
	  getNetErrorString(errorCode);
	  return errorCode;
	  }
	 }
	 
	  clearNodes(netConnection);  
      fclose (nodeInfo);
      return 0;
} 

unsigned int getNetErrorString(int errorCode){
    switch(errorCode){
        
        case ERR_EMPTY_NODE: printf("Error: Node read as a NULL value.\n"); return errorCode; break;
        case ERR_CMD_LINE: printf("Error: Invalid command line argument.\n"); return errorCode; break;
        case ERR_LOAD_NET: printf("Error: Failed to load network file.\n"); return errorCode; break;
        case ERR_CMD_LINE_MEMORY: printf("Error: Command line argument contains no file name.\n"); return errorCode; break;
        
    }
}

char stripComment(char* tempString){ // Removes comments from .ntwk file
    
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

unsigned int printNodes(char* stringValue, int index){ // Prints node information
    if(stringValue == NULL){
        return ERR_EMPTY_NODE;
    }

      switch(index){
    
          case 0: printf("Node ID: %s\n", stringValue); break;
          case 1: printf("Connection Count: %s", stringValue); break;
          case CYCLE_LIMIT: printf("Connection %d: %s", j, stringValue); j++; break;
      }
      
      return ERR_OK;
  }
  
unsigned int ParseCmdLine(int argCount, char* argVal[], NetworkCmdLine* cmdLineOut){ //Parses command line argument
    if(argVal[2] == NULL){
        return ERR_CMD_LINE_MEMORY;
    }
    
    strcpy(cmdLineOut->fileName, CMD_LINE_DEF_FILENAME);
    
    int idx = 1;

        switch(argVal[idx][1]){
            
            case 'n':
                strcpy(cmdLineOut->fileName, argVal[idx + 1]);
                ++idx;
                break;
                
            default:
                return ERR_CMD_LINE; 
                break;
        }
  
    
    return ERR_OK;
}

void getHelp(char* pgmName){ // Prints proper command line arguement required
    
    printf("Proper usage:\n\n");
    printf("%s -n {filename}\n", pgmName);
    
}

 unsigned int storeNodes(char* tempString, _NODES* netConnection){ // Stores network information in dynamically allocated arrays
      char* token;
      int errorCode;
      
      if(tempString == NULL){
        return ERR_EMPTY_NODE;
    }
      
	  token = strtok(tempString, STRING_MARKER);
	  while(token != NULL){
	      if(*token == 'e'){
	      k = 0;
	      j = 0;
	      printf("\n");
	      break;
	      }
	      netConnection[i]._NODE_INFORMATION = (char*)malloc(strlen(token) * sizeof(char));
	      strcpy(netConnection[i]._NODE_INFORMATION, token);
	      errorCode = printNodes(netConnection[i]._NODE_INFORMATION, k);
	      if(errorCode != 0){
	      return errorCode;
	      }
	      token = strtok(NULL, ", ");
	      ++i;
	      if(k < CYCLE_LIMIT){
	          ++k;
	      }
	  }
	  
	  return 0;
  }
  
  void clearNodes(_NODES *netConnection){ // Clears arrays
      
    for(int index = 0; index <= i; ++index){
        free(netConnection[index]._NODE_INFORMATION);
    }
}