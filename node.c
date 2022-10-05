#include "node.h"
#include "rns.h"
#include "utility.h"

 void storeNodes(char* tempString, _NODES* netConnection){
      char* token;
      
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
	      printString(netConnection[i]._NODE_INFORMATION, k);
	      token = strtok(NULL, ", ");
	      ++i;
	      if(k < CYCLE_LIMIT){
	          ++k;
	      }
	  }
  }
  
  void clearNodes(_NODES *netConnection){
      
    for(int index = 0; index <= i; ++index){
        free(netConnection[index]._NODE_INFORMATION);
    }
}