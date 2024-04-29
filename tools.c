#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "headers/tools.h"
#include "headers/config.h"
#include "headers/main.h"

#define MAXBUF 1024

char* getUsername(){
	char* username = (char*)malloc(100*sizeof(char*));
	getlogin_r(username, 100*sizeof(char*));
	return username;
}

char* getCurrentDir(){
	char* currentDir = (char*)malloc(100*sizeof(char*));
	getcwd(currentDir, 100*sizeof(char*));
	return currentDir;
}

char** splitUserInput(char* userInput){
	char** argv = (char**)malloc(100*sizeof(char*));
	char* result;
	int count = 0;

	argv[count] = strtok(userInput, " ");
	while((argv[++count] = strtok(NULL, " ")) != NULL){}
	argv[++count] = "0";
	return argv;
}

void printCmdLine(){
	char cmdLine[MAXBUF] = "";
	sprintf(cmdLine, "%s%s%s %s%s%s $ ", USERNAME_COLOR, getUsername(), ANSI_COLOR_RESET, DIRPATH_COLOR, getCurrentDir(), ANSI_COLOR_RESET);
	write(1, cmdLine, sizeof(cmdLine));
}