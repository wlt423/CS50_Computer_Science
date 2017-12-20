#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main(void)
{
float n=0;
int m=0, quarters=0, dimes=0,nickels=0, pennies=0, coins=0;
do 
{
printf("What is the change? ");
n = GetFloat();
}
while (n<0);
m=round(n*100);
quarters=m/25;
m=m-(quarters*25);
dimes=m/10;
m=m-(dimes*10);
nickels=m/5;
m=m-(nickels*5);
pennies=m;

coins=quarters+dimes+nickels+pennies;
printf("%d\n",coins);


}
