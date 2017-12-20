/*
*   Determines the equivalent number of bottles
*   for a given length shower
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int minutes = 0;
    int bottles = 0;
    
    // loops while until input is positive
    while (minutes <= 0)                                
    {
        // asks for shower length
        printf("Enter length of shower in minutes\n");  
        minutes = GetInt();
    }
    
    // calculates bottles used
    bottles = minutes * 12;                             
    
    // prints minutes and bottles used
    printf("minutes: %i\n", minutes);                   
    printf("bottles: %i\n", bottles);                   
}