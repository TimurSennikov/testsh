#include "headers/tools.h"
#include "headers/exec.h"
#include "headers/config.h"

char cmdLine[MAXBUF];
char userInput[MAXBUF];
char* argv[MAXBUF];

void cleanup(){
    for(int i = 0; i < sizeof(userInput); i++){
        userInput[i] = *"";
    }
}
int main(){
    while(1){
        cleanup();

        sprintf(cmdLine, "%s%s%s %s%s%s $ ", USERNAME_COLOR, getUsername(), ANSI_COLOR_RESET, DIRPATH_COLOR, getCurrentDir(), ANSI_COLOR_RESET);

        write(1, cmdLine, sizeof(cmdLine));

        fgets(userInput, MAXBUF, stdin);

        strcpy(*argv, splitUserInput(userInput));
    }
}