#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery();

int main(int argc, char const *argv[])
{
    int i;
    for (;;)
    {
        i = setjmp(buf);
        if(i){
            error_recovery();
        }
        else{
            printf("Everithing is fine on main\n");
        }
    }
    
    
}

void error_recovery(){
    printf("Something bad happened, transfering control to main...\n");
    longjmp(buf, 1);
}

