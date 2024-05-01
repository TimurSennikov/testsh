char* getHostname();
char* getUsername();
char* getCurrentDir();
char** splitUserInput();
int checkBuiltInCommands(char** argv);
void smartChangeDir();
void readHistory();
void addToHistory(char* text);
void printCmdLine();