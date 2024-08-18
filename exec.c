#include "headers/exec.h"
#include "headers/config.h"
#include "headers/tools.h"
#include "headers/readCommands.h"

void execArgv(char** argv){
    if(strcmp(argv[0], "cd") != 0 && !checkBuiltInCommands(argv)){
        int pid = fork();

        if(pid == 0){
            int returnCode = execvp(argv[0], argv);

            if(returnCode < 0){
                perror("error");
            }
        }
        else{
            wait(0);
        }
    }
    else{
        smartChangeDir(argv);
    }
}
