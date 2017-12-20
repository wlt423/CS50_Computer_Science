#include <stdio.h>
#include <cs50.h>

int main(void)
{
     int n=0;
     int i,j,k;
     do
     {
        printf("height?");
        n = GetInt();
     }
    while (n>23||n<0);
for (i=0;i<n;i++)
{
    for (k=0;k<n-i-1;k++)
        {
        printf(" ");
        }
    for (j=0;j<=1+i;j++)
    {    
        printf("#");
    }
printf("\n");
}
}




