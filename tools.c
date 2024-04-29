#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "headers/tools.h"
#include "headers/config.h"
#include "headers/main.h"

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

void smartChangeDir(char** argv){
	if(argv[1] && (strcmp(argv[1], "~") < 0 || strcmp(argv[1], "~") > 0) && (strncmp(argv[1], "~", 1) < 0 || strncmp(argv[1], "~", 1) > 0))
		chdir(argv[1]);
	else{
		if(strcmp(argv[1], "~") == 0){
			// сидишаемся в домашнюю директорию.
		}
		else{
			// убираем из argv[1] ~, добавляем в начало получившейся строки адрес домашней директории и сидишаемся туда (щас не делаю потому что школа скоро).
		}
	}
}

void printCmdLine(){
	char cmdLine[MAXBUF] = "";
	sprintf(cmdLine, "%s%s%s %s%s%s $ ", USERNAME_COLOR, getUsername(), ANSI_COLOR_RESET, DIRPATH_COLOR, getCurrentDir(), ANSI_COLOR_RESET);
	write(1, cmdLine, sizeof(cmdLine));
}