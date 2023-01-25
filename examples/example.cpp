#include "cs_481_hw_src/src.hpp"

int counter = 0;

void parent()
{
    counter -= 3;
    printf("Parent Counter %d\n", counter);
}

void child()
{
    counter *= 2;
    printf("Child Counter %d\n", counter);
}

void grandchild()
{
    counter += 7;
    printf("Grandchild Counter %d\n", counter);
}

int main(int argc, char* argv[])
{
    run_processes();
}
