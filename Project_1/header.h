#ifndef header
#define header

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define LEN_MAX_FILENAME 256
#define BUFFER_SIZE 1024
#define MARKER '#'
#define COMMA ","
#define NETWORK_SIZE 20
#define CYCLE_LIMIT 2
#define FILE_NAME_LIMIT 256
#define STRING_MARKER ", "

#define CMD_LINE_DEF_FILENAME "default.grp"
#define NETWORK_FILE "basic.ntwk"

enum _ERROR_CODES{
    ERR_OK = 0,
    ERR_CMD_LINE,
    ERR_LOAD_NET,
    ERR_CMD_LINE_MEMORY,
    ERR_EMPTY_NODE
};

int i, k, j;
typedef struct _NCMD_LINE_PARAMS NetworkCmdLine;
typedef struct _NETWORK_NODE_INFO _NODES;

typedef struct _NETWORK_NODE_INFO{
    char *_NODE_INFORMATION;
  }_NODES;
  

typedef struct _NCMD_LINE_PARAMS{
    char fileName[FILE_NAME_LIMIT];
}NetworkCmdLine;

FILE* nodeInfo;
unsigned int ParseCmdLine(int argCount, char* argVal[], NetworkCmdLine* cmdLineOut);
char stripComment(char* tempString);
unsigned int printNodes(char* stringValue, int index);
unsigned int getNetErrorString(int errorCode);
void clearNodes(_NODES *netConnection);
unsigned int storeNodes(char* tempString, _NODES* netConnection);
void getHelp(char* pgmName);

#endif
