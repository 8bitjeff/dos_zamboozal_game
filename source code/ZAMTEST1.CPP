// window.c
// test text - window functions
#include <conio.h>	// for window functions
#include <dos.h>        // for deleay()
#define LEFT  10
#define TOP    8
#define RIGHT 52
#define BOT   21
#define HEIGHT (BOT-TOP)

void main(void)
	{
	int j;
	window (LEFT,TOP,RIGHT,BOT);   		//define window
	textcolor(RED);				//set text color
	textbackground(GREEN);			//set text background
	for (j=0;j<100;j++)			//100 words
		{
		cputs("Greetings ");		//print word
		delay(100);			//slow down loop
		}
	 gotoxy(15,8);				//goto window center
	 textcolor(1);
	 cputs("The End");
	 gotoxy(1,HEIGHT);			//cursor to bottom
	 getch();				//wait for key press
	}