#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Create String varaible call name, and use get_string method to read keyboard input and store in name
    string name = get_string("What is your name?\n");
    //print " hello "name" "
    printf("hello, %s\n", name);
}