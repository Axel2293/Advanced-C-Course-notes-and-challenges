#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Line styles
#define SOLID   0
#define DOTTED  1
#define DASHED  2

// Primary colors Blue typicaly on the leftmost bit, green on center, red on right most bit
#define RED     1
#define GREEN   2
#define BLUE    4

#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)

void show_box_settings(packed_box);

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct packed_box{ // 2 bytes struct; 6 bits padding
    bool            transp          :1; // 1 bit
    unsigned short  fill_color      :3; // 3 bits
    unsigned short                  :4; //Padding 4 bits, 8 total / 1 byte
    bool            border          :1; //1 bit
    unsigned short  border_color    :3; //3 bits
    unsigned short  border_style    :2; //2 bits
    unsigned short                  :2; //2 bits padding, 8 total / 1 byte
};

typedef struct packed_box packed_box;


int main(void)
{
    printf("Size of struct %d\n", sizeof(packed_box));

    packed_box box = {true, WHITE, true, RED, DASHED};
    show_box_settings(box);


    return 0;
}

void show_box_settings(packed_box box){
    printf("Current box settings:\n");
    printf("\tTransparency: ");
    if (box.transp)
    {
        printf("transparent\n");
    }else{
        printf("opaque\n");
    }
    printf("\tFill color: %s\n", colors[box.fill_color]);
    
    printf("\tBorder: ");
    if (box.border)
    {
        printf("shown\n");
    }else{
        printf("not shown\n");
    }
    printf("\tBorder color: %s\n", colors[box.border_color]);

    printf("\tBorder style: ");
    switch (box.border_style)
    {
    case 0:
        printf("Solid \n");
        break;
    case 1:
        printf("Dotted \n");
        break;
    case 2:
        printf("Dashed \n");
        break;
    default:
        break;
    } 
}