//linebox
//draws a box with a line around it

#include <conio.h>

void main(void)
	{
	int left = 10,top=5,width=20,height=7;
	int j;
	char string[81];		//utility string

	window(1,1,80,10);
	textbackground(BLUE);
	clrscr();
	textcolor(WHITE);
	gotoxy(0,0);
	cputs("big window");
	gotoxy(0,10);
	cprintf("%d",10000);
	window (left,top,left+width-1,top+height); //no -1 so no scroll
	textbackground(GREEN);
	clrscr();
	textcolor(RED);
	//do top line and corners
	for (j=1;j<width-1;j++)
		{string[j] = '\xCD';}
	string[width] = '\0';   //end of string
	string[0] = '\xC9';	//upper left corner
	string[width-1]='\xBB'; //upper right corner
	gotoxy(1,1);
	cputs(string);		//display top line
      //	for (j=1;j<width-1;j++)
      //		{string[j] = '\xB2';}

	string[0] = '\xC8';	//lower left corner
	string[width-1] = '\xBC';	//lower right corner
	gotoxy(1,height);
	cputs(string);		//display bottom line

	//vertical line from top to bottom
	for (j=2;j<height;j++)
		{
		gotoxy(1,j);
		putch('\xBA');
		gotoxy(width,j);

		putch('\xBA');
		}
	gotoxy(1,1);
	cputs("Hello");
	// second box
	left = 40;
	top=20;
	width=10;
	height=4;

	window (left,top,left+width-1,top+height); //no -1 so no scroll
	textbackground(LIGHTGRAY);
	clrscr();
	textcolor(BLACK);
	//do top line and corners
	for (j=1;j<width-1;j++)
		{string[j] = '\xCD';}
	string[width] = '\0';   //end of string
	string[0] = '\xC9';	//upper left corner
	string[width-1]='\xBB'; //upper right corner
	gotoxy(1,1);
	cputs(string);		//display top line
      //	for (j=1;j<width-1;j++)
      //		{string[j] = '\xB2';}

	string[0] = '\xC8';	//lower left corner
	string[width-1] = '\xBC';	//lower right corner
	gotoxy(1,height);
	cputs(string);		//display bottom line

	//vertical line from top to bottom
	for (j=2;j<height;j++)
		{
		gotoxy(1,j);
		putch('\xBA');
		gotoxy(width,j);
		putch('\xBA');
		}
	gotoxy(1,1);
	cputs("GoodBye");
	// extra stuff in boxes
	getch();
	left = 10;
	top=5;
	width=20;
	height=7;
	window (left,top,left+width-1,top+height);
	gotoxy(2,2);
	cputs("Works");

	left = 40;
	top=20;
	width=10;
	height=4;

	window (left,top,left+width-1,top+height);
	gotoxy(2,2);
	cputs("my oh my");
	}



