//#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define up 72
#define down 80
#define left 75
#define right 77
#define enter 13
//#define end 79
//#define home 71
#define esc 27
int CheckWinner(int flagplayer ,int posy , int posx);
char sega[3][3] = {{'x','x','x'},{'.','.','.'},{'o','o','o'} } ;

int main()
{

	int i , j;
	char ch ;
	int posx = 0;
	int posy = 0;
	int flag = 0;
	int flagplayer = 0;
	int countplay = 0;
	int flagwin = 0;
	int flagexit = 0;
	do
	{
		clrscr();
		// player massege
		if(flagplayer == 0)
		{
			textattr(0x93);
			cprintf("\n player player one 'x'  " );
			textattr(0x07);
		}
		else if (flagplayer == 1)
		{
			textattr(0xA5);
			cprintf("\n player player two 'o'  " );
			textattr(0x07);
		}
		 // print sega
		 for(i=0 ; i<3 ;i++)
		 {
			for(j=0 ; j<3 ;j++)
			{
					gotoxy((j+7)*5,(i+4)*2);
					if(i== posy && j == posx)
					{
						textattr(0x84);
						cprintf("%c" , sega[i][j] );
						textattr(0x07);

					}
					else
					{
						printf("%c" , sega[i][j] );
					}
			}
			printf("\n" );
		  }


			ch = getch();
			switch(ch)
			{
				// play condition
				case enter :
					if(flagplayer == 0  )
					{

						if(flag == 0 &&  sega[posy][posx] == 'x'  )
						{
							sega[posy][posx] = '.' ;
							flag = 1;
							countplay++ ;
						}
						else if(flag == 1 && sega[posy][posx] == '.' )
						{
							sega[posy][posx] = 'x' ;
							if(countplay > 2)
							{
								flagwin = CheckWinner(flagplayer ,posy , posx);
							}

							if(flagwin == 1)
							{
								flagexit = 1 ;
							}
							else
							{
								flag = 0 ;
								flagplayer = 1;
							}
						}

					}
					else if ( flagplayer == 1)
					{

						if(flag == 0 &&  sega[posy][posx] == 'o'  )
						{
							sega[posy][posx] = '.' ;
							flag = 1;
						}
						else if( flag == 1 && sega[posy][posx] == '.' )
						{
							sega[posy][posx] = 'o' ;
							if(countplay > 2)
							{
								flagwin = CheckWinner(flagplayer ,posy, posx);
							}

							if(flagwin == 1)
							{
								flagexit = 1 ;
							}
							else
							{
								flag = 0 ;
								flagplayer = 0 ;
							}
						}
					}

				break;
				// directions
				case NULL :
					ch = getch();
					switch (ch)
					{
						
						case up :
							 posy -- ;
							 if( posy < 0 ) posy = 2;

						break;
						case down:
							 posy ++ ;
							 if( posy > 2 ) posy = 0;
							  
						break;
						case left :
							 posx -- ;
							 if( posx < 0 ) posx = 2;

						break;
						case right:
							 posx ++ ;
							 if( posx > 2 ) posx = 0;

						break;
					}

					break;
			}
		}while(ch != esc && flagexit != 1);

	 // print sega again due to loop end
		 for(i=0 ; i<3 ;i++)
		 {
			for(j=0 ; j<3 ;j++)
			{
					gotoxy((j+7)*5,(i+4)*2);
					if(i== posy && j == posx)
					{
						textattr(0x84);
						cprintf("%c" , sega[i][j] );
						textattr(0x07);

					}
					else
					{
						printf("%c" , sega[i][j] );
					}
			}
			printf("\n" );
		  }

	// print winner
	if(flagplayer == 0 && flagwin == 1 )
	 {
		textattr(0x93);
		cprintf(" player 1 winning ");
		textattr(0x07);
	 }
	 else if(flagplayer == 1 && flagwin == 1 )
	 {
		textattr(0xA5);
		cprintf(" player 2 winning ");
		textattr(0x07);
	 }

	 // clean up
	 getch();
	 return 0;
}


// chech win function
int CheckWinner(int flagplayer ,int posy , int posx)
{
	 int i;
	 int countrow = 0 ;
	 int countcolm = 0 ;
	 int countdig1 = 0 ;
	 int countdig2 = 0 ;

	 if(flagplayer == 0)
	 {
		  for(i = 0 ; i<3 ; i++)
		  {
				if(sega[posy][i] == 'x')
				{
					 countrow++ ;
				}
				if(sega[i][posx]== 'x')
				{
					countcolm++ ;
				}
				if(sega[i][i]== 'x')
				{
				   countdig1++ ;
				}
				if(sega[i][i]== 'x')
				{
				   countdig1++ ;
				}
				if(sega[2 - i][i]== 'x')
				{
				   countdig2++ ;
				}
		 }
	 }
	 else if( flagplayer == 1)
	 {
		  for(i = 0 ; i<3 ; i++)
		  {
				if(sega[posy][i]== 'o')
				{
					 countrow++ ;
				}
			    if(sega[i][posx]== 'o')
				{
					countcolm++ ;
				}
					if(sega[i][i]== 'o')
				{
				   countdig1++ ;
				}
				if(sega[2 - i][i]== 'o')
				{
				   countdig2++ ;
				}
		 }
	 }

	 if(countrow == 3 || countcolm == 3  || countdig1 == 3  ||countdig2 == 3 )
	 {
			return 1 ;
	 }
	 else
	 {
			return 0 ;
	 }
}