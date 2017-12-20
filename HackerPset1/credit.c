/*   checks the validity of a credit card number
*    and displays the type 
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{

    string cardtype;
    int digits = 0;
    long long number = 0;
    int checksum = 0;
    long long dig = 0;
    int product = 0;
    long long ans =0;

    // prompts for a credit card number
    printf("Enter a credit card number\n");                                     
    number = GetLongLong();
    
    // checks for an amex number
    if (number >= 340000000000000 && number < 380000000000000)                  
    {
        digits = 14;
        cardtype = "AMEX";
    }
    
    // checks for mastercard number 
    else if (number >= 5100000000000000 && number < 5600000000000000)           
    {
        digits = 15;
        cardtype = "MASTERCARD";
    }    
    
    // checks for 13 digit visa number
    else if (number >= 4000000000000 && number < 5000000000000)                 
    {
        digits = 12;
        cardtype = "VISA";
    }    
    
    // checks for 16 digit visa number 
    else if (number >= 4000000000000000 && number < 5000000000000000)           
    {
        digits = 15;
        cardtype = "VISA";
    }    
    
    // returns invalid if numbers are not properly formatted
    else 
    {
        cardtype = "INVALID";                                                   
    }

    /* turns each digit of card number into an array of individual
    *  digits the mod function and dividing by powers of 10
    */
    int eachnum[digits];
    int numdigits = digits;
    for (int j = 1; j <= numdigits; j++)
    {
        ans = pow(10, j);                                                       
        dig = number % ans;
        dig = dig / pow(10, dig - 1);       
        number = number - dig;
        eachnum[digits] = dig;
        digits = digits - 1;
    }
    
    
    
    
    // performs checksum on the array of digits 
    for (int i = numdigits - 1; i < 0; i = i - 2)  
    {
        product = eachnum[i] * 2;
        if (product >= 10)
        {
            product = 1 + product % 10;
            checksum = checksum + product;
        }    
    }
    product = 0;
    
    for (int i = numdigits; i < 0; i = i - 2)
    {
        product = eachnum[i] + product;
    }
    checksum = checksum + product;
    
    // valid card result prints cardtype
    if (checksum % 10 == 0)                                                     
    {
        printf("%s\n", cardtype);
    }
    
    // invalid card result prints INVALID
    else                                                                       
    {
        cardtype = "INVALID";
        printf("%s\n", cardtype);
    }
    return 0;
    
}
