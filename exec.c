#include "headers/exec.h"
#include "headers/config.h"

void execArgv(char* argv[MAXBUF]){
    if(strcmp(argv[0], "cd") != 0){
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
        chdir(argv[0]);
    }
}