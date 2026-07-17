#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
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
        char next_command[INPUT_SIZE];
        strcpy(next_command, command+5);
        if (strcmp(next_command,"echo") == 0 || strcmp(next_command,"exit") == 0 || strcmp(next_command,"type") == 0) {
            printf("%s is a shell builtin\n", next_command);
        } else {
            if (search_for_executable(next_command) != NULL) {
                printf("%s is %s\n", next_command,search_for_executable(next_command));
            } else {
                printf("%s: not found\n", next_command);
            }
        }
    }
    else {
        printf("%s: command not found\n", command);
    }
}

char* search_for_executable(const char* filename) {
    char* path_env = getenv("PATH");
    if (!path_env) {
        return NULL;
    }

    char* path_copy = strdup(path_env);
    if (!path_copy) {
        return NULL;
    }

    char full_path[FILE_PATH];
    char* token = strtok(path_copy,DELIMITER);
    while (token != NULL) {
        snprintf(full_path, sizeof(full_path), "%s/%s", token, filename);
        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return strdup(full_path);
        }
        token = strtok(NULL,DELIMITER);
    }

    free(path_copy);
    return NULL;
}
