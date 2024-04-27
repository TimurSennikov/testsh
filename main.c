#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXBUF 1024
#define SHELLNAME "testsh"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void onSIGINT();
void setup();
void clearData();
void setupCmdLine();
int child_branch();

bool running = true;

char userInput[MAXBUF] = "";

char currentDir[MAXBUF];

char cmdLine[MAXBUF];

char tmpChar[MAXBUF];

char* argv[MAXBUF];

char* token;

void onSIGINT(){
	running = false;
}

void setup(){
	signal(SIGINT, onSIGINT);
}

void clearData(){
	for(int i = 0; i < sizeof(cmdLine); i++){
		cmdLine[i] = *"";
	}
	for(int i = 0; i < sizeof(tmpChar); i++){
		tmpChar[i] = *"";
	}
	for(int i = 0; i < sizeof(userInput); i++){
		userInput[i] = *"";
	}
}

void setupCmdLine(char* shellNameColor, char* shellName, char* dirNameColor, char* dirName){
	sprintf(cmdLine, "%s%s%s %s%s%s $ ", shellNameColor, shellName, ANSI_COLOR_RESET, dirNameColor, dirName, ANSI_COLOR_RESET);
}

int main(){
	while(running){
		clearData();

		getcwd(currentDir, sizeof(currentDir));

		setupCmdLine(ANSI_COLOR_GREEN, SHELLNAME, ANSI_COLOR_BLUE, currentDir);

		write(1, cmdLine, sizeof(cmdLine));

		fgets(userInput, MAXBUF, stdin);

		userInput[strcspn(userInput, "\n")] = '\0';

		int count = 0;

		argv[count] = strtok(userInput, " ");

		while((argv[++count] = strtok(NULL, " ")) != NULL){}

		argv[++count] = 0;

		if(strcmp(argv[0], "cd") != 0 && !strlen(userInput) <= 1){
			int pid = fork();

			if(pid == 0)
				child_branch();
			else
				wait(0);
		}
		else if(!(strlen(userInput) <= 1)){
			chdir(argv[1]);
		}
	}
}

int child_branch(){
	int code = execvp(argv[0], argv);
	if(code < 0)
		perror("error");
	else
		return 0;
}
