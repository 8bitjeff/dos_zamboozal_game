//savetext
//demonstrates saving and restoring the screen
#include <conio.h>
#define LEFT    1 		//define entire screen
#define TOP     1
#define RIGHT  80
#define BOT    25
int buff[80][25];		//buffer for screen contents

void main(void)
	{
	int x,y,j;

	getch();
	gettext(LEFT,TOP,RIGHT,BOT,buff); //save old screen
	x=wherex();			//save old cursor position
	y=wherey();
	clrscr();
	for (j=0;j<300;j++)      //fill screen with text
		{cputs("Wheat Software Presents");}
	getch();
	puttext(LEFT,TOP,RIGHT,BOT,buff); //restore old screen
	gotoxy(x,y-1);      //restore old cursor position
	getch();
	}

