#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
int result;
if (argc != 2)   //checks for 2 arguments
    {
    printf("error\n");
    return 1;
    
    }
int k = atoi(argv[1]); //check for negative key
    if (k<0)
        {
        printf("error\n");
        return 1;
        
        }
string text = GetString();    //input string
int len = strlen(text);

for(int i=0; i<len; i++)     //encipher
    {
        if isalpha(text[i])
            {               
                if isupper(text[i])
                        result = 65+((text[i]+k)%26);
                else if islower(text[i])
                        result = 97+((text[i]+k)%26);
                printf("%c",result);       
            }
        else 
            printf("%c", text[i]);      
    }
printf("\n");
return 0;
    
}
