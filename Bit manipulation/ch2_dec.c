#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long to_bin(int);

int main(void)
{
    int decimal;
    printf("Enter decimal number: ");
    scanf("%lld", &decimal);

    printf("In decimal %d, in binary %lld\n", decimal, to_bin(decimal));
    
    return 0;
}


long long to_bin(int decimal){
    long long step=1, result=0;
    
    while (decimal!=0)
    {
        if(decimal & 1){
            result+= step;
        }
        step*=10;
        decimal>>=1;
    }

    return result;
}
