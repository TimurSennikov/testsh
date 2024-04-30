#include "headers/config.h"
#include "headers/exec.h"
#include "headers/tools.h"
#include "headers/readCommands.h"

int checkBuiltInCommands(char** argv){
	if(strcmp(argv[0], "history") == 0){
		readHistory();
		return 1;
	}
	return 0;
}

// history command.
void readHistory(){
    char path[MAXBUF];
    char formattedText[MAXBUF];

    sprintf(formattedText, "%s%s%s", WARNING_COLOR, "RUNNING BUILT-IN COMMAND!", ANSI_COLOR_RESET);

    printf("%s\n", formattedText);

    sprintf(path, "/home/%s/.testsh.log", getUsername());
    FILE* f = fopen(path, "r");

    char text[MAXBUF];

    int count = 0;
    while(fgets(text, MAXBUF, f)){
        text[strcspn(text, "\n")] = *"";
        printf("%d: %s\n", count, text);
        count++;
    }
}