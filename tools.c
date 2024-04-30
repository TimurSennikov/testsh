#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "headers/tools.h"
#include "headers/config.h"
#include "headers/main.h"
#include "headers/readCommands.h"

int historyCount = 0;
char** historyDup[MAXBUF];

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

void addToHistory(char* text){
	if(strlen(text) < 2)
		return;
	char* path;
	sprintf(path, "/home/%s/.testsh.log", getUsername());
	FILE* file = fopen(path, "a");
	fprintf(file, "%s", text);
	fclose(file);
}

void smartChangeDir(char** argv){
	if(argv[1] == NULL){
		char dirName[MAXBUF];
		sprintf(dirName, "/home/%s", getUsername());
		chdir(dirName);
	}
	else{
		if(argv[1] != NULL && (strcmp(argv[1], "~") < 0 || strcmp(argv[1], "~") > 0) && (strncmp(argv[1], "~", 1) < 0 || strncmp(argv[1], "~", 1) > 0))
			chdir(argv[1]);
		else{
			if(strcmp(argv[1], "~") == 0 || strcmp(argv[1], "~/") == 0){
				char path[MAXBUF];
				sprintf(path, "/home/%s", getUsername());
				chdir(path);
			}
			else if(strncmp(argv[1], "~/", 2) == 0){
				char dirName[MAXBUF];
				argv[1] += 2;

				sprintf(dirName, "/home/%s/%s", getUsername(), argv[1]);

				chdir(dirName);
			}
		}
	}
}

void printCmdLine(){
	char cmdLine[MAXBUF] = "";
	sprintf(cmdLine, "%s%s%s %s%s%s $ ", USERNAME_COLOR, getUsername(), ANSI_COLOR_RESET, DIRPATH_COLOR, getCurrentDir(), ANSI_COLOR_RESET);
	write(1, cmdLine, sizeof(cmdLine));
}