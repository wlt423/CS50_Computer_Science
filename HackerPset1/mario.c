/*
*   Builds two half pyramids to a
^   user specified height
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    int i, j, k;
    
    // Loop to enter non-negative integer 
    do                      
    {
        printf("Enter a non-negative integer less than 24:");
        height = GetInt();
    }
    while (height > 23 || height < 0);      
    
    // check that values are within the parameter 
    if (height == 0)               
        // check that value isn't zero
    {
        return 0;
        
    }
    else
    {
        // loop to print number of rows 
        for (i = 0; i < height; i++)       
        {
            
            // prints whitespace on each row
            for (j = 0; j < height - i - 1; j++)   
            {
                printf(" ");
            }
            
            // prints hashes on left of pyramid
            for (k = 0; k < 1 + i; k++)     
            {    
                printf("#");
            }
            
            // prints two spaces in middle of pyramid
            printf("  ");           
            
            // prints hashes on right of pyramid  
            for (k = 0; k < 1 + i; k++)     
            {    
                printf("#");
            }
            printf("\n");
        }
    }        
    return 0;
}

