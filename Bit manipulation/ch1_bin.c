#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int to_decimal(long long);

int main(int argc, char const *argv[])
{
    long long bin;
    printf("Enter binary (1 | 0): ");
    scanf("%lld", &bin);

    printf("In bin %lld, in decimal %d\n", bin, to_decimal(bin));
    return 0;
}

int to_decimal(long long bin){
    int decimalNumber = 0, i = 0, remainder;
    while (bin!=0)    {
        remainder = bin%10;
        bin /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
