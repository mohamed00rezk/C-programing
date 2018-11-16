#include<stdio.h>
#include<conio.h>
#include<alloc.h>

char* strcat(char* n1 , char* n2);
int strcmp(char* c1 , char* c2);
int main()
{
	char* wor1 , *wor2 , *pstr;

	clrscr();

	wor1 = (char*)malloc(20*sizeof(char));
	wor2 = (char*)malloc(10*sizeof(char));

	printf("enter the first string : ");
	flushall();
	gets(wor1);
	printf("enter the second string : ");
	flushall();
	gets(wor2);
	pstr = strcat(wor1 , wor2);
	printf("the concated string %s" , pstr);
	printf("\nthe result is %d" , strcmp(wor1 , wor2));
	free(wor1);
	free(wor2);
	getch();
	return 0;
}
char* strcat(char* wor1 , char* wor2)
{
	int i = 0 , j = 0 , k ;
	while(wor1[i] != '\0')
		i++;
	for(k=i ; k<20 ; k++)
	{
		while(wor2[j] != '\0')
		{
			wor1[i] = wor2[j];
			i++;
			j++;
		}
		wor1[i] = '\0';
	}
	return wor1;
}
int strcmp(char* wor1 , char* wor2)
{
	int i = 0;
	while(wor1[i] != '\0' && wor2[i] != '\0')
	{
		if(wor1[i] - wor2[i] > 0)
			return wor1[i] - wor2[i];
		else if(wor1[i] - wor2[i] < 0)
			return wor1[i] - wor2[i];
		else if(wor1[i] - wor2[i] == 0)
			i++;

	}
	return wor1[i-1] - wor2[i-1];
}