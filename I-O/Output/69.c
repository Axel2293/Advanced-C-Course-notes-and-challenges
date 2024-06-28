#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ch = 0;
    while ((ch = getchar())!= EOF)
        putchar(ch); //Put the char in the stdout file
    return 0;
}
