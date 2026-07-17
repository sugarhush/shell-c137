#ifndef SHELL_H
#define SHELL_H

#define INPUT_SIZE 100
#define FILE_PATH 1024
#define DELIMITER ":"

void repl();
void initialize();
void command_handling(char *);
char* search_for_executable(const char*);

#endif
