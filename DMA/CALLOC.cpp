#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n;
    int *element;

    printf("Enter total number of elements: ");
    scanf("%d", &n);

    element = (int*) calloc(n,sizeof(int)); //ekhane sudhu comma use hoi,,,where as malloc e * use hoi
                                                           //malloc r calloc er kaaj same

    if(element == NULL)
    {
        printf("Error.Not enough space available");
        exit(0);
    }

    for(i=0;i<n;i++)
       scanf("%d",element+i);

    for(i=1;i<n;i++)
    {
       if(*element > *(element+i))
           *element = *(element+i);
    }

    printf("Smallest element is %d",*element);

    return 0;
}
