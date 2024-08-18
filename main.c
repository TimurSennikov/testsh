#include "headers/tools.h"
#include "headers/exec.h"
#include "headers/config.h"

char userInput[MAXBUF];
char** argv;
char** history[MAXBUF];

void cleanup(){
    for(int i = 0; i < sizeof(userInput); i++){
        userInput[i] = *"";
    }
}
int main(){
    while(1){
        cleanup();
        printCmdLine();
        fgets(userInput, MAXBUF, stdin);

	if(strlen(userInput) == 0){printf("\n");exit(0);}

        //addToHistory(userInput);

        userInput[strcspn(userInput, "\n")] = '\0';

        argv = splitUserInput(userInput);

        if(strlen(userInput) > 0)
            execArgv(argv);
        else
            continue;
    }
}
