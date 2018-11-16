#include<stdio.h>
#include<conio.h>
#include<alloc.h>

int strlen(char* st);
char* strcpy(char* n1 , char* n2);

int main()
{
	char* wor1  ,  *wor2 ;
	char* pstr;

	clrscr();

	wor1 = (char*)malloc(10 * sizeof(char));
	wor2 = (char*)malloc(10 * sizeof(char));

	printf("enter the first word : ");
	flushall();
	gets(wor1);
	printf("\nthe lenght is %d ", strlen(wor1));



	pstr = strcpy(wor1 , wor2);
	printf("\nthe value of second string after copy is %s" , pstr);
	free (wor1);
	free (wor2);

	getch();
	return 0;
}
int strlen(char* wor)
{
	int i = 0;
	while(wor[i] != '\0')
		i++;

	return i;
}
char* strcpy(char* wor1 , char* wor2)
{
	int i = 0 ;

	while(wor1[i] != '\0')
	{
		wor2[i] = wor1[i];
		i++;
	}
	wor2[i] = '\0';
	return wor2;
}
