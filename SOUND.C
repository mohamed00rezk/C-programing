#include<stdio.h>
#include<conio.h>
#include<dos.h>

int main(void)
{
   clrscr();
   sound(440);
   delay(500);
   nosound();

   return 0;
}