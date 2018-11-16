#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<alloc.h>

#define up 72
#define down 80
#define enter 13
#define end 79
#define home 71
#define esc 27

int main ()
{
	int x ;
	int** ptr;
	int row;
	int col;
	int i ;
	int j ;
	int flag = 0;
	int pos = 0 ;
	char ch ;

		 clrscr();

		printf("\nEnter row arr SIZE ");
		scanf("%d" ,&row ) ;
		ptr = (int**) malloc(row * sizeof(int));

		printf("\nenter colms SIZE ");
		scanf("%d" ,&col ) ;
		for( i=0 ; i< row ; i++ )
		{
			ptr[i] = (char*) malloc(col * sizeof(char));
		}

		printf("\nEnter your menu ");
		for( i=0 ; i< row ; i++ )
		{
				printf("\nMenu name%d : " ,i );
				flushall();
				gets(ptr[i]) ;
		}



		 do
	 {
		 clrscr();
	 // print menu
		 for(i=0 ; i<row ;i++)
		 {
			gotoxy(5,i+5);

			if(i==pos)
			{
				textattr(0x84);
				cprintf("%s",ptr[i]);
				textattr(0x07);
			}
			else
			{
				 printf("%s",ptr[i]);
			}
		  }
		  ch = getch();
		 // cases
			switch (ch)
			{
				case esc :
					 flag = 1 ;
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
							 pos = row - 1;
						break;
						case up :
							 pos -- ;
							 if( pos < 0 ) pos = row;
						break;
						case down:
							 pos ++ ;
							 if( pos > row ) pos = 0;
						break;
					}
					break;

	      	 }

   }while( flag == 0 );




	for( i=0 ; i< row ; i++ )
	{
	  free(ptr[i]);
	}
	free(ptr);
	getch();
	return 0;
}

