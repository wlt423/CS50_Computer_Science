#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

string key = argv[1];
int result;
if (argc != 2)   //checks for 2 arguments
    {
    printf("error");
    return 1;
    }
int length = strlen(key);
for(int i=0; i<length; i++) //checks key for non alpha chars
    {
    if isalpha(key[i])
        ;
    else 
        {
        printf("error");
        return 1;
        }
    }

string text = GetString();    //input string
int len = strlen(text);
int j = 0;
for(int i=0; i<len; i++)     //encipher
    {
    
    if isalpha(text[i])
        {
         if (isupper(text[i]))
             {
             if (isupper(key[(j%length)]))
                {
                int k=(key[(j%length)]);
                result = ((text[i]-65+k-65)%26)+65;
                j++;
                }
             else if (islower(key[(j%length)]))
                {
                int k=(key[(j%length)]);
                result = ((text[i]-65+k-97)%26)+65;
                j++;
                }
             else
                {
                ;
                }
            
             }   
         else if (islower(text[i]))
             {
             if (isupper(key[(j%length)]))
                {
                int k=(key[(j%length)]);              
                result = ((text[i]-97+k-65)%26)+97;
                j++;
                }
             else if (islower(key[(j%length)]))
                {
                int k=(key[(j%length)]);
                result = ((text[i]-97+k-97)%26)+97;
                j++;
                }
             else
                {
                ;
                }
         
             } 
          else
             {
             ;
             }
       
          }
      else
        {
        result = text[i];
        }
      printf("%c",result);
      
      
      }  
printf("\n");             
return 0;  
    }
    
    
    
    
    
    
    
    
    
    
    
    
 
