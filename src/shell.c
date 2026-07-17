#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"

void initialize() {
    // Flush after every printf
    setbuf(stdout, NULL);
}

void repl() {
    char command[INPUT_SIZE];

    while (1) {
        printf("$ ");
        fgets(command, INPUT_SIZE, stdin);
        command[strlen(command)-1] = '\0';
        command_handling(command);
    }
}

void command_handling(char *command) {
    //Builting commands
    //exit
    if (strcmp(command,"exit") == 0) {
        exit(EXIT_SUCCESS);
    }
    //echo
    else if (strncmp(command,"echo ",5)==0) {
        printf("%s\n",command+5);
    }

    //type
    else if(strncmp(command,"type ",5)==0) {
        if (strcmp(command+5,"echo") == 0 || strcmp(command+5,"exit") == 0 || strcmp(command+5,"type") == 0) {
            printf("%s is a shell builtin\n", command+5);
        } else {
            printf("%s: not found\n", command+5);
        }
    }
    else {
        printf("%s: command not found\n", command);
    }
}
