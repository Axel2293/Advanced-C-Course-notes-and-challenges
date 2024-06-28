// Count the number of words and characters in a file OR from STDIN

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Define exit codes
#define EXIT_SUCCESS 0
#define EXIT_FILE_NOT_FOUND 1
#define EXIT_INVALID_ARGUMENT 2
#define EXIT_UNKNOWN_ERROR 3

void handle_err(int);
void count_file(void);
void count_stdin(void);


int main(int argc, char const *argv[])
{
    int selection = 0;

    printf("Would you like to count from terminal input or a file? (f / t)");
    selection = getchar(); getchar(); //Read option and discad '\n' character

    switch (selection)
    {
    case 'f':
        count_file();
        break;
    case 't':
        count_stdin();
        break;
    default:
        break;
    }

    return 0;
}

void count_file(void){
    printf("Input file path: ");
    char fpath_buff [1000]; int i=0, ch=0;

    while (((ch = getchar()) != '\n') 
            && ch != EOF 
            && i < 999) // Read STDIN till EOF or till end of string buff
    {
        fpath_buff[i++] = ch;
    }
    fpath_buff[999] = '\0';

    FILE *fp;

    if(fp = fopen((char*)fpath_buff, "r")){ //Open file with path stream
        int ch =0, c_char=0, c_words=0;
        while ((ch = fgetc(fp)) != EOF)
        {
            if(isalpha(ch))
                c_words++;
            else if(isgraph(ch))
                c_char++;
            else;
        } 

        printf("Word count: %d\n", c_words);
        printf("Character count %d\n", c_char);
        fclose(fp);                         //Close file
    }
    else
        handle_err(EXIT_FILE_NOT_FOUND);

}

void count_stdin(void){
    fprintf(stdout, "Enter text to count:");

    int ch =0, c_char=0, c_words=0;
    while ((ch = fgetc(stdin)) != '\n')
    {
        if(isalpha(ch))
            c_words++;
        else if(isgraph(ch))
            c_char++;
        else;
    } 

    printf("Word count: %d\n", c_words);
    printf("Character count %d\n", c_char);
}

void handle_err(int exit_code){
    switch (exit_code)
    {
    case EXIT_FILE_NOT_FOUND:
        fprintf(stderr, "Error: file not found\n");  
        break;
    default:
        fprintf(stderr, "Error: Unknown error\n");  
        break;
    }

    exit(exit_code);
}


