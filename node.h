#ifndef node
#define node

#define BUFFER_SIZE 1024
#define MARKER '#'
#define COMMA ","
#define NETWORK_SIZE 20
#define CYCLE_LIMIT 2
#define FILE_NAME_LIMIT 256
#define STRING_MARKER ", "

int i, k, j;

typedef struct _NETWORK_NODES _NODES;

    
typedef struct _NETWORK_NODES{
    char *_NODE_INFORMATION;
  }_NODES;
  

void clearNodes(_NODES *netConnection);
void storeNodes(char* tempString, _NODES* netConnection);

#endif