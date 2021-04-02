//Checking Character, Digit or Special Symbol
#include <stdio.h>

int main()
{
  char ch;
  printf("Enter the character\n");
  scanf("%c",&ch);
  if(int(ch)>=65&&int(ch)<=90)
  {
    printf("Entered character is Upper Case");
  }
  else if(int(ch)>=97&&int(ch)<=122)
  {
    printf("The entered character is Lower Case");
  }
  else if(int(ch)>=48&&int(ch)<=57)
  {
    printf("Entered input is Digit");
  }
  else
  {
    printf("Entered input is Special Character");
  }
}
