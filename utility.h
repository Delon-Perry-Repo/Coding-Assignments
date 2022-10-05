#ifndef utility
#define utility

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define LEN_MAX_FILENAME 256
#define ERR_OK 0
#define ERR_CMD_LINE 1
#define ERR_LOAD_NET 2
#define ERR_CMD_LINE_MEMORY 3

#define CMD_LINE_DEF_FILENAME "default.grp"
#define NETWORK_FILE "basic.ntwk"

typedef struct _NCMD_LINE_PARAMS NetworkCmdLine;

typedef struct _NCMD_LINE_PARAMS{
    char fileName[FILE_NAME_LIMIT];
}NetworkCmdLine;

FILE* nodeInfo;
unsigned int ParseCmdLine(int argCount, char* argVal[], NetworkCmdLine* cmdLineOut);
unsigned int LoadNetwork(const char* fileName);
void getHelp(char* pgmName);

#endif
