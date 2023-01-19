#include "src.hpp"

int counter = 0;

// Method that 'grandchild' process will call
void grandchild()
{
    counter += 7;
}

// Method that 'child' process will call
void child()
{
    counter *= 2;
}

// Method that 'parent' process will call
void parent()
{
    counter = 3;
}


// Fill in this method to complete Homework 1, Part 1
// Method is called by 'parent' process
void create_processes()
{

}
