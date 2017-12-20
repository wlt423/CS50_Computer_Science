#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
int length = 0;
int i = 0;
char initial='\0';
char initial1='\0';
string name = GetString();
length = strlen(name);
initial1=name[0];
printf("%c",toupper(initial1));
for(i=0; i<length; i++)
    {
    if (isspace(name[i]))
        {
        initial = toupper(name[i+1]);
        printf("%c", initial);
        }
    }
printf("\n");
}

