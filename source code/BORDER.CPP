//draw border test
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void main(void)
	{


	int j; //looping variable
	int left = 64,top=2,width=12,height=20;
	char string[81]; /*utility string*/

	clrscr();
	textcolor(WHITE);

	for (j=1;j<width-1;j++)
		{string[j] = '\xCD';}
	string[width] = '\0';   //end of string
	string[0] = '\xC9';	//upper left corner
	string[width-1 ]='\xBB'; //upper right corner
	gotoxy(left,top);
	cputs(string);		//display top line

	string[0] = '\xC8';	//lower left corner
	string[width-1] = '\xBC';	//lower right corner
	gotoxy(left,height);
	cputs(string);		//display bottom line

	//vertical line from top to bottom
		for (j=top+1;j<height;j++)
		{
		gotoxy(left,j);
		putch('\xBA');
	       //	if (width !=80)        //compensate for side of screen
		 //	{gotoxy(width+1,j);}

	       //	else
		//	{gotoxy(width,j);}
		gotoxy(width+72,j);
		putch('\xBA');
		}


	}