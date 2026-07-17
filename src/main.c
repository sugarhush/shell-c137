#include "shell.c"


int main(int argc, char *argv[]) {
    initialize();
    repl(); //Read Eval Print Loop
    return 0;
}
