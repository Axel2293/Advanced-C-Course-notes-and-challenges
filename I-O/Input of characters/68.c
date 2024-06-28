#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    int ch = 0;
    
    // ch = getc(stdin);
    // printf("read in character %c\n", ch);

    // while ((ch = getchar()) != EOF)
    //     printf("%c", ch);
    
    //ungetc

    while (isspace(ch = (char) getchar()));
    ungetc(ch, stdin);
    
    printf("None space character %c", getchar());

    return 0;
}
