#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long to_bin(int decimal);


int main(void)
{
    int dec, bit;
    unsigned int mask=1;
    printf("Enter decimal: ");
    scanf("%d", &dec);
    printf("On binary %lld\n", to_bin(dec));

    printf("Enter bit to check (0-31): ");
    scanf("%d", &bit);

    printf("Bit at %d is %d\n", bit, (dec>>bit)&1);

    dec= (1<<bit)|dec;
    printf("\nNew value is %d\n", dec);
    printf("On binary %lld\n", to_bin(dec));
    

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
