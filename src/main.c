#include <stdio.h>
#include <string.h>

#define INPUT_SIZE 100

int main(int argc, char *argv[]) {
    // Flush after every printf
    setbuf(stdout, NULL);

    char command[INPUT_SIZE];
    printf("$ ");
    fgets(command, INPUT_SIZE, stdin);
    command[strlen(command)-1] = '\0';
    printf("%s: command not found", command);
    return 0;
}
