#include "headers/config.h"
#include "headers/exec.h"
#include "headers/tools.h"
#include "headers/readCommands.h"

int checkBuiltInCommands(char** argv){
	if(strcmp(argv[0], "history") == 0){
		readHistory();
		return 1;
	}
    else if(strcmp(argv[0], "testshCredits") == 0){
        displayCredits();
        return 1;
    }
    else if(strcmp(argv[0], "help") == 0){
        displayHelp();
        return 1;
    }
    else if(strcmp(argv[0], "exit") == 0){
	exit(0);
    }
	return 0;
}

// help command.
void displayHelp(){
    char formattedText[MAXBUF];

    sprintf(formattedText, "%s%s%s\n", WARNING_COLOR, "RUNNING BUILT-IN COMMAND!", ANSI_COLOR_RESET);
    printf("%s\n", formattedText);

    printf("this is testsh version %d, built-in commands are located at github README.MD (%s).\n", VERSION, GITHUB_URL);
}

// testshCredits command.
void displayCredits(){
    char formattedText[MAXBUF];

    sprintf(formattedText, "%s%s%s\n", WARNING_COLOR, "RUNNING BUILT-IN COMMAND!", ANSI_COLOR_RESET);
    printf("Thanks to all who was following me during this shell`s develop!\n");
    printf("%sThanks to Roman Guridov for being ZIL refridgerator`s son!%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    printf("%sThanks to Yaroslav for calling me at 00:00 AM%s\n", ANSI_COLOR_BLUE, ANSI_COLOR_RESET);
    printf("%sThanks to Nikolay for suporting me!%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
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
