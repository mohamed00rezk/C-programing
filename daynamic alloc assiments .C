#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>

struct emp
{
	 int id;
	 char name[10];
	 float salary;
	 float overtime;
	 float deduction;
};
#define up 72
#define down 80
#define enter 13
#define end 79
#define home 71
#define esc 27

   float sal;
   float ot;
   float ded;
   float res = 0;
   int x =0 ;
   struct emp* e1;
   int i ;

void getinf(int);
void prninf();
void prninfpar(int);
int main ()
{
	 int num;
	 char menu[4][10]  = { "new" , "display" ,"displayid","exit"} ;
	 int pos = 0;
	 int flag = 0;
	 int flagp = 0;
	 char ch;
	 char ch1;

	 clrscr();
	 do
	 {
		printf("enter your arr size: ");
		scanf("%d" ,&x );
	 }while( x < 1 );
	 e1 = (struct emp*) malloc(x * sizeof(struct emp));

	 for(i=0 ; i <x ;i++)
	 {
		 e1[i].id= -1 ;
	 }

	 do
	 {
		 clrscr();

		 for(i=0 ; i<4 ;i++)
		 {
			gotoxy(5,i+5);
			if(i==pos)
			{
				textattr(0x84);
				cprintf("%s",menu[i]);
				textattr(0x07);
			}
			else
			{
				 printf("%s",menu[i]);
			}
		  }
		  ch = getch();
		 // cases
			switch (ch)
			{
				case esc :
					 flag = 1 ;
				break;
				case enter :
					 clrscr();
					 switch (pos)
						{
							case 0 :
								 do
								 {
									 printf("\nenter a valid endex PLZ 1 to %d : ",x) ;
									 scanf("%d" , &num ) ;
								 }while( num > x || num < 1 );
								   getinf(num);
								   flagp = 1 ;
							break;
							case 1 :
								if( flagp == 0 )
								{
									printf("\nThere is no data PLz enter ur ARR ");
								}
								else if ( flagp == 1)
								{
									printf("\nthe exist info ");
									prninf();
								}
							break;
							case 2 :
							  if( flagp == 0 )
							  {
								printf("\nThere is no data PLz enter ur ARR ");
							  }
							  else if ( flagp == 1)
							  {
								 do
								 {
									 printf("\nenter a valid endex PLZ 1 to %d: ",x) ;
									 scanf("%d" , &num ) ;
								 }while( num > x || num < 1 );

								 prninfpar(num);
							   }
							break;
								case 3 :
								 flag = 1 ;
							break;
						}
                        getch();
				break;
		   // null cases
				case NULL :
			    ch = getch();
					switch (ch)
					{
						case home :
							 pos = 0;
						break;

						case end :
							 pos = 3;
						break;
						case up :
							 pos -- ;
							 if( pos < 0 ) pos = 3;
						break;
						case down:
							 pos ++ ;
							 if( pos > 3 ) pos = 0;
						break;
					}
					break;

	      	 }

   }while( flag == 0 );

   free(e1);
   return 0 ;
}

void getinf(int num)
{
  char ch1;
	 for(i=0 ; i <5 ; i++ )
	{

	  if (i ==  ( num - 1 ))
	  {
	   if(e1[i].id == -1 )
	   {
		printf("\nemp  num : %d " ,i+1 );

		printf("please enter  id : " );
			scanf( "%d" , &e1[i].id);

		printf("please enter  name : " );
			flushall() ;
			gets(e1[i].name);

		printf("please enter  salary : " );
			scanf( "%f" , &sal);
			e1[i].salary = sal;

		printf("please enter overtime : " );
			scanf( "%f" , &ot);
			e1[i].overtime = ot;

		printf("please enter deduction : " );
			scanf( "%f" , &ded);
			e1[i].deduction = ded;
		}
		else if(e1[i].id  > -1 )
		{
			textattr(0x84);
			cprintf("\nover write data \t y ! n : " );
			textattr(0x07);
			ch1 = getche();
			if(ch1 =='y' || ch1 == 'n' )
			{
				if(ch1 =='y' )
				{
				printf("emp  num : %d " ,i+1 );

				printf("please enter  id :" );
					scanf( "%d" , &e1[i].id);

				printf("please enter  name : " );
					flushall() ;
					gets(e1[i].name);

				printf("please enter  salary : " );
					scanf( "%f" , &sal);
					e1[i].salary = sal;

				printf("please enter overtime : " );
					scanf( "%f" , &ot);
					e1[i].overtime = ot;

				printf("please enter deduction : " );
					scanf( "%f" , &ded);
					e1[i].deduction = ded;

				}
				else if(ch1 == 'n' )
				{
				  break;
				}
			  }
			}
	}
  }
}

void prninf()
{

   for(i=0 ; i < x ; i++ )
   {
	if ( e1[i].id > -1 )
	{
	printf("\n %d %s %f %f %f " , e1[i].id ,e1[i].name ,e1[i].salary ,e1[i].overtime , e1[i].deduction);
	res = e1[i].salary + e1[i].overtime - e1[i].deduction ;
	printf("\n result : %f" , res );
	}
  }
}



void prninfpar(int num)
{
   int f = 0 ;

   while(f == 0)
   {
   for(i=0 ; i < x ; i++ )
   {
	  if (i ==  ( num - 1 ))
	  {
		if( e1[i].id == -1 )
		{
			textattr(0x84);
			cprintf("\nPLZ focus no emp ");
			textattr(0x07);
			do
			{
				printf("\nenter a valid index PLZ 1 to %d: ", x) ;
				scanf("%d" , &num ) ;
			} while( num > x || num < 1 );
		}
		else if( e1[i].id > -1  )
		{
			printf("\n %d %s %f %f %f " , e1[i].id ,e1[i].name ,e1[i].salary ,e1[i].overtime , e1[i].deduction);
			res = e1[i].salary + e1[i].overtime - e1[i].deduction ;
			printf("\n result : %f" , res );
			f = 1 ;
		}
	}
  }
  }
}
