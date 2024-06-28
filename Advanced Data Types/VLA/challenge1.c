#include <stdio.h>
#include <stdlib.h>

int calculate_sum(size_t, int arr[]);


int main(int argc, char const *argv[])
{

    size_t size=0;

    printf("Enter array size: ");
    scanf("%ld", &size);

    int arr[size];

    for (size_t i = 0; i < size; i++)
    {
        printf("Enter value on index %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("\nResult of sum is: %d", calculate_sum(size, arr));
    
    return 0;
}

int calculate_sum(size_t size, int arr[size]){
    
    int result = 0;
    for (size_t i = 0; i < size; i++)
    {
        result+=arr[i];
    }
    return result;
    
}

