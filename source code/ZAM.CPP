/*Zamboozal 5 dice*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

/*Macros*/
#define CLEAR_SCREEN clrscr()
#define TRUE 1
#define FALSE 0
#define RESET 0
#define L_ARROW 75
#define R_ARROW 77
#define U_ARROW 72
#define D_ARROW 80
#define ACROSS 205
#define UPDOWN 186
#define ESCAPE 27
#define MAIN_WINDOW  show_window(1,1,80,25,WHITE,BLUE)
#define SCORE_WINDOW show_window(3,4,61,10,WHITE,CYAN)
#define BACK 0
#define FRONT 1
#define NEW 0
#define LEAVE 1
#define FAST 1
#define SLOW 0
#define ACES 0
#define	DUCES  1
#define	THREES 2
#define	FOURS  3
#define	FIVES  4
#define	SIXES  5
#define	ONEPAIR 6
#define	TWOPAIR 7
#define	THREEOFAKIND 8
#define	FOUROFAKIND 9
#define	MICROSTRAIGHT 10
#define	SMALLSTRAIGHT 11
#define	LARGESTRAIGHT 12
#define	FULLHOUSE 13
#define	ZAMBOOZAL 14
#define	SECONDZAMBOOZAL 15
#define	BLACKJACK 16
#define	WAR 17
#define	ROULETTE 18
#define	GINRUMMY 19
#define	CHANCE 20
// ONLY IN SCORE STRUCT
#define	WILDPLAY_TOP 21
#define	WILDPLAY_BOTTOM 22
#define	BONUS 23
// ONLY IN CHOSEN STRUCT
#define WILDPLAY  21
#define STEP1 1
#define STEP2 2

/*declarations*/

/*Structures*/
struct dice {
	int side;
	int selected;
	int facing;
	};

struct control {
	char name[15];
	char wildplay[15];
	int turns_taken;
	int rolls_left;
	int turn_score;
	int juststarted;
	int re_roll;
	int re_rolled;
	int turn;
	int lastgamesc;
	int menu_4_back;
	};

struct highs{
	int upper;
	int lower;
	int bonus;
	int total;
	char wildplay[15];
	char name [11];
	char slogan[51];
	char date[9];
	int precent;
	int scores[24];
	};

struct totals{
	int upper_total;
	int lower_total;
	int total;
	};
struct score_tables{
	char name[30];
	int hpos;
	int vpos;
	};


struct menus{
	char name[50];
	char item[10][40];
	char direction[5][20];
	int nhpos;  // name hpos
	int ihpos[10]; //item hpos
	int dhpos[5];  //direction hpos
	int dirhpos;
	int directionyn;
	int items;
	int directions;
	int exityn;
	int left;
	int top;
	int right;
	int bottom;
	int backcolor;
	int titlecolor;
	int textcolor;
	int bordercolor;
	int selectedcolor;
	int dietotalyn;
	};

struct tboxes{
	char name[80];
	char item[10][80];
	int nhpos;  // name hpos
	int ihpos[10]; //item hpos
	int items;
	int left;
	int top;
	int right;
	int bottom;
	int backcolor;
	int titlecolor;
	int textcolor;
	int bordercolor;
	int selectedcolor;
	int rhpos; // return message hpos
	char returnmessage[80];

	};

struct scores{
	int itemscore[24];
	};

struct choices {
       int itemchosen[22];
	};


struct dice die[6];
struct choices chosen;
struct control game_control;
struct highs highscore[5];
struct highs hightemp;
struct highs highsave[5];
struct totals total_scores;
struct menus menu[20];
struct tboxes tbox[10];
struct score_tables sc[30];
struct scores score;

//global variables
int screen[80][25]; // for redrawing the screen


/*prototypes*/
int roll_1(void);
void sort_dice(void);
int check_acesthru6(int);
int check_onepair(void);
int check_twopair(void);
int check_3ofakind(void);
int check_4ofakind(void);
int check_microstraight(void);
int die_total(void);
int check_smallstraight(void);
int check_largestraight(void);
int check_fullhouse(void);
int check_zamboozal(void);
int check_2ndzamboozal(void);
int check_blackjack(void);
int check_war(void);
int check_roulette(void);
int check_ginrummy(void);
void initialize_dice(void);
int get_uppertotal(void);
int get_bonus(void);
int get_lowertotal(void);
int get_total(void);
void rewrite_screen(void);
void write_screen(void);
int start_newgame(void);
void get_character(void);
void show_window(int left,int top,int width,int height,int tc ,int bc);
void show_scores(void);
void draw_border(int left,int top,int right,int bottom, int color);
void draw_box(int left,int top,int right,int bottom, int color);
void draw_title(void);
void draw_line(int xpos,int ypos, int length, int color);
void display_totals(void);
void window_main(void);
void window_scores(void);
void window_totals(void);
void window_dice(int die,int type);
void write_score(int x,int y, char name[15],int score,int selected);
void draw_back(int die,int left,int top,int right,int bottom);
void draw_front(int dieside,int left,int top,int right,int bottom);
int show_menu(int);
void menu_setup(void);
int menu_start(void);
int menu_exit(void);
int menu_game_1(void);
char get_code(void);
int game_main(int gamenum);
int menu_case_start(void);
void show_all_5(void);
int menu_game_2(void);
int menu_game_3(void);
int menu_game_4(void);
int menu_ins_1(void);
int menu_ins_2(void);
int menu_ins_LAST(void);
void get_screen(void);
void put_screen(void);
void message_box(char m1[15],char m2[15],char m3[15],char m4[15]);
void show_help(void);
void write_help(int x,int y,char name[15],int score,int selected);
void select_dice(void);
int dice_menu(int place);
void text_box(int bn); // bn = box number
void setup_textboxes(void);
int roll_dice(void);
int select_item();
void fill_sc(void);
int menu_restart(void);
int menu_you_chose(char name[20]);
int menu_do_keep(void);
void do_wildplay(void);
void draw_plus(void);
void show_ins_1(void);
void show_ins_2(void);
void show_ins_3(void);
void show_ins_4(void);
void show_ins_5(void);
void show_ins_6(void);
void end_of_game_1(void);
void end_of_game_2(void);
void end_of_game_3(void);
void write_endscore(int x,int y, char name[15],int score);
void high_score_table(void);
int menu_highscore(void);
void new_highscore(void);
int hscinput_menu(void);
void read_hsfile(void);
void display_history(int choice);
void fire_works(void);
void title_screen(void);


void main(void)
	{
	/*declaration*/
	int gametype = NEW;  //NEW is 1
	int leave = FALSE;
	int gamenum =1;
	title_screen();

	while (leave == FALSE)
		{
			gametype=game_main(gamenum);
			switch (gametype)
			{
				case(NEW):{
					  start_newgame();
					  strcpy(game_control.wildplay,
					  "          ");
					  gamenum++;
					  read_hsfile();
					  break;
					  }

				case(LEAVE):{
						leave = TRUE;
						break;
					     }
			}

		}
	window_main();
	clrscr();
	_setcursortype(_NORMALCURSOR);
	exit(0);
	}

int game_main(int gamenum)

	{
	/*declaration*/
	int counter=0,bye=FALSE, menuexit=FALSE;
	int choice, goback,choice_start,choice_1,choice_2,choice_3, choice_4;
	int rolled = 0 , done= FALSE, rolls_left = 3;
	char m1[50], m2[50],m3[50],m4[50]; // message lines
	int tc,bc,bdc,rc, repeat;
	for (counter=0;counter<5;counter++)
		{die[counter].selected = FALSE;}
	CLEAR_SCREEN;
	menu_setup();
	setup_textboxes();
	fill_sc();  // fill score table
	game_control.turns_taken = 0;

	write_screen(); // for first time
	game_control.re_roll = FALSE;
	game_control.turn = FALSE;
	game_control.juststarted=TRUE;

	read_hsfile();
	while (game_control.turns_taken<21)
	{
		rewrite_screen();
		get_screen();
		menuexit = FALSE;
		done = FALSE;
		if (game_control.turns_taken == 0)
			{
			randomize();

			if (gamenum == 1)
				{
				choice_start = menu_case_start();


				if (choice_start==5)
					{return(LEAVE);}
				if (choice_start==1)
					{return(NEW);}

				}
			}

	game_control.rolls_left=3;
	while (game_control.rolls_left >=0)
	{


	switch (game_control.rolls_left)
		{
		case(3):
		{
		if (game_control.turns_taken>0)
			{
			rewrite_screen();
			get_screen();
			}
		menuexit = FALSE;
		done = FALSE;


		//game_menu_1 and roll
		put_screen();
		game_control.juststarted=FALSE;

		while (menuexit == FALSE)
			{
			choice_1 = menu_game_1();
			switch(choice_1)
				{
				case(1):{menuexit = TRUE;
					 break;
					}
				case(2):{/*see scores*/;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   PRESS");
					 strcpy(m2,"  ANY KEY");
					 strcpy(m3," TO GET BACK");
					 strcpy(m4," TO THE MENU");
					 message_box(m1,m2,m3,m4);
					 getch();
					 break;
					}
				case(3):{put_screen();
					choice_start = menu_case_start();
					if (choice_start == 5)
						{return(LEAVE);}
					if (choice_start==1)
					{return(NEW);}
					break;
					}
				}
			}


	     // FIRST ROLL ALL FIVE DICE
		put_screen();
		for (counter=0;counter < 5;counter++)
			{
			die[counter].selected=TRUE;
			}
		roll_dice();
		initialize_dice();
		sort_dice();
		// face all dice to the front
		die[0].facing=FRONT;
		die[1].facing=FRONT;
		die[2].facing=FRONT;
		die[3].facing=FRONT;
		die[4].facing=FRONT;
		break;
		} // end case(3)

		case(2):
		{
		// second game menu and roll

		put_screen();
		show_all_5();
		menuexit=FALSE;
		while (menuexit == FALSE)
			{
			choice_2 = menu_game_2();
			switch(choice_2)
				{
				case(1):{
					 menuexit = roll_dice();
					 break;
					}
				case(2):{/*select item*/;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   USE ALL 4");
					 strcpy(m2,"   ARROW KEYS");
					 strcpy(m3,"  AND [ENTER]");
					 strcpy(m4," TO SELECT ITEM");
					 message_box(m1,m2,m3,m4);
					 done = select_item();
					 if (done == TRUE)
						{menuexit = TRUE;}
					 break;
					}
				case(3):{/*select dice*/;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"<> ARROW KEYS");
					 strcpy(m2,"AND [SPACE]");
					 strcpy(m3,"TO SELECT DICE");
					 strcpy(m4,"  OR THIS BOX");
					 message_box(m1,m2,m3,m4);
					 select_dice();

					 break;
					}
				case(4):{/*get help */;
					 show_help();
					 put_screen();
					 show_all_5();

					 break;
					}
				case(5):{/*see scores */;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   PRESS");
					 strcpy(m2,"  ANY KEY");
					 strcpy(m3," TO GET BACK");
					 strcpy(m4," TO THE MENU");
					 message_box(m1,m2,m3,m4);
					 getch();
					 break;
					}
				case(6):{put_screen();
					 show_all_5();
					 choice_start = menu_case_start();
					 if (choice_start == 5)
						{return(LEAVE);}
					 if (choice_start==1)
						{return(NEW);}
					 break;
					}
				}
			}
		break;
		} // end case 2

		case(1):
		{
		  // third  game menu and roll uses game menu 3 again

		put_screen();
		sort_dice();
		show_all_5();
		menuexit=FALSE;
		if (done == TRUE)
			{menuexit = TRUE;}
		while (menuexit == FALSE)
			{
			choice_3 = menu_game_3();
			switch(choice_3)
				{
				case(1):{
					 menuexit = roll_dice();
					 break;
					 }
				case(2):{/*select item*/;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   USE ALL 4");
					 strcpy(m2,"   ARROW KEYS");
					 strcpy(m3,"  AND [ENTER]");
					 strcpy(m4," TO SELECT ITEM");
					 message_box(m1,m2,m3,m4);
					 done =
					 select_item();
					 if (done == TRUE)
						{menuexit = TRUE;}
					 break;
					}
				case(3):{/*select dice*/;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"<> ARROW KEYS");
					 strcpy(m2,"AND [SPACE]");
					 strcpy(m3,"TO SELECT DICE");
					 strcpy(m4,"  OR THIS BOX");
					 message_box(m1,m2,m3,m4);
					 select_dice();

					 break;
					}
				case(4):{/*get help */;
					 show_help();
					 put_screen();
					 show_all_5();
					 break;
					}
				case(5):{/*see scores */;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   PRESS");
					 strcpy(m2,"  ANY KEY");
					 strcpy(m3," TO GET BACK");
					 strcpy(m4," TO THE MENU");
					 message_box(m1,m2,m3,m4);
					 getch();
					  break;
					}
				case(6):{put_screen();
					 show_all_5();
					 choice_start = menu_case_start();
					if (choice_start == 5)
						{return(LEAVE);}
					if (choice_start==1)
						{return(NEW);}
					break;
					}
				}
			}
		break;
		} // end case 1

		case(0):
		{
		// fourth  game menu
		game_control.menu_4_back = TRUE;
		sort_dice();
		put_screen();
		show_all_5();
		menuexit=FALSE;
		if (done == TRUE)
			{menuexit=TRUE;}
		while (menuexit == FALSE)
			{
			choice_4 = menu_game_4();
			game_control.menu_4_back = FALSE;
			switch(choice_4)
				{
				case(1):{/*select item */
					 put_screen();
					 show_all_5();
					 strcpy(m1,"ARROW KEYS & ");
					 strcpy(m2,"  [ENTER] TO ");
					 strcpy(m3," SELECT ITEM ");
					 strcpy(m4," OR SEE MENU ");
					 message_box(m1,m2,m3,m4);
					 done =
					 select_item();
					 if (done == TRUE)
						{menuexit = TRUE;}
					 break;
					}
				case(2):{/*get help*/;
					 show_help();
					 put_screen();
					 show_all_5();

					 break;
					}
				case(3):{/*see scores */;
					 put_screen();
					 show_all_5();
					 strcpy(m1,"   PRESS");
					 strcpy(m2,"  ANY KEY");
					 strcpy(m3," TO GET BACK");
					 strcpy(m4," TO THE MENU");
					 message_box(m1,m2,m3,m4);
					 getch();
					 break;
					}
				case(4):{put_screen();
					 show_all_5();
					 choice_start = menu_case_start();
					if (choice_start == 5)
						{return(LEAVE);}
					if (choice_start==1)
						{return(NEW);}
					break;
					}
				}
			}
		break;
		} // end case 0
		} // end switch


	if ((game_control.re_roll==TRUE) &&
	    (game_control.re_rolled == FALSE))
		{
		done = FALSE;
		game_control.re_rolled = TRUE;
		}

	game_control.rolls_left--;

	} // while game_control
		put_screen();
		show_all_5();
	 game_control.turns_taken++;
      //	 game_control.turns_taken = 22; // for testing end of game
	} //end while

	end_of_game_1();
	high_score_table();
	return(0);
	}

int roll_1()
	{
	return (random(6)+1);
	}

void sort_dice(void)
	{
	int temp1, temp2,dicount,counter;
	for (counter = 0;counter < 4;counter++)
		{
		for (dicount=0;dicount < 4;dicount++)
			{
			if (die[dicount].side > die[dicount+1].side )
				{
				temp1 = die[dicount].side;
				temp2 = die[dicount+1].side;
				die[dicount].side = temp2;
				die[dicount+1].side = temp1;
				}
			  }
		}
	}


int die_total(void)
	{
	return (die[0].side + die[1].side + die[2].side + die[3].side
		 + die[4].side);
	}



void initialize_dice(void)
	{
	int counter;
	for (counter=0;counter <6;counter ++)
		{
		die[counter].selected = FALSE;
		}
	}

int check_acesthru6(int type)
	{
	int counter,score=0;
	for (counter = 0;counter <5;counter++)
		{
		if (die[counter].side==type)
		{score+=type;}
		}
	return (score);
	}
int check_onepair(void)
	{
	if (die[0].side == die[1].side)
		{return (10);}
	else if  (die[1].side == die[2].side)
		{return (10);}
	else if (die[2].side == die[3].side)
		{return (10);}
	else if (die[3].side == die[4].side)
		{return (10);}
	return (0);
	}

int check_twopair(void)
	{
	if (die[0].side == die[1].side)
		{
		if (die[2].side == die[3].side)
			{return(15);}
		if (die[3].side == die[4].side)
			{return(15);}
		}
	else if (die[1].side == die[2].side)
		{
		if (die[3].side == die[4].side)
			{return(15);}
		}
	return(0);

	}
int check_3ofakind(void)
	{
	if ((die[0].side == die[1].side) && (die[1].side==die[2].side))
		{return(die_total());}
	else if ((die[1].side == die[2].side) && (die[2].side==die[3].side))
		{return(die_total());}
	else if ((die[2].side == die[3].side) && (die[3].side==die[4].side))
		{return(die_total());}
	return(0);
	}

int check_4ofakind(void)
	{
	if ((die[0].side == die[1].side) && (die[1].side==die[2].side &&
	     die[2].side == die[3].side))
		{return(die_total());}
	else if ((die[1].side == die[2].side) && (die[2].side==die[3].side &&
		  die[3].side == die[4].side))
		{return(die_total());}

	return(0);
	}

int check_microstraight(void)
	{
	if ((die[1].side == die[0].side+1) && (die[2].side == die[1].side+1))
		{return(15);}
	else if ((die[2].side == die[1].side+1) &&
		(die[3].side == die[2].side+1))
		{return(15);}
	else if ((die[3].side == die[2].side+1) &&
		(die[4].side == die[3].side+1))
		{return(15);}
	else if ((die[1].side == die[0].side+1) &&
		(die[3].side == die[1].side+1))
		{return(15);}
	else if ((die[1].side == die[0].side+1) &&
		(die[4].side == die[1].side+1))
		{return(15);}
	else if ((die[2].side == die[1].side+1) &&
		(die[4].side == die[2].side+1))
		{return(15);}

	return(0);
	}


int check_smallstraight(void)
	{
	if ((die[1].side == die[0].side+1) &&
	   (die[2].side == die[1].side+1) &&
	   (die[3].side == die[2].side+1))
	   {return(25);}
	else if
	   ((die[2].side == die[1].side+1) &&
	   (die[3].side == die[2].side+1) &&
	   (die[4].side == die[3].side+1))
	   {return(25);}
	else if
	   ((die[1].side == die[0].side+1) &&
	   (die[2].side == die[1].side+1) &&
	   (die[4].side == die[2].side+1))
	   {return(25);}
	else if
	   ((die[1].side == die[0].side+1) &&
	   (die[2].side == die[0].side+1) &&
	   (die[4].side == die[3].side+1))
	   {return(25);}
	return(0);
	}

int check_largestraight(void)
	{
	if ((die[1].side == die[0].side+1) &&
	   (die[2].side == die[1].side+1) &&
	   (die[3].side == die[2].side+1) &&
	   (die[4].side == die[3].side+1))
	   {return(35);}

	return(0);
	}
int check_fullhouse(void)
	{
	if ((die[0].side == die[1].side) &&
	   (die[2].side == die[1].side)  &&
	   (die[3].side == die[4].side))
	   {return(35);}
	else if
	   ((die[0].side == die[1].side) &&
	   (die[2].side == die[3].side) &&
	   (die[3].side == die[4].side))
	   {return(35);}
       return (0);
       }

int check_zamboozal(void)
	{
	if (die[0].side == die[4].side)
	   {return(50+die_total());}
	return(0);
	}

int check_2ndzamboozal(void)
	{


	if ((chosen.itemchosen[14] == TRUE) &&
	    (die[0].side == die[4].side) &&
	    (score.itemscore[14] >0))
	   {return(75+die_total());}

	return(0);
	}

int check_blackjack(void)
	{
	int counter=0, house_dice[5], house_total=0, repeat;

	put_screen();
	show_all_5();
	for (counter=0;counter<5;counter++)
		{
		for (repeat=0;repeat<6;repeat++)
		{
		house_dice[counter] = roll_1();
		switch (counter)
			{
			case (0):
				{
				if (repeat ==0)
					{
					window(2,2,12,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[0],2,2,12,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (1):
				{
				if (repeat ==0)
					{
					window(14,2,24,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[1],14,2,24,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (2):
				{
				if (repeat ==0)
					{
					window(26,2,36,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[2],26,2,36,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (3):
				{

				if (repeat ==0)
					{
					window(38,2,48,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[3],38,2,48,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (4):
				{
				if (repeat==0)
					{
					window(50,2,60,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[4],50,2,60,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			}
			delay(100);
		} // for repeat

		} // for counter
	house_total = house_dice[0]+house_dice[1]+house_dice[2]+
		      house_dice[3]+house_dice[4];

	sprintf(tbox[1].item[0],"The dealer has %d",house_total);
	sprintf(tbox[1].item[1],"Your hand is %d",die_total());

	if (die_total() ==21)
	   {
	   sprintf(tbox[1].item[2],"You Got BLACK JACK!");
	   sprintf(tbox[1].item[3],"You WIN 35 Points");
	   text_box(1);
	   put_screen();
	   return(35);
	   }


	else if
	   (die_total() <=21)
	   {
	   if ((house_total < die_total()) || (house_total >21) &&
	      (die_total() <=21))
		{
		sprintf(tbox[1].item[2],"You Beat The Dealer!");
		sprintf(tbox[1].item[3],"You WIN 35 Points");
		text_box(1);
		put_screen();
		return(35);
		}
	   }
	if (house_total == die_total())
		{
		sprintf(tbox[1].item[2],"TIES go to the DEALER!");
		sprintf(tbox[1].item[3],"You get nothing!");
		text_box(1);
		put_screen();
		return(0);
		}
	sprintf(tbox[1].item[2],"The Dealer Beat You!");
	sprintf(tbox[1].item[3],"You get NOTHING!");
	text_box(1);
	put_screen();
	return(0);
	}

int check_war(void)
	{
	int house_dice[5], house_total=0, counter, repeat;
	int dietot, newplayer, newhouse;

	put_screen();
	show_all_5();
	for (counter=0;counter<5;counter++)
		{
		for (repeat=0;repeat<6;repeat++)
		{
		house_dice[counter] = roll_1();
		switch (counter)
			{
			case (0):
				{
				if (repeat ==0)
					{
					window(2,2,12,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[0],2,2,12,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (1):
				{
				if (repeat ==0)
					{
					window(14,2,24,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[1],14,2,24,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (2):
				{
				if (repeat ==0)
					{
					window(26,2,36,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[2],26,2,36,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (3):
				{

				if (repeat ==0)
					{
					window(38,2,48,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[3],38,2,48,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			case (4):
				{
				if (repeat==0)
					{
					window(50,2,60,8);
					textbackground(LIGHTGRAY);
					clrscr();
					}
				draw_front(house_dice[4],50,2,60,8);
				textbackground(BLACK);
				draw_border(1,1,11,7,RED);
				break;
				}
			}
			delay(100);
		} // for repeat

		} // for counter
	house_total = house_dice[0]+house_dice[1]+house_dice[2]+
		      house_dice[3]+house_dice[4];


       dietot=die_total();

	while (dietot==house_total)
		{
		//dietot=die_total();
		sprintf(tbox[2].item[0],"The dealer has %d",house_total);
		sprintf(tbox[2].item[1],"Your hand is %d",dietot);
		sprintf(tbox[2].item[2],"A TIE! Another Die");
		sprintf(tbox[2].item[3],"Will Be Rolled For Each");
		text_box(2);

		for (repeat=0;repeat<6;repeat++)
			{
			newhouse = roll_1();
			if (repeat ==0)
				{
				window(2,9,12,15);
				textbackground(LIGHTGRAY);
				clrscr();
				}
			draw_front(newhouse,2,9,12,15);
			textbackground(BLACK);
			draw_border(1,1,11,7,RED);
			delay(100);
			}

		 for (repeat=0;repeat<6;repeat++)
			{
			newplayer=roll_1();
			if (repeat==0)
				{
				window(50,9,60,15);
				textbackground(LIGHTGRAY);
				clrscr();
				}
			draw_front(newplayer,50,9,60,15);
			textbackground(BLACK);
			draw_border(1,1,11,7,WHITE);
			delay(100);
			} // for repeat
		house_total +=newhouse;
		dietot +=newplayer;



		}// for while

	if (die_total()>= house_total)
	   {
	   sprintf(tbox[2].item[0],"The dealer has %d",house_total);
	   sprintf(tbox[2].item[1],"Your hand is %d",dietot);
	   sprintf(tbox[2].item[2],"You Beat The Computer,");
	   sprintf(tbox[2].item[3],"All The Spoils to you!");
	   text_box(2);
	   put_screen();
	   return(35);
	   }
	sprintf(tbox[2].item[0],"The dealer has %d",house_total);
	sprintf(tbox[2].item[1],"Your hand is %d",dietot);
	sprintf(tbox[2].item[2],"The Computer Beat You,");
	sprintf(tbox[2].item[3],"Retreat For NO Points!");
	text_box(2);
	put_screen();
	return(0);
	}

int check_roulette(void)
	{
	int counter,score=0, house_roll, repeat, count=0;

	put_screen();
	show_all_5();

	for (repeat=0;repeat<6;repeat++)
			{
			house_roll = roll_1();
			if (repeat ==0)
				{
				window(10,8,20,14);
				textbackground(LIGHTGRAY);
				clrscr();
				}
			draw_front(house_roll,10,8,20,14);
			textbackground(BLACK);
			draw_border(1,1,11,7,RED);
			delay(100);
			}

	for (counter = 0;counter <5;counter++)
		{
		if (die[counter].side==house_roll)
			{
			score+=(house_roll*5);
			count++;
			}
		}
	sprintf(tbox[3].item[0],"The wheel landed on %d.",house_roll);
	sprintf(tbox[3].item[1],"You have %d of them.",count);
	if (count>1)
		{
		sprintf(tbox[3].item[2],
		"You get %d for each!",5*house_roll);
		}
	else if (count ==1)
		{
		sprintf(tbox[3].item[2],
		"You get %d for it!",5*house_roll);
		}
	else
		{
		sprintf(tbox[3].item[2],"SORRY!");
		}
	sprintf(tbox[3].item[3],"Your score is %d!",score);
	text_box(3);
	put_screen();
	return (score);
	}

int check_ginrummy(void)
	{
	if ((die[0].side == die[1].side) &&
	   (die[3].side == die[2].side+1) &&
	   (die[4].side == die[3].side+1))
	   {return(30);}

	else if
	   ((die[1].side == die[0].side+1) &&
	   (die[2].side == die[1].side+1) &&
	   (die[3].side == die[4].side))
	   {return(30);}

	else if ((die[0].side == die[1].side) &&
	   (die[2].side == die[1].side)  &&
	   (die[3].side == die[4].side))
	   {return(30);}
	else if
	   ((die[0].side == die[1].side) &&
	   (die[2].side == die[3].side) &&
	   (die[3].side == die[4].side))
	   {return(30);}
	return(0);
	}

int get_uppertotal(void)
	{return(score.itemscore[0]+score.itemscore[1]+score.itemscore[2]+
		 score.itemscore[3]+score.itemscore[4]+score.itemscore[5]+
		 +score.itemscore[21]);}

int get_bonus(void)
	{
	if (get_uppertotal() > 70)
		{return(40);}

	if (get_uppertotal() > 67)
		{return(35);}

	if (get_uppertotal() > 57)
		{return(30);}

	return(0);
	}
int get_lowertotal(void)
	{return(score.itemscore[6]+score.itemscore[7]+score.itemscore[8]+
		score.itemscore[9]+score.itemscore[10]+score.itemscore[11]+
		score.itemscore[12]+score.itemscore[13]+score.itemscore[14]+
		score.itemscore[15]+score.itemscore[16]+score.itemscore[17]+
		score.itemscore[18]+score.itemscore[19]+score.itemscore[20]+
		score.itemscore[22]);}

int get_total(void)
	 {return(get_uppertotal()+get_bonus()+get_lowertotal());}


void write_screen(void)
	{
	window_main();
	window_scores();
	show_scores();
	die[0].side=0;
	die[1].side=0;
	die[2].side=0;
	die[3].side=0;
	die[4].side=0;
	die[0].facing=BACK;
	die[1].facing=BACK;
	die[2].facing=BACK;
	die[3].facing=BACK;
	die[4].facing=BACK;
	window_dice(0,die[0].facing);
	window_dice(1,die[1].facing);
	window_dice(2,die[2].facing);
	window_dice(3,die[3].facing);
	window_dice(4,die[4].facing);

	window_totals();
	display_totals();
	return;
	}

void rewrite_screen(void)
	{
	window_scores();
	show_scores();
	die[0].side=0;
	die[1].side=0;
	die[2].side=0;
	die[3].side=0;
	die[4].side=0;
	die[0].facing=BACK;
	die[1].facing=BACK;
	die[2].facing=BACK;
	die[3].facing=BACK;
	die[4].facing=BACK;
	window_dice(0,die[0].facing);
	window_dice(1,die[1].facing);
	window_dice(2,die[2].facing);
	window_dice(3,die[3].facing);
	window_dice(4,die[4].facing);

	window_totals();
	display_totals();
	return;
	}

int start_newgame(void)
	{
	int counter;
	for (counter=0;counter<24;counter++)
		{
		score.itemscore[counter] = 0;
		}
	for (counter=0;counter<22;counter++)
		{
		chosen.itemchosen[counter] = FALSE;
		}

	return(0);
	}

void get_character(void)
	{
	int in_char;
	in_char = getc(stdin);
	printf("%c",in_char);
	return;
	}

void show_window(int left,int top,int width,int height,int tc,int bc)

	{

	window(left,top,left+width-1,top+height);
	textbackground(bc);
	clrscr();
	textcolor(tc);


	return;
	}

void draw_border(int left,int top,int right,int bottom, int color)

	{
	int j; //looping variable
	char c; // character to print


	textcolor(color);
	//top left corner
	gotoxy(left,top);
	c='\xC9';
	cprintf("%c",c);
	//top right corner
	gotoxy(right,top);
	c='\xBB';
	cprintf("%c",c);
	//lower left corner
	gotoxy(left,bottom);
	c='\xC8';
	cprintf("%c",c);
	//lower right corner
	gotoxy(right,bottom);
	c='\xBC';
	cprintf("%c",c);


	for (j=left+1;j<right;j++)
		{
		gotoxy(j,top);
		c='\xCD';
		cprintf("%c",c);
		gotoxy(j,bottom);
		cprintf("%c",c);
		}
	for (j=top+1;j<bottom;j++)
		{
		gotoxy(left,j);
		c='\xBA';
		cprintf("%c",c);
		gotoxy(right,j);
		cprintf("%c",c);
		}

	return;
	}
 void draw_box(int left,int top,int right,int bottom, int color)

	{
	int j; //looping variable
	char c; // character to print


	textcolor(color);
	//top left corner
	gotoxy(left,top);
	c='\xDA';
	cprintf("%c",c);
	//top right corner
	gotoxy(right,top);
	c='\xBF';
	cprintf("%c",c);
	//lower left corner
	gotoxy(left,bottom);
	c='\xC0';
	cprintf("%c",c);
	//lower right corner
	gotoxy(right,bottom);
	c='\xD9';
	cprintf("%c",c);


	for (j=left+1;j<right;j++)
		{
		gotoxy(j,top);
		c='\xC4';
		cprintf("%c",c);
		gotoxy(j,bottom);
		cprintf("%c",c);
		}
	for (j=top+1;j<bottom;j++)
		{
		gotoxy(left,j);
		c='\xB3';
		cprintf("%c",c);
		gotoxy(right,j);
		cprintf("%c",c);
		}

	return;
	}
void show_scores(void)
	{
	int ctr;
	textcolor(WHITE);
	gotoxy(3,1);
	cputs("<\xAEScore Items\xAF>");
	textcolor(MAGENTA);
	gotoxy(2,2);
	cprintf(" ** TOP SIX **");
	gotoxy(20,2);
	cprintf("  *** LOWER FIFTEEN ***");
	textcolor(BLUE);
	gotoxy(50,2);
	cprintf("TURNS LEFT:%d",(21-game_control.turns_taken));
	draw_box(2,3,16,12,BLACK);
	draw_box(17,3,62,12,BLACK);
	for (ctr = 0;ctr<21;ctr++)
		{
		write_score(sc[ctr].hpos,sc[ctr].vpos,sc[ctr].name,
			    score.itemscore[ctr],chosen.itemchosen[ctr]);
		}

	gotoxy(41,11);
	textcolor(RED);
	cprintf("W");
	textcolor(BLUE);
	cprintf("I");
	textcolor(BLACK);
	cprintf("L");
	textcolor(YELLOW);
	cprintf("D");
	textcolor(BLUE);
	cprintf("%s",game_control.wildplay);
	return;
	}

void draw_title(void)
	{
	gotoxy(25,2);
	textcolor(WHITE);
	cputs("Z");
	textcolor(GREEN);
	cputs("AM");
	textcolor(WHITE);
	cputs("B");
	textcolor(GREEN);
	cputs("OOZAL");
	textcolor(WHITE);
	cputs("    P");
	textcolor(GREEN);
	cputs("OKER");
	textcolor(WHITE);
	cputs("    D");
	textcolor(GREEN);
	cputs("ICE");

	return;
	}

void display_totals(void)
	{


	//print characters
	textcolor(YELLOW);
	gotoxy(4,2);
	cputs(" SCORES ");

	draw_line(2,3,14,YELLOW);

	textcolor(BLACK);
	gotoxy(2,4);
	cprintf("TOP 6    :");
	gotoxy(2,5);
	cprintf("BONUS:");

	draw_line(2,6,14,YELLOW);

	gotoxy(2,7);
	textcolor(BLACK);
	cprintf("TOP TOT  :");

	gotoxy(2,8);
	textcolor(BLACK);
	cprintf("LOWER 15 :");

	draw_line(2,9,14,YELLOW);

	gotoxy(2,10);
	textcolor(YELLOW);
	cprintf("TOTAL    :");

	draw_line(2,11,14,BLACK);

	textcolor(CYAN);
	gotoxy(2,12);
	cprintf("(c)1995 jdf");
	gotoxy(2,13);
	cprintf("  Wheat Sft");

		 //print integers
	textcolor(YELLOW);
	gotoxy(11,4);
	cprintf("%3d",get_uppertotal());
	gotoxy(11,5);
	cprintf("%3d",get_bonus());
	gotoxy(11,7);
	cprintf("%3d",(get_uppertotal() + get_bonus()));
	gotoxy(11,8);
	cprintf("%3d",get_lowertotal());
	textcolor(BLACK);
	gotoxy(11,10);
	cprintf("%3d",get_total());

	return;
	}

void draw_line(int xpos,int ypos, int length, int color)
	{
	int loop;
	char c;
	textcolor(color);
	for (loop=xpos;loop<length;loop++)
		{
		c='\xC4';
		gotoxy(loop,ypos);
		cprintf("%c",c);
		}
	return;
	}

void window_main(void)
	{
	 int row, column;
	 char c;
	 window(1,1,80,24);
	 textbackground(BLUE);
	 clrscr();
	 window(1,1,80,25);
	 textcolor(LIGHTGRAY);

	 for (row=16;row<25;row++)
		{

		for (column=1;column<81;column++)
			{
			gotoxy(column,row);
			cprintf("z");
			}
		}

	 //borders

	 draw_border(1,1,80,24,WHITE);	//main border



	//Zamboozal title
	draw_title();


	return;
	}
void window_scores(void)
	{
	window(2,3,64,15);
	textbackground(CYAN);
	clrscr();
	window(2,3,64,16);
	draw_border(1,1,63,13,WHITE); //score border
	textcolor(MAGENTA);
	return;
	}

void window_totals(void)
	{
	window(66,2,79,15);
	textbackground(RED);
	clrscr();
	window(66,2,79,16);
	draw_border(1,1,14,14,YELLOW);
	textcolor(RED);
	return;
	}

void window_dice(int dienum,int type)
	{
	int side;
	if (type ==0)
		{
		  switch (dienum)
			 {
		  case (0):
				{
				draw_back(1,2,17,12,23);
				break;
				}
		  case (1):
				{
				draw_back(2,14,17,24,23);
				break;
				}
		  case (2):
				{
				draw_back(3,26,17,36,23);
				break;
				}
		  case (3):
				{
				draw_back(4,38,17,48,23);
				break;
				}
		  case (4):
				{
				draw_back(5,50,17,60,23);
				break;
				}
		 }
		}
	if (type ==1)
		{
		  switch (dienum)
			 {
		  case (0):
				{
				draw_front(die[0].side,2,17,12,23);
				break;
				}
		  case (1):
				{
				draw_front(die[1].side,14,17,24,23);
				break;
				}
		  case (2):
				{
				draw_front(die[2].side,26,17,36,23);
				break;
				}
		  case (3):
				{
				draw_front(die[3].side,38,17,48,23);
				break;
				}
		  case (4):
				{
				draw_front(die[4].side,50,17,60,23);
				break;
				}
		 }
		}

	}

void write_score(int x,int y, char name[15],int score,int selected)
	{
	if (selected == TRUE)
	   {textcolor(RED);}
	else
	   {textcolor(WHITE);}
	gotoxy(x,y);
	cprintf("%s",name);
	textcolor(BLACK);
	if (x<17)
		{cprintf("%2d",score);}
	else
		{cprintf("%3d",score);}
	textcolor(WHITE);
	return;
	}

void draw_back(int dienum,int left,int top,int right,int bottom)
	{
	char c;
	int loop;
	window(left,top,right,bottom);
	textbackground(MAGENTA);
	clrscr();
	window(left,top,right,bottom+1);
	textbackground(BLACK);
	draw_border(1,1,11,7,WHITE);
	textbackground(MAGENTA);
	draw_box(2,2,10,5,LIGHTGRAY);
	textcolor(BLACK);
	c='\xCD';
	for (loop=3;loop<10;loop++)
		{
		gotoxy(loop,4);
		cprintf("%c",c);
		}

	textcolor(BLUE);
	gotoxy(4,3);
	cprintf("DIE ");
	textcolor(YELLOW);
	cprintf("%d",dienum);

	return;
	}

void draw_front(int dieside,int left,int top,int right,int bottom)
	{
	char c;
	window(left,top,right,bottom+1);
	textbackground(LIGHTGRAY);
	gotoxy(3,3);
	cputs("       ");
	gotoxy(3,4);
	cputs("       ");
	gotoxy(3,5);
	cputs("       ");
	draw_box(2,2,10,6,BLACK);

	switch (dieside)
			 {
		  case (1):
				{

				textcolor(BLACK);
				gotoxy(6,4);
				cprintf("o");
				break;
				}
		  case (2):
				{

				textcolor(RED);
				gotoxy(4,3);
				cprintf("o");
				gotoxy(8,5);
				cprintf("o");
				break;
				}
		  case (3):
				{

				textcolor(BLUE);
				gotoxy(4,3);
				cprintf("o");
				gotoxy(8,5);
				cprintf("o");
				gotoxy(6,4);
				cprintf("o");

				break;
				}
		  case (4):
				{

				textcolor(WHITE);
				gotoxy(4,3);
				cprintf("o");
				gotoxy(8,3);
				cprintf("o");
				gotoxy(4,5);
				cprintf("o");
				gotoxy(8,5);
				cprintf("o");
				break;
				}
		  case (5):
				{

				textcolor(MAGENTA);
				gotoxy(4,3);
				cprintf("o");
				gotoxy(8,3);
				cprintf("o");
				gotoxy(4,5);
				cprintf("o");
				gotoxy(8,5);
				cprintf("o");
				gotoxy(6,4);
				cprintf("o");
				break;
				}

		  case (6):
				{

				textcolor(GREEN);
				gotoxy(4,3);
				cprintf("o");
				gotoxy(4,4);
				cprintf("o");
				gotoxy(4,5);
				cprintf("o");
				gotoxy(8,3);
				cprintf("o");
				gotoxy(8,4);
				cprintf("o");
				gotoxy(8,5);
				cprintf("o");
				break;
				}
		 }

	 return;
	}

void menu_setup(void)
	{
	//start menu = menu[0];
	menu[0].items = 5;
	menu[0].directions = 3;
	menu[0].exityn = TRUE;
	menu[0].left= 63;
	menu[0].top = 10;
	menu[0].right =80;
	menu[0].bottom =24;
	strcpy(menu[0].name,"START MENU ");
	strcpy(menu[0].item[0],"START NEW GAME");
	strcpy(menu[0].item[1],"RETURN TO GAME");
	strcpy(menu[0].item[2],"HIGH SCORES");
	strcpy(menu[0].item[3],"INSTRUCTIONS");
	strcpy(menu[0].item[4],"EXIT TO DOS");
	strcpy(menu[0].direction[0],"USE ARROW KEYS");
	strcpy(menu[0].direction[1],"AND [RETURN]");
	strcpy(menu[0].direction[2],"TO SELECT.");
	menu[0].backcolor=BLACK;
	menu[0].titlecolor=WHITE;
	menu[0].textcolor=GREEN;
	menu[0].bordercolor=YELLOW;
	menu[0].selectedcolor=BLUE;
	menu[0].nhpos = 5;  // name hpos
	menu[0].dirhpos = 3; // direction hpos
	menu[0].ihpos[0] = 3;    //item hpos
	menu[0].ihpos[1] = 3;
	menu[0].ihpos[2] = 3;
	menu[0].ihpos[3] = 3;
	menu[0].ihpos[4] = 3;
	menu[0].dhpos[0] = 3;
	menu[0].dhpos[1] = 4;
	menu[0].dhpos[2] = 5;
	menu[0].directionyn = TRUE;


	//exit menu
	menu[1].items = 2;
	menu[1].directions = 2;
	menu[1].exityn = FALSE;
	menu[1].left= 27;
	menu[1].top = 5;
	menu[1].right =48;
	menu[1].bottom =15;
	strcpy(menu[1].name,"EXIT MENU");
	strcpy(menu[1].item[0],"NO");
	strcpy(menu[1].item[1],"YES!");
	strcpy(menu[1].direction[0],"ARE YOU CERTAIN");
	strcpy(menu[1].direction[1],"WANT TO EXIT?");
	menu[1].backcolor=BLACK;
	menu[1].titlecolor=YELLOW;
	menu[1].textcolor=GREEN;
	menu[1].bordercolor=RED;
	menu[1].selectedcolor=BLUE;
	menu[1].exityn = TRUE;
	menu[1].nhpos = 7;  // name hpos
	menu[1].dirhpos = 4; // direction hpos
	menu[1].ihpos[0] = 10;    //item hpos
	menu[1].ihpos[1] = 10;
	menu[1].dhpos[0] = 4;
	menu[1].dhpos[1] = 5;
	menu[1].directionyn = TRUE;

	//menu_game_1 = menu[2];
	menu[2].items = 3;
	menu[2].directions = 5;
	menu[2].exityn = FALSE;
	menu[2].left= 61;
	menu[2].top = 9;
	menu[2].right =80;
	menu[2].bottom =24;
	strcpy(menu[2].name,"GAME MENU");
	strcpy(menu[2].item[0],"ROLL DICE");
	strcpy(menu[2].item[1],"SEE SCORES");
	strcpy(menu[2].item[2],"GO TO START MENU");
	strcpy(menu[2].direction[0],"3 ROLLS LEFT");
	strcpy(menu[2].direction[1]," ");
	strcpy(menu[2].direction[2],"USE ARROW KEYS");
	strcpy(menu[2].direction[3],"AND [RETURN]");
	strcpy(menu[2].direction[4],"TO SELECT.");
	menu[2].backcolor=LIGHTGRAY;
	menu[2].titlecolor=BLACK;
	menu[2].textcolor=BLUE;
	menu[2].bordercolor=WHITE;
	menu[2].selectedcolor=GREEN;
	menu[2].nhpos = 6;  // name hpos
	menu[2].dirhpos = 4; // direction hpos
	menu[2].ihpos[0] = 3;    //item hpos
	menu[2].ihpos[1] = 3;
	menu[2].ihpos[2] = 3;
	menu[2].dhpos[0] = 4;
	menu[2].dhpos[1] = 4;
	menu[2].dhpos[2] = 4;
	menu[2].dhpos[3] = 5;
	menu[2].dhpos[4] = 6;
	menu[2].directionyn = TRUE;

	// game menu 2 menu[3];

	menu[3].items = 6;
	menu[3].directions = 5;
	menu[3].exityn = FALSE;
	menu[3].left= 61;
	menu[3].top = 7;
	menu[3].right =80;
	menu[3].bottom =24;
	strcpy(menu[3].name,"GAME MENU");
	strcpy(menu[3].item[0],"ROLL DICE");
	strcpy(menu[3].item[1],"SELECT ITEM");
	strcpy(menu[3].item[2],"CHOOSE DICE");
	strcpy(menu[3].item[3],"GET HELP");
	strcpy(menu[3].item[4],"SEE SCORES");
	strcpy(menu[3].item[5],"GO TO START MENU");
	strcpy(menu[3].direction[0],"2 ROLLS LEFT");
	strcpy(menu[3].direction[1]," ");  //left open for die total
	strcpy(menu[3].direction[2],"USE ARROW KEYS");
	strcpy(menu[3].direction[3],"AND [RETURN]");
	strcpy(menu[3].direction[4],"TO SELECT.");
	menu[3].backcolor=LIGHTGRAY;
	menu[3].titlecolor=BLACK;
	menu[3].textcolor=BLUE;
	menu[3].bordercolor=WHITE;
	menu[3].selectedcolor=GREEN;
	menu[3].nhpos = 6;  // name hpos
	menu[3].dirhpos = 4; // direction hpos
	menu[3].ihpos[0] = 3;    //item hpos
	menu[3].ihpos[1] = 3;
	menu[3].ihpos[2] = 3;
	menu[3].ihpos[3] = 3;
	menu[3].ihpos[4] = 3;
	menu[3].ihpos[5] = 3;
	menu[3].dhpos[0] = 4;
	menu[3].dhpos[1] = 4;
	menu[3].dhpos[2] = 4;
	menu[3].dhpos[3] = 5;
	menu[3].dhpos[4] = 6;
	menu[3].directionyn = TRUE;
	menu[3].dietotalyn = TRUE;
	// game menu 3 menu[4];

	menu[4].items = 6;
	menu[4].directions = 5;
	menu[4].exityn = FALSE;
	menu[4].left= 61;
	menu[4].top = 7;
	menu[4].right =80;
	menu[4].bottom =24;
	strcpy(menu[4].name,"GAME MENU");
	strcpy(menu[4].item[0],"ROLL DICE");
	strcpy(menu[4].item[1],"SELECT ITEM");
	strcpy(menu[4].item[2],"CHOOSE DICE");
	strcpy(menu[4].item[3],"GET HELP");
	strcpy(menu[4].item[4],"SEE SCORES");
	strcpy(menu[4].item[5],"GO TO START MENU");
	strcpy(menu[4].direction[0],"1 ROLL LEFT");
	strcpy(menu[4].direction[1]," "); // left open for die total
	strcpy(menu[4].direction[2],"USE ARROW KEYS");
	strcpy(menu[4].direction[3],"AND [RETURN]");
	strcpy(menu[4].direction[4],"TO SELECT.");
	menu[4].backcolor=LIGHTGRAY;
	menu[4].titlecolor=BLACK;
	menu[4].textcolor=BLUE;
	menu[4].bordercolor=WHITE;
	menu[4].selectedcolor=GREEN;
	menu[4].nhpos = 6;  // name hpos
	menu[4].dirhpos = 4; // direction hpos
	menu[4].ihpos[0] = 3;    //item hpos
	menu[4].ihpos[1] = 3;
	menu[4].ihpos[2] = 3;
	menu[4].ihpos[3] = 3;
	menu[4].ihpos[4] = 3;
	menu[4].ihpos[5] = 3;
	menu[4].dhpos[0] = 4;
	menu[4].dhpos[1] = 4;
	menu[4].dhpos[2] = 4;
	menu[4].dhpos[3] = 5;
	menu[4].dhpos[4] = 6;
	menu[4].directionyn = TRUE;
	menu[4].dietotalyn = TRUE;
	// game menu 4 menu[5];

	menu[5].items = 4;
	menu[5].directions = 5;
	menu[5].exityn = FALSE;
	menu[5].left= 61;
	menu[5].top = 9;
	menu[5].right =80;
	menu[5].bottom =24;
	strcpy(menu[5].name,"GAME MENU");
	strcpy(menu[5].item[0],"SELECT ITEM");
	strcpy(menu[5].item[1],"GET HELP");
	strcpy(menu[5].item[2],"SEE SCORES");
	strcpy(menu[5].item[3],"GO TO START MENU");
	strcpy(menu[5].direction[0],"NO ROLLS LEFT");
	strcpy(menu[5].direction[1]," ");// left open for die total
	strcpy(menu[5].direction[2],"USE ARROW KEYS");
	strcpy(menu[5].direction[3],"AND [RETURN]");
	strcpy(menu[5].direction[4],"TO SELECT.");
	menu[5].backcolor=LIGHTGRAY;
	menu[5].titlecolor=BLACK;
	menu[5].textcolor=BLUE;
	menu[5].bordercolor=WHITE;
	menu[5].selectedcolor=GREEN;
	menu[5].nhpos = 6;  // name hpos
	menu[5].dirhpos = 4; // direction hpos
	menu[5].ihpos[0] = 3;    //item hpos
	menu[5].ihpos[1] = 3;
	menu[5].ihpos[2] = 3;
	menu[5].ihpos[3] = 3;
	menu[5].dhpos[0] = 4;
	menu[5].dhpos[1] = 4;
	menu[5].dhpos[2] = 4;
	menu[5].dhpos[3] = 5;
	menu[5].dhpos[4] = 6;
	menu[5].directionyn = TRUE;
	menu[5].dietotalyn = TRUE;

	//start,are you sure menu
	menu[6].items = 2;
	menu[6].directions = 2;
	menu[6].exityn = FALSE;
	menu[6].left= 27;
	menu[6].top = 5;
	menu[6].right =50;
	menu[6].bottom =15;
	strcpy(menu[6].name,"RESTART YOUR GAME?");
	strcpy(menu[6].item[0],"NO WAY!");
	strcpy(menu[6].item[1],"OF COURSE");
	strcpy(menu[6].direction[0],"YOU ALREADY HAVE");
	strcpy(menu[6].direction[1],"A GAME IN PROGRESS");
	menu[6].backcolor=BLACK;
	menu[6].titlecolor=YELLOW;
	menu[6].textcolor=GREEN;
	menu[6].bordercolor=RED;
	menu[6].selectedcolor=BLUE;
	menu[6].exityn = TRUE;
	menu[6].nhpos = 4;  // name hpos
	menu[6].dirhpos = 4; // direction hpos
	menu[6].ihpos[0] = 8;    //item hpos
	menu[6].ihpos[1] = 8;
	menu[6].dhpos[0] = 4;
	menu[6].dhpos[1] = 4;
	menu[6].directionyn = TRUE;

	// you chose ...are you sure menu
	menu[7].items = 2;
	menu[7].directions = 1;
	menu[7].exityn = FALSE;
	menu[7].left= 25;
	menu[7].top = 5;
	menu[7].right =54;
	menu[7].bottom =15;
	strcpy(menu[7].item[0],"OF COURSE!");
	strcpy(menu[7].item[1],"NO WAY!");
	strcpy(menu[7].direction[0],"IS THIS YOUR CHOICE?");
	menu[7].backcolor=BLACK;
	menu[7].titlecolor=YELLOW;
	menu[7].textcolor=GREEN;
	menu[7].bordercolor=RED;
	menu[7].selectedcolor=BLUE;
	menu[7].exityn = TRUE;
	menu[7].nhpos = 4;  // name hpos
	menu[7].dirhpos = 7; // direction hpos
	menu[7].ihpos[0] = 11;    //item hpos
	menu[7].ihpos[1] = 11;
	menu[7].dhpos[0] = 5;
	menu[7].dhpos[1] = 4;
	menu[7].directionyn = TRUE;

	//you will get 0 points
	menu[8].items = 2;
	menu[8].directions = 2;
	menu[8].exityn = FALSE;
	menu[8].left= 25;
	menu[8].top = 5;
	menu[8].right =58;
	menu[8].bottom =15;
	strcpy(menu[8].name,"YOU WILL GET 0 POINTS!");
	strcpy(menu[8].item[0],"NO WAY!");
	strcpy(menu[8].item[1],"OF COURSE");
	strcpy(menu[8].direction[0],"ARE YOU SURE YOU");
	strcpy(menu[8].direction[1],"REALLY WANT TO DO THIS");
	menu[8].backcolor=LIGHTGRAY;
	menu[8].titlecolor=BLACK;
	menu[8].textcolor=GREEN;
	menu[8].bordercolor=WHITE;
	menu[8].selectedcolor=BLUE;
	menu[8].exityn = TRUE;
	menu[8].nhpos = 7;  // name hpos
	menu[8].dirhpos = 10; // direction hpos
	menu[8].ihpos[0] = 13;    //item hpos
	menu[8].ihpos[1] = 13;
	menu[8].dhpos[0] = 9;
	menu[8].dhpos[1] = 7;
	menu[8].directionyn = TRUE;

	// menu 9 is instruction page 1 menu
	menu[9].items = 2;
	menu[9].directions = 0;
	menu[9].left= 27;
	menu[9].top = 19;
	menu[9].right =55;
	menu[9].bottom =25;
	strcpy(menu[9].name,"CONTINUE INSTRUCTIONS?");
	strcpy(menu[9].item[0],"NEXT PAGE");
	strcpy(menu[9].item[1],"START MENU");
	menu[9].backcolor=GREEN;
	menu[9].titlecolor=WHITE;
	menu[9].textcolor=YELLOW;
	menu[9].bordercolor=WHITE;
	menu[9].selectedcolor=BLUE;
	menu[9].exityn = FALSE;
	menu[9].nhpos = 4;  // name hpos
	menu[9].dirhpos = 4; // direction hpos
	menu[9].ihpos[0] =11;    //item hpos
	menu[9].ihpos[1] =11;
	menu[9].directionyn = FALSE;

		// menu 10 is instruction page 1 menu
	menu[10].items = 3;
	menu[10].directions = 0;
	menu[10].left= 27;
	menu[10].top = 18;
	menu[10].right =55;
	menu[10].bottom =25;
	strcpy(menu[10].name,"INSTRUCTIONS");
	strcpy(menu[10].item[0],"NEXT PAGE");
	strcpy(menu[10].item[1],"PREVIOUS PAGE");
	strcpy(menu[10].item[2],"START MENU");
	menu[10].backcolor=GREEN;
	menu[10].titlecolor=WHITE;
	menu[10].textcolor=YELLOW;
	menu[10].bordercolor=WHITE;
	menu[10].selectedcolor=BLUE;
	menu[10].exityn = FALSE;
	menu[10].nhpos = 9;  // name hpos
	menu[10].dirhpos = 4; // direction hpos
	menu[10].ihpos[0] =9;    //item hpos
	menu[10].ihpos[1] =9;
	menu[10].ihpos[2] =9;
	menu[10].directionyn = FALSE;

		// menu 11 is highscore menu
	menu[11].items = 6;
	menu[11].directions = 0;
	menu[11].left= 28;
	menu[11].top = 14;
	menu[11].right =53;
	menu[11].bottom =24;
	strcpy(menu[11].name,"Examine A High Score?");
	strcpy(menu[11].item[0],"THE KING");
	strcpy(menu[11].item[1],"HIGH SCORE 2");
	strcpy(menu[11].item[2],"HIGH SCORE 3");
	strcpy(menu[11].item[3],"HIGH SCORE 4");
	strcpy(menu[11].item[4],"HIGH SCORE 5");
	strcpy(menu[11].item[5],"NO!,Back to Zamboozal");
	menu[11].backcolor=GREEN;
	menu[11].titlecolor=WHITE;
	menu[11].textcolor=YELLOW;
	menu[11].bordercolor=BLACK;
	menu[11].selectedcolor=BLUE;
	menu[11].exityn = TRUE;
	menu[11].nhpos = 4;  // name hpos
	menu[11].dirhpos = 0; // direction hpos
	menu[11].ihpos[0] =4;    //item hpos
	menu[11].ihpos[1] =4;
	menu[11].ihpos[2] =4;
	menu[11].ihpos[3] =4;
	menu[11].ihpos[4] =4;
	menu[11].ihpos[5] =4;
	menu[11].directionyn = FALSE;

	// menu 12 is highscore input menu
	menu[12].items = 2;
	menu[12].directions = 0;
	menu[12].left= 28;
	menu[12].top = 12;
	menu[12].right =53;
	menu[12].bottom =18;
	strcpy(menu[12].name,"Re-enter Data?");
	strcpy(menu[12].item[0],"YES");
	strcpy(menu[12].item[1],"NO");
	menu[12].backcolor=BLUE;
	menu[12].titlecolor=WHITE;
	menu[12].textcolor=YELLOW;
	menu[12].bordercolor=LIGHTGRAY;
	menu[12].selectedcolor=GREEN;
	menu[12].exityn = TRUE;
	menu[12].nhpos = 7;  // name hpos
	menu[12].dirhpos = 0; // direction hpos
	menu[12].ihpos[0] =12;    //item hpos
	menu[12].ihpos[1] =12;
	menu[12].directionyn = FALSE;

	}


int show_menu(int mnum)
	{
	int counter, items = menu[mnum].items;
	int vpos =4;
	int right = menu[mnum].right,left = menu[mnum].left;
	int top = menu[mnum].top, bottom = menu[mnum].bottom;
	window(left,top,right,bottom-1);
	textbackground(menu[mnum].backcolor);
	clrscr();
	window(left,top,right,bottom);
	draw_border(1,1,(right-left)+1,(bottom-top),menu[mnum].bordercolor);
	textcolor(menu[mnum].titlecolor);
	//center and write name title

	gotoxy(menu[mnum].nhpos,2);
	cputs(menu[mnum].name);

	draw_line(2,3,(right-left)+1,menu[mnum].bordercolor);
	textcolor(menu[mnum].textcolor);
	textbackground(menu[mnum].backcolor);
	if (menu[mnum].directionyn == TRUE)
		{
		draw_line(2,items+5,(right-left)+1,menu[mnum].bordercolor);
		}
	//center and write directions
	if (menu[mnum].directionyn == TRUE)
	{
		gotoxy(menu[mnum].dirhpos,items+5);
		textcolor(menu[mnum].bordercolor);
		cputs("INFO/DIRECTIONS");


		for (counter=0;counter<menu[mnum].directions;counter++)
			{
			textcolor(menu[mnum].titlecolor);
			gotoxy(menu[mnum].dhpos[counter],items+counter+6);
			cputs(menu[mnum].direction[counter]);
			}
		if (menu[mnum].dietotalyn==TRUE)
			{
			gotoxy(menu[mnum].dhpos[0],items+7);
			textcolor(YELLOW);
			cprintf("DIE TOTAL: ");
			gotoxy(menu[mnum].dhpos[0]+11,items+7);
			textcolor(RED);
			cprintf("%d",die_total());
			}
	}
	while (TRUE)
		{
			for (counter=0;counter<items;counter++)
			{
			textbackground(menu[mnum].backcolor);
			textcolor(menu[mnum].textcolor);
			if (counter ==vpos-4)
				{textbackground(menu[mnum].selectedcolor);}
			if ((menu[mnum].exityn == TRUE) &&
			(counter == items-1))
				{textcolor(RED);}

			//center and write item

			gotoxy(menu[mnum].ihpos[counter],4+counter);
			cputs(menu[mnum].item[counter]);
			}

		switch ( get_code() )
			{
			case U_ARROW:
				{
				vpos = (vpos >4) ? --vpos: items+3;
				break;
				}
			case D_ARROW:
				{
				vpos = (vpos<items+3) ? ++vpos: 4;

				break;
				}
			case '\r':
				{
				return(vpos);

				}
			case ' ':
				{
				return(vpos);
				}
			}

		}

	}

int menu_start(void)
	{
	int vpos,choice;
	_setcursortype(_NOCURSOR);

	vpos = show_menu(0);
	return(vpos -3);

	}

int menu_exit(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(1);
	switch (vpos)
		{
		case(4): {
			  choice = FALSE;
			  break;
			 }

		case(5): {
			  choice = TRUE;
			  break;
			 }

		}
	 return(choice);

	}
int menu_highscore(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(11);
	return(vpos - 3);

	}
int hscinput_menu(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(12);
	return(vpos - 3);

	}



int menu_ins_1(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(9);
	return(vpos - 3);
	}

int menu_ins_2(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(10);
	return(vpos - 3);

	}



int menu_restart(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);

	vpos = show_menu(6);
	switch (vpos)
		{
		case(4): {
			  choice = FALSE;
			  break;
			 }

		case(5): {
			  choice = TRUE;
			  break;
			 }

		}
	 return(choice);
	 }

int menu_you_chose(char name[20])
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	sprintf(menu[7].name,"You Chose %s.",name);
	vpos = show_menu(7);
	switch (vpos)
		{
		case(4): {
			  choice = TRUE;
			  break;
			 }

		case(5): {
			  choice = FALSE;
			  break;
			 }

		}
	 return(choice);
	 }

int menu_do_keep(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(8);
	switch (vpos)
		{
		case(4): {
			  choice = FALSE;
			  break;
			 }

		case(5): {
			  choice = TRUE;
			  break;
			 }

		}
	 return(choice);
	 }

int menu_game_1(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(2);
	return(vpos-3);
	}

int menu_game_2(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(3);
	return(vpos - 3);
	}

int menu_game_3(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	vpos = show_menu(4);
	return(vpos -3);
	}



int menu_game_4(void)
	{
	int vpos, choice;
	_setcursortype(_NOCURSOR);
	if (game_control.menu_4_back==TRUE)
	    {return(1);}
	vpos = show_menu(5);
	return(vpos - 3);
	}



char get_code(void)
	{
	char key;
	if ( (key=getch()) == 0)
		return(getch() );
	else if (key == '\r')
		return(key);
	else if (key == ' ')
		return(key);
	else
		return(0);
	}


menu_case_start()
	{
	int choice, menuexit = FALSE, goback,returnval = 0,bye, restart=FALSE;
	while (menuexit==FALSE)
			{
				choice = menu_start();
				switch (choice)
				{
				case(1):{
					if (game_control.juststarted ==TRUE)
						{menuexit=TRUE;}
					else
					{
					restart= menu_restart();
					  if (restart == TRUE)
						{
						menuexit = TRUE;
						returnval = 1;
						}
					put_screen();
					show_all_5();
					}

					break;
					}
				case(2):{
					returnval=2;
					menuexit=TRUE;
					break;
					}
				case(3):{
					menuexit=FALSE;
					high_score_table();
					put_screen();
					show_all_5();
					break;
					}
				case(4):{
					menuexit=FALSE;
					show_ins_1();
					put_screen();
					show_all_5();
					break;
					}
				case(5):{
					  bye= menu_exit();
					  if (bye == TRUE)
						{
						menuexit = TRUE;
						returnval = 5;
						}

					  put_screen();
					  show_all_5();
					  break;
					 }

				}

			}

	return (returnval);
	}

void show_all_5(void)
	{

		window_dice(0,die[0].facing);
		window_dice(1,die[1].facing);
		window_dice(2,die[2].facing);
		window_dice(3,die[3].facing);
		window_dice(4,die[4].facing);
		return;
	}
void get_screen (void)
	{
	window(1,1,80,25);
	gettext(1,1,80,25,screen);
	return;
	}
void put_screen(void)
	{
	window(1,1,80,25);
	puttext(1,1,80,25,screen);
	return;
	}

void message_box(char m1[15],char m2[15],char m3[15], char m4[15])
	{
	window(63,15,79,23);
	textbackground(LIGHTGRAY);
	clrscr();
	window(63,15,79,24);
	draw_box(1,1,17,9,BLACK);
	textcolor(BLACK);
	gotoxy(5,2);
	cputs("MESSAGES!");
	textcolor(RED);
	gotoxy(3,3);
	cputs("Die Total:");
	gotoxy(13,3);
	textcolor(YELLOW);
	cprintf("%d",die_total());
	textcolor(RED);
	gotoxy(3,4);
	cputs("Rolls Left:");
	gotoxy(14,4);
	textcolor(YELLOW);
	cprintf("%d",game_control.rolls_left);
	textcolor(BLUE);
	gotoxy(3,5);
	cputs(m1);
	gotoxy(2,6);
	cputs(m2);
	gotoxy(2,7);
	cputs(m3);
	gotoxy(2,8);
	cputs(m4);

	return;


	}

void show_help(void)
	{
	window(7,1,70,12);
	textbackground(GREEN);
	clrscr();
	window(7,1,70,13);
	draw_border(1,1,64,12,BLACK); //score border
	textcolor(BLUE);
	gotoxy(26,1);
	cputs("HELP SCREEN");
	write_help(3,3,"Ace(s)    :",check_acesthru6(1),chosen.itemchosen[0]);
	write_help(3,4,"Deuce(s)  :",check_acesthru6(2),chosen.itemchosen[1]);
	write_help(3,5,"Threes(s) :",check_acesthru6(3),chosen.itemchosen[2]);
	write_help(3,6,"Fours(s)  :",check_acesthru6(4),chosen.itemchosen[3]);
	write_help(3,7,"Fives(s)  :",check_acesthru6(5),chosen.itemchosen[4]);
	write_help(3,8,"Sixes(s)  :",check_acesthru6(6),chosen.itemchosen[5]);
	write_help(18,3,"One Pair(10)      :",check_onepair(),
		chosen.itemchosen[6]);
	write_help(18,4,"Two Pair(15)      :",check_twopair(),
		chosen.itemchosen[7]);
	write_help(18,5,"3 of a Kind(ALL)  :",check_3ofakind(),
		chosen.itemchosen[8]);
	write_help(18,6,"4 of a Kind(ALL)  :",check_4ofakind(),
		chosen.itemchosen[9]);
	write_help(18,7,"Micro Straight(15):",check_microstraight(),
		chosen.itemchosen[10]);
	write_help(18,8,"Small Straight(25):",check_smallstraight(),
		chosen.itemchosen[11]);
	write_help(18,9,"Large Straight(35):",check_largestraight(),
		chosen.itemchosen[12]);
	write_help(18,10,"Full House(35)    :",check_fullhouse(),
		chosen.itemchosen[13]);
	write_help(41,3,"Zamboozal (50)   :",check_zamboozal(),
		chosen.itemchosen[14]);
	write_help(41,4,"2nd Zamboozal(75):",check_2ndzamboozal(),
		chosen.itemchosen[15]);
	textcolor(WHITE);

	if (chosen.itemchosen[16] == FALSE)
		{
		gotoxy(41,5);
		cprintf("Black Jack (35)  : ??");
		}
	if ((die_total() == 21)&&
	    (chosen.itemchosen[16] == FALSE))
		{
		gotoxy(41,5);
		cprintf("Black Jack (35)  : 35");
		}
	if (chosen.itemchosen[17] == FALSE)
		{
		gotoxy(41,6);
		cprintf("War(35)          : ??");
		}
	if (chosen.itemchosen[18] == FALSE)
		{
		gotoxy(41,7);
		cprintf("Roulette(5*Roll) : ??");
		}


	write_help(41,8,"Gin Rummy (30)   :",check_ginrummy(),
		chosen.itemchosen[19]);
	write_help(41,9,"Chance (All)     :",die_total(),
		chosen.itemchosen[20]);
	if (chosen.itemchosen[21] == FALSE)
		{
		gotoxy(41,10);
		cprintf("Wild Play        : ??");
		}

	textcolor(BLUE);
	gotoxy(15,12);
	cputs("Press ANY KEY to go back to the Menu");

	getch();
	return;
	}

void write_help(int x,int y,char name[15],int score,int selected)
	{
	if (selected == FALSE)
	   {
	   textcolor(WHITE);
	   gotoxy(x,y);
	   cprintf("%s",name);
	   textcolor(RED);
		if (x<17)
			{cprintf("%2d",score);}
		else
			{cprintf("%3d",score);}
	   textcolor(WHITE);
	   }

	return;
	}

void select_dice(void)
	{
	int place = 0,leave = FALSE;

	window(1,1,80,25);//main window
	while (leave == FALSE)
		{
		place = dice_menu(place);

		if (place<5)
			{
			if (die[place].selected == TRUE)
				{
				die[place].selected = FALSE;
				die[place].facing = FRONT;
				window_dice(place,die[place].facing);
				leave = FALSE;
				}
			else
				{
				die[place].selected = TRUE;
				die[place].facing = BACK;
				window_dice(place,die[place].facing);
				leave = FALSE;
				}

			}
		if (place == 5)
				{ // back to menu
				leave = TRUE;
				}


		} // end while
	return;
	} // end procedure



int dice_menu(int place)
	{
	int counter;

	while (TRUE)
		{
		for (counter=0;counter<5;counter++)
			{
			switch(counter)
			{
				case (0):
				{
				window(2,17,12,23);
				window(2,17,12,24);
				break;
				}
				case (1):
				{
				window(14,17,24,23);
				window(14,17,24,24);
				break;
				}
				case (2):
				{
				window(26,17,36,23);
				window(26,17,36,24);
				break;
				}
				case (3):
				{
				window(38,17,48,23);
				window(38,17,48,24);
				break;
				}
				case (4):
				{
				window(50,17,60,23);
				window(50,17,60,24);
				break;
				}


			}// end case

		       //window_dice(counter,die[counter].facing);// show die 0
			textbackground(BLACK);
			if (counter == place)
				{draw_border(1,1,11,7,YELLOW);}
			else
				{draw_border(1,1,11,7,WHITE);}
			 }


		window(63,15,79,24);
		textbackground(LIGHTGRAY);

		if (place == 5)
			{draw_box(1,1,17,9,YELLOW);}
		else
			{draw_box(1,1,17,9,WHITE);}

		switch (get_code())
			{
			case L_ARROW:
				{
				place = (place >0) ? --place : 5;
				break;
				}
			case R_ARROW:
				{
				place = (place < 5) ? ++place : 0;
				break;
				}
			case '\r':
				{
				return(place);
				}
			case ' ':
				{
				return(place);
				}
			} // end case
		}  // end while
	} // end procedure

void setup_textboxes(void)
	{
	// tbox[0] is dice rolled
	strcpy (tbox[0].name,"DICE ROLLED");
	strcpy (tbox[0].item[0],"If needed, they ");
	strcpy (tbox[0].item[1],"Will be Resorted");
	tbox[0].nhpos = 5;  // name hpos
	tbox[0].ihpos[0] = 3; //item hpos
	tbox[0].ihpos[1] = 3;
	tbox[0].items = 2;
	tbox[0].left =29;
	tbox[0].top = 9;
	tbox[0].right= 48;
	tbox[0].bottom=16;
	tbox[0].backcolor = GREEN;
	tbox[0].titlecolor = WHITE;
	tbox[0].textcolor=YELLOW;
	tbox[0].bordercolor=BLACK;
	tbox[0].rhpos = 4; // return message hpos
	strcpy (tbox[0].returnmessage,"PRESS ANY KEY");

	// tbox[1] is for  black jack
	strcpy (tbox[1].name,"BLACK JACK TABLE");
       //strcpy (tbox[1].item[0]// USE SPRINTF IN CHECK
       //strcpy (tbox[1].item[1]// USE SPRINTF IN CHECK
	tbox[1].nhpos = 5;  // name hpos
	tbox[1].ihpos[0] = 3; //item hpos
	tbox[1].ihpos[1] = 3;
	tbox[1].ihpos[2] = 3; //item hpos
	tbox[1].ihpos[3] = 3;
	tbox[1].items = 4;
	tbox[1].left =22;
	tbox[1].top = 7;
	tbox[1].right= 46;
	tbox[1].bottom=16;
	tbox[1].backcolor = GREEN;
	tbox[1].titlecolor = WHITE;
	tbox[1].textcolor=YELLOW;
	tbox[1].bordercolor=BLACK;
	tbox[1].rhpos = 6; // return message hpos
	strcpy (tbox[1].returnmessage,"PRESS ANY KEY");

	// tbox[2] is for WAR
	strcpy (tbox[2].name,"BATTLE FIELD!");
       //strcpy (tbox[1].item[0]// USE SPRINTF IN CHECK
       //strcpy (tbox[1].item[1]// USE SPRINTF IN CHECK
	tbox[2].nhpos = 7;  // name hpos
	tbox[2].ihpos[0] = 3; //item hpos
	tbox[2].ihpos[1] = 3;
	tbox[2].ihpos[2] = 3; //item hpos
	tbox[2].ihpos[3] = 3;
	tbox[2].items = 4;
	tbox[2].left =22;
	tbox[2].top = 7;
	tbox[2].right= 48;
	tbox[2].bottom=16;
	tbox[2].backcolor = GREEN;
	tbox[2].titlecolor = WHITE;
	tbox[2].textcolor=YELLOW;
	tbox[2].bordercolor=BLACK;
	tbox[2].rhpos = 7; // return message hpos
	strcpy (tbox[2].returnmessage,"PRESS ANY KEY");

	// tbox[3] is for ROULETTE
	strcpy (tbox[3].name,"ROULETTE TABLE!");
       //strcpy (tbox[1].item[0]// USE SPRINTF IN CHECK
       //strcpy (tbox[1].item[1]// USE SPRINTF IN CHECK
	tbox[3].nhpos = 6;  // name hpos
	tbox[3].ihpos[0] = 3; //item hpos
	tbox[3].ihpos[1] = 3;
	tbox[3].ihpos[2] = 3; //item hpos
	tbox[3].ihpos[3] = 3;
	tbox[3].items = 4;
	tbox[3].left =22;
	tbox[3].top = 7;
	tbox[3].right= 48;
	tbox[3].bottom=16;
	tbox[3].backcolor = GREEN;
	tbox[3].titlecolor = WHITE;
	tbox[3].textcolor=YELLOW;
	tbox[3].bordercolor=BLACK;
	tbox[3].rhpos = 7; // return message hpos
	strcpy (tbox[3].returnmessage,"PRESS ANY KEY");

	// tbox[4] is for telling the turn score
	strcpy (tbox[4].name,"SCORE!");
       //strcpy (tbox[4].item[0]// USE SPRINTF IN CHECK
       //strcpy (tbox[4].item[1]// USE SPRINTF IN CHECK
	tbox[4].nhpos = 10;  // name hpos
	tbox[4].ihpos[0] = 3; //item hpos
	tbox[4].ihpos[1] = 3;
	tbox[4].ihpos[2] = 3; //item hpos
	tbox[4].ihpos[3] = 3;
	tbox[4].items = 1;
	tbox[4].left =27;
	tbox[4].top = 7;
	tbox[4].right= 52;
	tbox[4].bottom=13;
	tbox[4].backcolor = GREEN;
	tbox[4].titlecolor = WHITE;
	tbox[4].textcolor=YELLOW;
	tbox[4].bordercolor=BLACK;
	tbox[4].rhpos = 7; // return message hpos
	strcpy (tbox[4].returnmessage,"PRESS ANY KEY");

	// tbox[5] is for no dice to roll box
	strcpy (tbox[5].name,"NO DICE SELECTED!");
	tbox[5].nhpos = 3;  // name hpos
	tbox[5].items = 0;
	tbox[5].left =22;
	tbox[5].top = 7;
	tbox[5].right= 48;
	tbox[5].bottom=12;
	tbox[5].backcolor = RED;
	tbox[5].titlecolor = WHITE;
	tbox[5].textcolor=YELLOW;
	tbox[5].bordercolor=BLACK;
	tbox[5].rhpos = 3; // return message hpos
	strcpy (tbox[5].returnmessage,"PRESS ANY KEY");

	// tbox[6] is for wild play
	strcpy (tbox[6].name,"WILD PLAY!!");
	tbox[6].nhpos = 20;  // name hpos
	tbox[6].items = 0;
	tbox[6].left =14;
	tbox[6].top = 1;
	tbox[6].right= 64;
	tbox[6].bottom=6;
	tbox[6].backcolor = GREEN;
	tbox[6].titlecolor = YELLOW;
	tbox[6].textcolor=YELLOW;
	tbox[6].bordercolor=BLACK;
	tbox[6].rhpos = 7; // return message hpos
	strcpy (tbox[6].returnmessage,"PRESS ANY KEY TO START THE WILD SPIN");

	// tbox[7] is for wild play end;
	strcpy (tbox[7].name,"Wild Play Complete");
	tbox[7].nhpos = 13;  // name hpos
	tbox[7].ihpos[0] = 7;
	tbox[7].items = 1;
	tbox[7].left =19;
	tbox[7].top = 18;
	tbox[7].right= 59;
	tbox[7].bottom=24;
	tbox[7].backcolor = LIGHTGRAY;
	tbox[7].titlecolor = RED;
	tbox[7].textcolor=RED;
	tbox[7].bordercolor=BLACK;
	tbox[7].rhpos = 15; // return message hpos
	strcpy (tbox[7].returnmessage,"PRESS ANY KEY");
	strcpy (tbox[7].item[0],"You must now Finish your Turn");

	// tbox[8] is for wild play not on roll 3;
	strcpy (tbox[8].name,"IMPORTANT MESSAGE");
	tbox[8].nhpos = 14;  // name hpos
	tbox[8].ihpos[0] = 7;
	tbox[8].ihpos[1] = 9;
	tbox[8].items = 2;
	tbox[8].left =19;
	tbox[8].top = 10;
	tbox[8].right= 61;
	tbox[8].bottom=17;
	tbox[8].backcolor = RED;
	tbox[8].titlecolor = WHITE;
	tbox[8].textcolor=YELLOW;
	tbox[8].bordercolor=BLACK;
	tbox[8].rhpos = 16; // return message hpos
	strcpy (tbox[8].returnmessage,"PRESS ANY KEY");
	strcpy (tbox[8].item[0],"You Cannot Choose Wild Play Unless");
	strcpy (tbox[8].item[1],"You have 0 Rolls Remaining");

	// tbox[9] is for high score 1
	strcpy (tbox[9].name,"YOU HAVE A HIGH SCORE!");
	tbox[9].nhpos = 13;  // name hpos
	tbox[9].ihpos[0] = 4;
	tbox[9].items = 1;
	tbox[9].left =19;
	tbox[9].top = 10;
	tbox[9].right= 61;
	tbox[9].bottom=17;
	tbox[9].backcolor = BLUE;
	tbox[9].titlecolor = WHITE;
	tbox[9].textcolor=YELLOW;
	tbox[9].bordercolor=LIGHTGRAY;
	tbox[9].rhpos = 16; // return message hpos
	strcpy (tbox[9].returnmessage,"PRESS ANY KEY");
	strcpy (tbox[9].item[0],"");

	}

void text_box(int bn)   // bn = boxnum
	{
	int left,top,right,bottom,items,bc,rc,bdc,tc,width,height;
	int counter;

	left = tbox[bn].left;
	top = tbox[bn].top;
	right = tbox[bn].right;
	bottom= tbox[bn].bottom;
	items = tbox[bn].items;
	bc = tbox[bn].backcolor;
	rc = tbox[bn].titlecolor;
	bdc = tbox[bn].bordercolor;
	tc = tbox[bn].textcolor;
	width = (right - left)+1;
	height = (bottom - top)+1;

	window(left,top,right,bottom);
	textbackground(bc); // back ground color bc
	clrscr();
	window(left,top,right,bottom+1);
	draw_border(1,1,width,height,bdc); // border box color bdc
	textcolor(rc);
	gotoxy (tbox[bn].nhpos,2);
	cputs(tbox[bn].name);
	draw_line(2,3,width,bdc);
	textcolor(tc); // normal text color tc
	for (counter=0;counter<items;counter++)
		{
		gotoxy(tbox[bn].ihpos[counter],counter+4);
		cputs (tbox[bn].item[counter]);
		}
	draw_line(2,items+4,width,bdc);
	textcolor(rc);  // return message color
	gotoxy(tbox[bn].rhpos,items+5);
	cputs(tbox[bn].returnmessage);
	getch();
	return;
	}

int roll_dice(void)
	{
	 // roll selected dice first time
	 int rolled = 0, menuexit = FALSE, counter, repeat;
	 char m1[50],m2[50],m3[50],m4[50];
	 for (counter=0;counter < 5;counter++)
		{
		if (die[counter].selected == TRUE)
			{
			rolled++;
			for (repeat=0;repeat<6;repeat++)
				{
				die[counter].side = roll_1();
				switch (counter)
				{
				case (0):
					{
					draw_front(die[0].side,2,17,12,23);
					break;
					}
				case (1):
					{
					draw_front(die[1].side,14,17,24,23);
					break;
					}
				case (2):
					{
					draw_front(die[2].side,26,17,36,23);
					break;
					}
				case (3):
					{
					draw_front(die[3].side,38,17,48,23);
					break;
					}
				case (4):
					{
					draw_front(die[4].side,50,17,60,23);
					break;
					}
				}

				delay(100);
				}
			die[counter].selected = FALSE;
			die[counter].facing = FRONT;
			}
		}
	//show_all_5();

	if (rolled > 0)
		{
		text_box(0); // dice rolled box
		}
	 if (rolled == 0)
		{
		menuexit = FALSE;
		text_box(5);
		put_screen();
		show_all_5();
		}
	 else
		{menuexit = TRUE;}

	 return(menuexit);
	 } // exit rolled dice

int select_item()
	{
	int hpos=3,vpos=4, ctr, leave = FALSE;
	int done = FALSE, temp, turnscore=0, keep=TRUE, stay=TRUE ;
	int complete = FALSE;

	// print selected item with different background

	while (complete == FALSE)
	{
	leave = FALSE;
	window_scores();
	show_scores();
	while (leave==FALSE)
	{
	keep = TRUE;
	stay= TRUE;

	for (ctr = 0;ctr<21;ctr++)
		{

		if ((hpos ==sc[ctr].hpos) &&
		    (vpos ==sc[ctr].vpos))
			{
			textbackground(LIGHTGRAY);
			}

		else
			{
			textbackground(CYAN);
			}

			write_score(sc[ctr].hpos,sc[ctr].vpos,sc[ctr].name,
			score.itemscore[ctr],chosen.itemchosen[ctr]);


		}
	if ((hpos==41)&&(vpos==11))
		{textbackground(LIGHTGRAY);}
	else
		{textbackground(CYAN);}
	gotoxy(41,11);
	textcolor(RED);
	cprintf("W");
	textcolor(BLUE);
	cprintf("I");
	textcolor(BLACK);
	cprintf("L");
	textcolor(YELLOW);
	cprintf("D");
	textcolor(BLUE);
	cprintf("%s",game_control.wildplay);

	if ((hpos==3)&&(vpos==10))
		{textbackground(LIGHTGRAY);}
	else
		{textbackground(CYAN);}
	gotoxy(3,10);
	textcolor(BLUE);
	cprintf("BACK TO MENU!");


	switch (get_code())
		{
		case U_ARROW:
			{
			if (hpos==3)
				{
				vpos = (vpos >4) ? --vpos:10;
				}
			else
				{
				vpos = (vpos >4) ? --vpos:11;
				}
			break;
			}
		 case D_ARROW:
			{
			if (hpos==3)
				{
				vpos = (vpos <10) ? ++vpos:4;
				}
			else
				{
				vpos = (vpos <11) ? ++vpos:4;
				}
			break;
			}
		case R_ARROW:
			{
			if (hpos == 3)
				{
				hpos = 18;
				break;
				}
			else if (hpos == 18)
				{
				hpos = 41;
				break;
				}
			else if (hpos == 41)
				{
				hpos =3;
				vpos =(vpos==11)? 10:vpos;
				break;
				}
			break;
			}  // end case r_arrow

		case L_ARROW:
			{
			if (hpos == 3)
				{
				hpos = 41;
				break;
				}
			else if (hpos == 18)
				{
				hpos = 3;
				vpos =(vpos==11)? 10:vpos;
				break;
				}
			else if (hpos == 41)
				{
				hpos =18;
				break;
				}
			break;
			}  // end case r_arrow

		case ESCAPE:
			{
			leave = TRUE;
			break;
			}
		case '\r':
			{
			leave = TRUE;
			break;
			}

		} // end case

	if (hpos==3)
		{temp = 0;}
	if (hpos==18)
		{temp = 6;}
	if (hpos==41)
		{temp = 14;}

       // the following is menu diagnostics
       /*	gotoxy(1,1);
	cprintf("hpos = %2d, Vpos = %2d chosen = %d, score =%3d",hpos,vpos,
		chosen.itemchosen[(vpos-4)+temp],
		score.itemscore[(vpos-4)+temp]);

	gotoxy(1,13);
	cprintf("keep=%d, stay=%d, complete=%d, done=%d",keep,stay,complete,
		done);  */

	} // end WHILE

	if ((hpos==3) && (chosen.itemchosen[(vpos-4)] == TRUE))
		{stay = FALSE;}
	if ((hpos==3) && ((vpos-4)==6))
		{
		// exit to menu
		done = FALSE;
		stay=TRUE;
		keep=TRUE;
		break;
		}
	if ((hpos==3) && (chosen.itemchosen[(vpos-4)] == FALSE))
		{
		done = TRUE;
		switch(vpos-4)
			{
			case(0):
				{
				stay =menu_you_chose("ACES");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(1);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}

				score.itemscore[0] = check_acesthru6(1);
				chosen.itemchosen[0]=TRUE;
				break;
				} // end vpos case 4
			case(1):
				{
				stay =menu_you_chose("DUECES");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(2);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[1] = check_acesthru6(2);
				chosen.itemchosen[1]=TRUE;

				break;
				}
			case(2):
				{
				stay =menu_you_chose("THREES");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(3);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[2] = check_acesthru6(3);
				chosen.itemchosen[2]=TRUE;
				break;
				}
			case(3):
				{
				stay =menu_you_chose("FOURS");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(4);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[3] = check_acesthru6(4);
				chosen.itemchosen[3]=TRUE;
				break;
				}
			case(4):
				{
				stay =menu_you_chose("FIVES");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(5);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[4] = check_acesthru6(5);
				chosen.itemchosen[4]=TRUE;
				break;
				}
			case(5):
				{
				stay =menu_you_chose("SIXES");
				if (stay == FALSE)
					{break;}
				turnscore=check_acesthru6(6);
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[5] = check_acesthru6(6);
				chosen.itemchosen[5]=TRUE;
				break;
				}


			} // end switch vpos

		} // end hpos if 3


	if ((hpos==18) && (chosen.itemchosen[(vpos-4)+6] == TRUE))
		{stay = FALSE;}
	if ((hpos==18) && (chosen.itemchosen[(vpos-4)+6] == FALSE))
		{
		done = TRUE;
		switch(vpos-4)
			{
			case(0):
				{
				stay =menu_you_chose("ONE PAIR");
				if (stay == FALSE)
					{break;}
				turnscore=check_onepair();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[6] = check_onepair();
				chosen.itemchosen[6]=TRUE;
				break;
				} // end vpos case 4
			case(1):
				{
				stay =menu_you_chose("TWO PAIR");
				if (stay == FALSE)
					{break;}
				turnscore=check_twopair();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[7] = check_twopair();
				chosen.itemchosen[7]=TRUE;
				break;
				}
			case(2):
				{
				stay =menu_you_chose("THREE OF A KIND");
				if (stay == FALSE)
					{break;}
				turnscore=check_3ofakind();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[8] = check_3ofakind();
				chosen.itemchosen[8]=TRUE;
				break;
				}
			case(3):
				{
				stay =menu_you_chose("FOUR OF A KIND");
				if (stay == FALSE)
					{break;}
				turnscore=check_4ofakind();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[9] = check_4ofakind();
				chosen.itemchosen[9]=TRUE;
				break;
				}
			case(4):
				{
				stay =menu_you_chose("MICRO STRAIGHT");
				if (stay == FALSE)
					{break;}
				turnscore=check_microstraight();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[10] = check_microstraight();
				chosen.itemchosen[10]=TRUE;
				break;
				}
			case(5):
				{
				stay =menu_you_chose("SMALL STRAIGHT");
				if (stay == FALSE)
					{break;}
				turnscore=check_smallstraight();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[11] = check_smallstraight();
				chosen.itemchosen[11]=TRUE;
				break;
				}
			case(6):
				{
				stay =menu_you_chose("LARGE STRAIGHT");
				if (stay == FALSE)
					{break;}
				turnscore=check_largestraight();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[12] = check_largestraight();
				chosen.itemchosen[12]=TRUE;
				break;
				}
			case(7):
				{
				stay =menu_you_chose("FULL HOUSE");
				if (stay == FALSE)
					{break;}
				turnscore=check_fullhouse();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[13] = check_fullhouse();
				chosen.itemchosen[13]=TRUE;
				break;
				}



			} // end switch vpos

		} // end hpos if 3

	  if ((hpos==41) && (chosen.itemchosen[(vpos-4)+14] == TRUE))
		{stay = FALSE;}

	  if ((hpos==41) && (chosen.itemchosen[(vpos-4)+14] == FALSE))
		{
		done = TRUE;
		switch(vpos-4)
			{


			case(0):
				{
				stay =menu_you_chose("ZAMBOOZAL");
				if (stay == FALSE)
					{break;}
				turnscore=check_zamboozal();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[14] = check_zamboozal();
				chosen.itemchosen[14]=TRUE;
				break;
				} // end vpos case 4
			case(1):
				{
				stay =menu_you_chose("2ND ZAMBOOZAL");
				if (stay == FALSE)
					{break;}
				turnscore=check_2ndzamboozal();
				if (turnscore == 0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[15] = check_2ndzamboozal();
				chosen.itemchosen[15]=TRUE;
				break;
				}
			case(2):
				{
				stay =menu_you_chose("BLACK JACK");
				if (stay == FALSE)
					{break;}
				turnscore=check_blackjack();
				score.itemscore[16] =turnscore;
				chosen.itemchosen[16]=TRUE;
				break;
				}
			case(3):
				{
				stay =menu_you_chose("WAR");
				if (stay == FALSE)
					{break;}
				turnscore=check_war();
				score.itemscore[17]= turnscore;
				chosen.itemchosen[17]=TRUE;
				break;
				}
			case(4):
				{
				stay =menu_you_chose("ROULETTE");
				if (stay == FALSE)
					{break;}
				turnscore=check_roulette();
				score.itemscore[18]= turnscore;
				chosen.itemchosen[18]=TRUE;
				break;
				}
			case(5):
				{
				stay =menu_you_chose("GIN RUMMY");
				if (stay == FALSE)
					{break;}
				turnscore=check_ginrummy();
				if (turnscore ==0)
					{keep = menu_do_keep();}
				if (keep == FALSE)
					{break;}
				score.itemscore[19] = check_ginrummy();
				chosen.itemchosen[19]=TRUE;
				break;
				}
			case(6):
				{
				stay =menu_you_chose("CHANCE");
				if (stay == FALSE)
					{break;}
				turnscore = die_total();
				score.itemscore[20] = die_total();
				chosen.itemchosen[20]=TRUE;
				break;
				}
			case(7):
				{
				if (game_control.rolls_left >0)
					{
					text_box(8);
					stay=FALSE;
					put_screen();
					show_all_5();
					break;
					}
				stay =menu_you_chose("WILD PLAY");
				if (stay == FALSE)
					{break;}

				do_wildplay();
				turnscore = 0;
				chosen.itemchosen[21] = TRUE;
				done =FALSE;
				if (game_control.turn==TRUE)
					{done=TRUE;}
				if (game_control.re_roll==TRUE)
					{done=TRUE;}
				put_screen();
				show_all_5();
				window_scores();
				show_scores();
				window_totals();
				display_totals();
				get_screen();


				break;
				}



			} // end switch vpos

		} // end hpos if 3

	if ((stay==TRUE) && (keep ==TRUE))
		{complete = TRUE;}

	} // end complete while
	if (turnscore >0)
		{
		sprintf(tbox[4].item[0],"This Turn's Score is %d",turnscore);
		text_box(4);
		}

	return (done);
	}// end procedure

void fill_sc(void)   //sc = scores
	{
	sc[0].hpos=3;
	sc[0].vpos=4;
	strcpy(sc[0].name,"Ace(s)    :");
	sc[1].hpos = 3;
	sc[1].vpos = 5;
	strcpy(sc[1].name,"Deuce(s)  :");
	sc[2].hpos = 3;
	sc[2].vpos = 6;
	strcpy(sc[2].name,"Threes(s) :");
	sc[3].hpos = 3;
	sc[3].vpos = 7;
	strcpy(sc[3].name,"Fours(s)  :");
	sc[4].hpos = 3;
	sc[4].vpos = 8;
	strcpy(sc[4].name,"Fives(s)  :");
	sc[5].hpos = 3;
	sc[5].vpos = 9;
	strcpy(sc[5].name,"Sixes(s)  :");
	sc[6].hpos = 18;
	sc[6].vpos = 4;
	strcpy(sc[6].name,"One Pair(10)      :");
	sc[7].hpos = 18;
	sc[7].vpos = 5;
	strcpy(sc[7].name,"Two Pair(15)      :");
	sc[8].hpos = 18;
	sc[8].vpos = 6;
	strcpy(sc[8].name,"3 of a Kind(ALL)  :");
	sc[9].hpos = 18;
	sc[9].vpos = 7;
	strcpy(sc[9].name,"4 of a Kind(ALL)  :");
	sc[10].hpos = 18;
	sc[10].vpos = 8;
	strcpy(sc[10].name,"Micro Straight(15):");
	sc[11].hpos = 18;
	sc[11].vpos = 9;
	strcpy(sc[11].name,"Small Straight(25):");
	sc[12].hpos = 18;
	sc[12].vpos =10;
	strcpy(sc[12].name,"Large Straight(35):");
	sc[13].hpos = 18;
	sc[13].vpos =11;
	strcpy(sc[13].name,"Full House(35)    :");
	sc[14].hpos = 41;
	sc[14].vpos = 4;
	strcpy(sc[14].name,"Zamboozal (50)   :");
	sc[15].hpos = 41;
	sc[15].vpos = 5;
	strcpy(sc[15].name,"2nd Zamboozal(75):");
	sc[16].hpos = 41;
	sc[16].vpos = 6;
	strcpy(sc[16].name,"Black Jack (35)  :");
	sc[17].hpos = 41;
	sc[17].vpos = 7;
	strcpy(sc[17].name,"War (35)         :");
	sc[18].hpos = 41;
	sc[18].vpos = 8;
	strcpy(sc[18].name,"Roulette(5*Roll) :");
	sc[19].hpos = 41;
	sc[19].vpos = 9;
	strcpy(sc[19].name,"Gin Rummy (30)   :");
	sc[20].hpos = 41;
	sc[20].vpos = 10;
	strcpy(sc[20].name,"Chance (ALL)     :");
	}

void do_wildplay(void)
	{
	int wildnum, repeat, row;
	char c;
	put_screen();
	show_all_5();

	text_box(6);
	window(23,7,53,17);
	textbackground(BLACK); // back ground color bc
	clrscr();
	window(23,7,53,18);

	for (repeat=0;repeat<10;repeat++)
	{
	 wildnum=(random(7)+1);

		switch (wildnum)
		{
			case(1):
				{ //+5 to top
				textbackground(BLACK);
				draw_border(1,1,31,11,RED);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(LIGHTGRAY);
					cputs("                           ");
					}
				textcolor(BLUE);
				draw_plus();
				textcolor(MAGENTA);
				gotoxy(15,3);
				cputs("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(15,4);
				cputs("\xB2");
				gotoxy(15,5);
				cputs("\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(15,6);
				cputs("       \xB2");
				gotoxy(15,7);
				cputs("\xB2      \xB2");
				gotoxy(15,8);
				cputs(" \xB2\xB2\xB2\xB2\xB2\xB2");
				textcolor(BLUE);
				gotoxy(7,9);
				cputs("POINTS");
				gotoxy(4,10);
				textcolor(RED);
				cputs("TO THE ");
				textcolor(YELLOW);
				cputs("TOP 6 SCORE");
				break;
				}
			case(2):
				{ //+10 to bottom
				textbackground(BLACK);
				draw_border(1,1,31,11,YELLOW);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(CYAN);
					cputs("                           ");
					}
				textcolor(BLUE);
				draw_plus();
				textcolor(WHITE);
				gotoxy(15,3);
				cputs("  \xB2 ");
				gotoxy(15,4);
				cputs(" \xB2\xB2");
				gotoxy(15,5);
				cputs("  \xB2");
				gotoxy(15,6);
				cputs("  \xB2");
				gotoxy(15,7);
				cputs("  \xB2");
				gotoxy(15,8);
				cputs("\xB2\xB2\xB2\xB2\xB2 ");
				gotoxy(22,3);
				cputs(" \xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,4);
				cputs("\xB2     \xB2");
				gotoxy(22,5);
				cputs("\xB2     \xB2");
				gotoxy(22,6);
				cputs("\xB2     \xB2");
				gotoxy(22,7);
				cputs("\xB2     \xB2");
				gotoxy(22,8);
				cputs(" \xB2\xB2\xB2\xB2\xB2 ");
				gotoxy(7,9);
				cputs("POINTS");
				gotoxy(4,10);
				textcolor(RED);
				cputs("TO LOWER 15 ");
				textcolor(YELLOW);
				cputs("SCORE");
				break;
				}
			case(3):
				{ // + 10 to top
				textbackground(BLACK);
				draw_border(1,1,31,11,WHITE);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(GREEN);
					cputs("                           ");
					}
				textcolor(BLUE);
				draw_plus();
				textcolor(BLACK);
				gotoxy(15,3);
				cputs("  \xB2 ");
				gotoxy(15,4);
				cputs(" \xB2\xB2");
				gotoxy(15,5);
				cputs("  \xB2");
				gotoxy(15,6);
				cputs("  \xB2");
				gotoxy(15,7);
				cputs("  \xB2");
				gotoxy(15,8);
				cputs("\xB2\xB2\xB2\xB2\xB2 ");
				gotoxy(22,3);
				cputs(" \xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,4);
				cputs("\xB2     \xB2");
				gotoxy(22,5);
				cputs("\xB2     \xB2");
				gotoxy(22,6);
				cputs("\xB2     \xB2");
				gotoxy(22,7);
				cputs("\xB2     \xB2");
				gotoxy(22,8);
				cputs(" \xB2\xB2\xB2\xB2\xB2 ");
				gotoxy(7,9);
				cputs("POINTS");
				gotoxy(4,10);
				textcolor(YELLOW);
				cputs("TO TOP 6 ");
				textcolor(RED);
				cputs("SCORE");
				break;
				}
			case(4):
				{ // + 20 to bottom
				textbackground(BLACK);
				draw_border(1,1,31,11,MAGENTA);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(LIGHTGRAY);
					cputs("                           ");
					}
				textcolor(BLUE);
				draw_plus();
				textcolor(WHITE);
				gotoxy(15,3);
				cputs(" \xB2\xB2\xB2\xB2 ");
				gotoxy(15,4);
				cputs("\xB2    \xB2");
				gotoxy(15,5);
				cputs("    \xB2");
				gotoxy(15,6);
				cputs(" \xB2\xB2\xB2");
				gotoxy(15,7);
				cputs("\xB2    ");
				gotoxy(15,8);
				cputs("\xB2\xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,3);
				cputs(" \xB2\xB2\xB2\xB2\xB2");
				gotoxy(22,4);
				cputs("\xB2     \xB2");
				gotoxy(22,5);
				cputs("\xB2     \xB2");
				gotoxy(22,6);
				cputs("\xB2     \xB2");
				gotoxy(22,7);
				cputs("\xB2     \xB2");
				gotoxy(22,8);
				cputs(" \xB2\xB2\xB2\xB2\xB2 ");
				gotoxy(7,9);
				cputs("POINTS");
				gotoxy(4,10);
				textcolor(RED);
				cputs("TO LOWER 15 ");
				textcolor(YELLOW);
				cputs("SCORE");
				break;
				}
			case(5):
				{  //whole turn over
				textbackground(BLACK);
				draw_border(1,1,31,11,MAGENTA);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(GREEN);
					cputs("                           ");
					}
				//T
				textcolor(BLACK);
				gotoxy(4,3);
				cputs("\xB2\xB2\xB2\xB2\xB2");
				gotoxy(4,4);
				cputs("\x20\x20\xB2\x20\x20");
				gotoxy(4,5);
				cputs("\x20\x20\xB2\x20\x20");
				gotoxy(4,6);
				cputs("\x20\x20\xB2\x20\x20");
				gotoxy(4,7);
				cputs("\x20\x20\xB2\x20\x20");
				//U
				textcolor(WHITE);
				gotoxy(11,3);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,4);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,5);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,6);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,7);
				cputs("\x20\xB2\xB2\xB2\x20");
				//R
				gotoxy(18,3);
				cputs("\xB2\xB2\xB2\xB2\x20");
				gotoxy(18,4);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(18,5);
				cputs("\xB2\xB2\xB2\xB2\x20");
				gotoxy(18,6);
				cputs("\xB2\x20\xB2\x20\x20");
				gotoxy(18,7);
				cputs("\xB2\x20\x20\xB2\xB2");
				//N
				gotoxy(25,3);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(25,4);
				cputs("\xB2\xB2\x20\x20\xB2");
				gotoxy(25,5);
				cputs("\xB2\x20\xB2\x20\xB2");
				gotoxy(25,6);
				cputs("\xB2\x20\x20\xB2\xB2");
				gotoxy(25,7);
				cputs("\xB2\x20\x20\x20\xB2");

				gotoxy(4,9);
				textcolor(YELLOW);
				cputs("Take your Whole Turn Over!");
				break;
				}

			 case(6):
				{  //re-roll dice
				textbackground(BLACK);
				draw_border(1,1,31,11,MAGENTA);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(LIGHTGRAY);
					cputs("                           ");
					}
				//R
				textcolor(BLACK);
				gotoxy(4,3);
				cputs("\xB2\xB2\xB2\xB2\x20");
				gotoxy(4,4);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(4,5);
				cputs("\xB2\xB2\xB2\xB2\x20");
				gotoxy(4,6);
				cputs("\xB2\x20\xB2\x20\x20");
				gotoxy(4,7);
				cputs("\xB2\x20\x20\xB2\xB2");

				//O
				textcolor(BLUE);
				gotoxy(11,3);
				cputs("\x20\xB2\xB2\xB2\x20");
				gotoxy(11,4);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,5);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,6);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,7);
				cputs("\x20\xB2\xB2\xB2\x20");
				//L
				gotoxy(18,3);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(18,4);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(18,5);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(18,6);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(18,7);
				cputs("\xB2\xB2\xB2\xB2\xB2");
				//L
				gotoxy(25,3);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(25,4);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(25,5);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(25,6);
				cputs("\xB2\x20\x20\x20\x20");
				gotoxy(25,7);
				cputs("\xB2\xB2\xB2\xB2\xB2");

				gotoxy(10,9);
				textcolor(RED);
				cputs("One Extra");
				gotoxy(11,10);
				cputs("Roll!!");
				break;

				}
			 case(7):
				{  // nothing ya loser
				textbackground(BLACK);
				draw_border(1,1,31,11,BLUE);
				for (row=2;row<11;row++)
					{
					gotoxy(3,row);
					textbackground(BLACK);
					cputs("                           ");
					}
				//N
				textcolor(YELLOW);
				gotoxy(3,3);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(3,4);
				cputs("\xB2\xB2\x20\x20\xB2");
				gotoxy(3,5);
				cputs("\xB2\x20\xB2\x20\xB2");
				gotoxy(3,6);
				cputs("\xB2\x20\x20\xB2\xB2");
				gotoxy(3,7);
				cputs("\xB2\x20\x20\x20\xB2");

				//A
				textcolor(RED);
				gotoxy(11,3);
				cputs("\x20\x20\xB2\x20\x20");
				gotoxy(11,4);
				cputs("\x20\xB2\x20\xB2\x20");
				gotoxy(11,5);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(11,6);
				cputs("\xB2\xB2\xB2\xB2\xB2");
				gotoxy(11,7);
				cputs("\xB2\x20\x20\x20\xB2");
				//D
				gotoxy(18,3);
				cputs("\xB2\xB2\xB2\xB2\x20");
				gotoxy(18,4);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(18,5);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(18,6);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(18,7);
				cputs("\xB2\xB2\xB2\xB2\x20");
				textcolor(RED);
				//A
				gotoxy(25,3);
				cputs("\x20\x20\xB2\x20\x20");
				gotoxy(25,4);
				cputs("\x20\xB2\x20\xB2\x20");
				gotoxy(25,5);
				cputs("\xB2\x20\x20\x20\xB2");
				gotoxy(25,6);
				cputs("\xB2\xB2\xB2\xB2\xB2");
				gotoxy(25,7);
				cputs("\xB2\x20\x20\x20\xB2");

				gotoxy(7,9);
				textcolor(RED);
				cputs("You Get Nothing!");
				textcolor(WHITE);
				gotoxy(11,10);
				cputs("YA LOSER!");
				draw_border(1,1,31,11,RED);

				break;
				}


		} //end switch
		delay(300);
	} // end repeat
	switch (wildnum)
		{
		 case(1):
			{
			strcpy(game_control.wildplay," Top +5");
			score.itemscore[21] = 5;
			text_box(7);
			break;
			}
		 case(2):
			{
			strcpy(game_control.wildplay," Bottom +10");
			score.itemscore[22] = 10;
			text_box(7);
			break;
			}
		 case(3):
			{
			strcpy(game_control.wildplay," Top +10");
			score.itemscore[21] = 10;
			text_box(7);
			break;
			}
		 case(4):
			{
			strcpy(game_control.wildplay," Bottom +20");
			score.itemscore[22] = 20;
			text_box(7);
			break;
			}
		 case(5):
			{
			strcpy(game_control.wildplay," Turn Over!");
			strcpy(tbox[7].item[0],"You get your Turn Over");
			text_box(7);
			game_control.rolls_left=4;
			game_control.turn=TRUE;
			break;
			}
		 case(6):
			{
			strcpy(game_control.wildplay," RE-ROLL!");
			strcpy(tbox[7].item[0],"You Get One EXTRA Re_roll!");
			text_box(7);
			game_control.rolls_left = 2;
			game_control.re_roll = TRUE;
			break;
			}
		 case(7):
			{
			strcpy(game_control.wildplay,"NOTHING!");
			text_box(7);
			break;
			}
		} // end switch

	return;
	}// end function

void draw_plus(void)
	{
		gotoxy(4,3);
		cputs("    \xBA");
		gotoxy(4,4);
		cputs("    \xBA");
		gotoxy(4,5);
		cputs("\xCD\xCD\xCD\xCD\xCE\xCD\xCD\xCD\xCD");
		gotoxy(4,6);
		cputs("    \xBA");
		gotoxy(4,7);
		cputs("    \xBA");


	}


void show_ins_1(void)
	{
	int choice;
	window(1,1,80,24);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,25);
	clrscr();
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(25,3);
	textcolor(RED);
	cputs("Instructions - Page 1 OF 5");
	textcolor(YELLOW);
	gotoxy(3,5);
	cputs("   Zamboozal Poker Dice is a dice game (of course).  The object is to");
	gotoxy(3,6);
	cputs("get the highest possible score by getting poker hands, and other card game");
	gotoxy(3,7);
	cputs("hands on five rolled dice.  You get 5 dice, and can re-roll any or all of");
	gotoxy(3,8);
	cputs("them two times before you pick a score item (category) to place your hand.");
	gotoxy(3,9);
	cputs("   The game works like this:  At the beginning of your turn, all five dice");
	gotoxy(3,10);
	cputs("are rolled for you.  At this time you can: SELECT A SCORE ITEM to place your");
	gotoxy(3,11);
	cputs("hand, or SELECT DICE, then RE-ROLL them.  You will also have other options.");
	gotoxy(3,12);
	cputs("These are: HELP, will show you what score you would receive if you");
	gotoxy(3,13);
	cputs("chose any of the score items you have not already selected. SEE SCORES, will");
	gotoxy(3,14);
	cputs("temporarily remove the menu box to allow un-obscured view of the game board.");
	gotoxy(3,15);
	cputs("BACK TO START MENU will allow you to re-start your game, view high scores,");
	gotoxy(3,16);
	cputs("view these instructions or quit the program.");
	gotoxy(3,17);
	cputs("   You are able to select and roll dice twice on each turn.  After the second");
	gotoxy(3,18);
	cputs("re-roll, you will be forced to choose one the 21 score items or WILD PLAY.");

	strcpy(menu[9].item[0],"NEXT PAGE");
	choice = menu_ins_1();

	if (choice == 2)
		{return;}
	if (choice==1)
		{show_ins_2();}
	return;
	}

void show_ins_2(void)
	{
	int choice;
	window(1,1,80,24);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,25);
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(25,3);
	textcolor(RED);
	cputs("Instructions - Page 2 OF 5");
	textcolor(YELLOW);
	gotoxy(3,5);
	cputs("The score items are as follows:");
	gotoxy(3,6);
	cputs("TOP SIX: These are ACES(ones) thru SIX.  You score the face value of ");
	gotoxy(3,7);
	cputs("each die you choose.  For example, if you have 2 sixes, and you choose ");
	gotoxy(3,8);
	cputs("SIXES, you will score 12 points.");
	gotoxy(3,10);
	cputs("LOWER 15: These consist of poker, as well as other card game hands.");
	gotoxy(3,11);
	cputs("ONE PAIR - Two dice that are the same: score 10 points.");
	gotoxy(3,12);
	cputs("TWO PAIR - Two pairs of dice that are the same: score 15 points.");
	gotoxy(3,13);
	cputs("3 OF A KIND - Three dice that are the same - score the total of all dice.");
	gotoxy(3,14);
	cputs("4 OF A KIND - Four dice that are the same - score the total of all dice.");
	gotoxy(3,15);
	cputs("MICRO STRAIGHT - 3 dice that are in continuous number order. EX: 1 2 3");
	gotoxy(7,16);
	cputs("- score 15 points.");
	gotoxy(3,17);
	cputs("SMALL STRAIGHT - Same as above, but 4 dice in order - score 25 points.");

	choice = menu_ins_2();

	if (choice == 2)
		{show_ins_1();}
	if (choice == 3)
		{return;}
	if (choice==1)
		{show_ins_3();}
	return;
	}

void show_ins_3(void)
	{
	int choice;
	window(1,1,80,24);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,25);
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(25,3);
	textcolor(RED);
	cputs("Instructions - Page 3 OF 5");
	textcolor(YELLOW);
	gotoxy(3,5);
	cputs("LARGE STRAIGHT - All 5 dice in order: 12345 or 23456 - score 35 Points.");
	gotoxy(3,6);
	cputs("FULL HOUSE - 3 of one die side and 2 of another: EX 11166 - Score 35 Pts.");
	gotoxy(3,7);
	cputs("ZAMBOOZAL - The game's Namesake. All five dice the same side: EX: 11111");
	gotoxy(7,8);
	cputs("You score 50 points + the total of the dice. If you have 55555");
	gotoxy(7,9);
	cputs("then you would score 75 Points.");
	gotoxy(3,10);
	cputs("2ND ZAMBOOZAL - You can only score on this one if you have a regular");
	gotoxy(7,11);
	cputs("ZAMBOOZAL first.  Same scoring, but a base of 75 points.");
	gotoxy(3,12);
	cputs("BLACK JACK - If your DIE TOTAL  is 21, or if you beat the dealers's hand");
	gotoxy(7,13);
	cputs("and you stay 21 or under, you score 35 points.");
	gotoxy(3,14);
	cputs("WAR - The computer will roll 5 dice, if your total is higher you win.");
	gotoxy(7,15);
	cputs("If you tie, another die will be rolled for each of you - 35 Points.");

	choice = menu_ins_2();

	if (choice == 2)
		{show_ins_2();}
	if (choice == 3)
		{return;}
	if (choice==1)
		{show_ins_4();}
	return;
	}

void show_ins_4(void)
	{
	int choice;
	window(1,1,80,24);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,25);
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(25,3);
	textcolor(RED);
	cputs("Instructions - Page 4 OF 5");
	textcolor(YELLOW);
	gotoxy(3,5);
	cputs("ROULETTE - The computer will roll 1 die.  If any of your dice match the");
	gotoxy(7,6);
	cputs("computer roll, you get 5 * the face value of the die. EX: if the computer");
	gotoxy(7,7);
	cputs("rolls a 2 and you have 2 threes, you score 5*3 + 5*3 or 30 points.");
	gotoxy(3,8);
	cputs("GIN RUMMY - A pair of dice the same, and a Micro Straight in the same hand");
	gotoxy(7,9);
	cputs("or a FULL HOUSE will score 30 points. EX: 55123 or 55111.");
	gotoxy(3,10);
	cputs("CHANCE - The face value of all the dice, score the DIE TOTAL.");
	gotoxy(3,11);
	cputs("WILD PLAY - This, like all the others, can only be used once.  You will");
	gotoxy(7,12);
	cputs("randomly receive ONE of the following:+ 5 points to your TOP 6 score,");
	gotoxy(7,13);
	cputs("+ 10 points to BOTTOM score, + 10 to TOP 6 score, + 20 to BOTTOM score,");
	gotoxy(7,14);
	cputs("Take you whole TURN OVER, Select and RE-ROLL dice one more time or");
	gotoxy(7,15);
	cputs("NOTHING at all ... You take your chances!!!");

	choice = menu_ins_2();

	if (choice == 2)
		{show_ins_3();}
	if (choice == 3)
		{return;}
	if (choice == 1)
		{show_ins_5();}
	return;
	}


void show_ins_5(void)
	{
	int choice;
	window(1,1,80,24);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,25);
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(25,3);
	textcolor(RED);
	cputs("Instructions - Page 5 OF 5 :LAST PAGE");
	textcolor(YELLOW);
	gotoxy(3,5);
	cputs("BONUS: The bonus is based on your TOP 6 score. ");
	gotoxy(7,6);
	cputs("Over 57 = 30 Bonus points.  Over 67  = Bonus 35 points.");
	gotoxy(7,7);
	cputs("Over 70 = 40 bonus points.");
	gotoxy(3,8);
	cputs("END OF GAME: At the end of the game, you will be given full statistics");
	gotoxy(7,9);
	cputs("on the game, and if you have one of the top scores, those statistics will");
	gotoxy(7,10);
	cputs("be stored for later viewing through the high score table.");
	gotoxy(5,12);
	cputs("This is my first finished game on the PC, it is free, but copywrited.");
	gotoxy(7,13);
	cputs("It is not Public Domain.  It was completely written in Turbo C ++ for");
	gotoxy(7,14);
	cputs("dos.  All of the menu, text box, and dialog box routines are my own.");
	gotoxy(7,15);
	cputs("There are only text Graphics, in this version, so it will run on any");
	gotoxy(7,16);
	cputs("machine.  The Windows 95 version will be a graphic and sound wonder.");
	gotoxy(7,17);
	cputs("If you have any comments, I can be reached as JFULTON500@AOL.COM.");
	strcpy(menu[10].item[0],"FIRST PAGE");
	choice = menu_ins_2();
	strcpy(menu[10].item[0],"NEXT PAGE");
	if (choice == 2)
		{show_ins_4();}
	if (choice == 3)
		{return;}
	if (choice == 1)
		{show_ins_1();}

	return;



	}

void end_of_game_1(void)
	{
	int choice,total,upper,lower, ctr,leave,ctr1,ctr2,temp1,temp2;
	int higharr[6];
	float totalf,upperf,lowerf;
	FILE *fptr;


	upper = get_uppertotal();
	lower = get_lowertotal();
	total=get_total();
	leave=FALSE;

	totalf = ((float)total/886)*100;
	lowerf = ((float)lower/750)*100;
	upperf = ((float)upper/126)*100;
	score.itemscore[23] = get_bonus();
	game_control.lastgamesc=total;

	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	draw_border(1,1,80,24,WHITE);
	draw_title();
	gotoxy(30,3);
	textcolor(RED);
	cputs("End Of Game Stats");
	textcolor(RED);
	gotoxy(13,5);
	cputs("FINAL SCORE   :");
	textcolor(YELLOW);
	cprintf(" %d",get_total());

	draw_line(2,6,80,GREEN);

	gotoxy(13,7);
	textcolor(CYAN);
	cputs("TOP 6 TOTAL   :");
	textcolor(YELLOW);
	cprintf(" %d",get_uppertotal());
	gotoxy(13,8);
	textcolor(CYAN);
	cputs("BONUS         :");
	textcolor(YELLOW);
	cprintf(" %d",get_bonus());
	gotoxy(13,9);
	textcolor(CYAN);
	cputs("LOWER 15 TOTAL:");
	textcolor(YELLOW);
	cprintf(" %d",get_lowertotal());

	textcolor(RED);
	gotoxy(33,5);
	cputs("  % OF TOTAL SCORE POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",totalf);

	gotoxy(33,7);
	textcolor(CYAN);
	cputs("  % OF TOTAL TOP 6 POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",upperf);
	gotoxy(33,8);
	textcolor(CYAN);
	cputs("  BONUS LEVEL :");
	textcolor(YELLOW);

	switch(get_bonus())
		{
			case(0):{
				cputs("  Level 0 - NO BONUS ");
				break;
				}
			case(30):{
				cputs("  Level 1 - Upper Total > 57");
				break;
				}
			case(35):{
				cputs("  Level 2 - Upper Total > 67");
				break;
				}
			case(40):{
				cputs("  Level 3 - Upper Total > 70");
				break;
				}
		} // end switch
	gotoxy(33,9);
	textcolor(CYAN);
	cputs("  % OF TOTAL LOWER POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",lowerf);


	draw_box(10,10,70,18,RED);
	gotoxy(33,10);
	textcolor(WHITE);
	cputs("SCORE CARD");


	for (ctr=0;ctr<21;ctr++)
	{
		write_endscore(sc[ctr].hpos+8,sc[ctr].vpos+7,sc[ctr].name,
		    score.itemscore[ctr]);
	}

	gotoxy(25,19);
	textcolor(YELLOW);
	if(chosen.itemchosen[21]==FALSE)
		{
		strcpy(game_control.wildplay,"NOT USED");
		}
	cputs("Wild play: ");
	textcolor(WHITE);
	cprintf("%s",game_control.wildplay);

	gotoxy(35,23);
	textcolor(GREEN);
	cputs("Press Any Key");
	getch();
	gotoxy(35,23);
	cputs("             ");
	get_screen();

	if (total > highscore[4].total)
	   {
	   strcpy(tbox[9].item[0],
		"You have achieved, Dice-Man!!!!!!!");
	     if (total > highscore[0].total)
		{
		strcpy (tbox[9].item[0],
		"You are the new KING/QUEEN of ZAMBOOZAL!");
		}
	   text_box(9);
	   put_screen();
	   while (leave == FALSE)
		{
		new_highscore();
		choice=hscinput_menu();
		if (choice == 2)
			{leave=TRUE;}
		}
	   for (ctr=0;ctr<5;ctr++)
		{
		higharr[ctr]=highscore[ctr].total;
		}

	   hightemp.lower = lower;
	   hightemp.upper = upper;
	   hightemp.total = total;
	   strcpy(hightemp.wildplay,game_control.wildplay);
	   for (ctr=0;ctr<24;ctr++)
	    {hightemp.scores[ctr] =score.itemscore[ctr];}
	   // re-write out highscore file
	   fptr = fopen("zamscore.dat","wb");

	     if (hightemp.total> highscore[0].total)
	      {
	      fwrite(&hightemp,sizeof(hightemp),1,fptr);
	      fwrite(&highscore,sizeof(highscore[0]),4,fptr);
	      }
	     else if (hightemp.total >highscore[1].total)
	      {
	      fwrite(&highscore[0],sizeof(highscore[0]),1,fptr);
	      fwrite(&hightemp,sizeof(hightemp),1,fptr);
	      fwrite(&highscore[1],sizeof(highscore[1]),1,fptr);
	      fwrite(&highscore[2],sizeof(highscore[2]),1,fptr);
	      fwrite(&highscore[3],sizeof(highscore[3]),1,fptr);
	      }
	     else if (hightemp.total >highscore[2].total)
	      {
	      fwrite(&highscore[0],sizeof(highscore[0]),1,fptr);
	      fwrite(&highscore[1],sizeof(highscore[1]),1,fptr);
	      fwrite(&hightemp,sizeof(hightemp),1,fptr);
	      fwrite(&highscore[2],sizeof(highscore[2]),1,fptr);
	      fwrite(&highscore[3],sizeof(highscore[3]),1,fptr);
	      }
	     else if (hightemp.total >highscore[3].total)
	      {
	      fwrite(&highscore[0],sizeof(highscore[0]),1,fptr);
	      fwrite(&highscore[1],sizeof(highscore[1]),1,fptr);
	      fwrite(&highscore[2],sizeof(highscore[2]),1,fptr);
	      fwrite(&hightemp,sizeof(hightemp),1,fptr);
	      fwrite(&highscore[3],sizeof(highscore[3]),1,fptr);
	      }
	     else if (hightemp.total >highscore[4].total)
	      {
	      fwrite(&highscore,sizeof(highscore[0]),4,fptr);
	      fwrite(&hightemp,sizeof(hightemp),1,fptr);
	      }

	  fclose(fptr);
	  }// end of highscore section

	put_screen();

	gotoxy(25,23);
	textbackground(BLACK);
	textcolor(GREEN);
	cputs("Press Any Key for High Score Table");
	getch();
	return;
	}



 void write_endscore(int x,int y, char name[15],int score)
	{

	textcolor(GREEN);

	if ((x==26) && (y==18))
		{
		gotoxy(11,17);
		cprintf("Full House:");
		x=1; //  to get score column %2d
		}

	else
		{
		gotoxy(x,y);
		cprintf("%s",name);
		}
	textcolor(YELLOW);
	if (x<17)
		{cprintf("%2d",score);}
	else
		{cprintf("%3d",score);}

	return;
	}

void high_score_table(void)
	{
	int choice;
	float totalf;
	read_hsfile();

	window(1,1,80,25);
	textbackground(RED);
	clrscr();
	draw_border(1,1,80,24,YELLOW);
	draw_title();
	textcolor(CYAN);
	gotoxy(32,3);
	cputs("HIGH SCORES");
	gotoxy(28,4);
	textcolor(BLACK);
	cputs("***THE KING/QUEEN***");
	gotoxy(35,5);
	textcolor(WHITE);
	cputs(highscore[0].name);
	textcolor(YELLOW);
	gotoxy(21,6);
	cputs("SCORED");
	textcolor(WHITE);
	gotoxy(29,6);
	cprintf("%d",highscore[0].total);
	textcolor(YELLOW);
	gotoxy(33,6);
	cprintf("POINTS ON");
	textcolor(WHITE);
	gotoxy(43,6);
	cputs(highscore[0].date);
	totalf = ((float)highscore[0].total/886)*100;
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points.",totalf);
	gotoxy(21,7);
	textcolor(LIGHTGRAY);
	cprintf("\"%s\"",highscore[0].slogan);
	draw_line(2,8,80,YELLOW);
	gotoxy(5,9);
	textcolor(CYAN);
	cputs("#2");
	cprintf(" %s >> ",highscore[1].name);
	cprintf(" %d Points.",highscore[1].total);
	cprintf("   DATE:%s",highscore[1].date);
	totalf = ((float)highscore[1].total/886)*100;
	gotoxy(52,9);
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points.",totalf);


	gotoxy(5,10);
	textcolor(CYAN);
	cputs("#3");
	cprintf(" %s >> ",highscore[2].name);
	cprintf(" %d Points.",highscore[2].total);
	cprintf("   DATE:%s",highscore[2].date);
	totalf = ((float)highscore[2].total/886)*100;
	gotoxy(52,10);
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points",totalf);

	gotoxy(5,11);
	textcolor(YELLOW);
	cputs("#4");
	cprintf(" %s >> ",highscore[3].name);
	cprintf(" %d Points.",highscore[3].total);
	cprintf("   DATE:%s",highscore[3].date);
	totalf = ((float)highscore[3].total/886)*100;
	gotoxy(52,11);
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points.",totalf);

	gotoxy(5,12);
	textcolor(YELLOW);
	cputs("#5");
	cprintf(" %s >> ",highscore[4].name);
	cprintf(" %d Points.",highscore[4].total);
	cprintf("   DATE:%s",highscore[4].date);
	totalf = ((float)highscore[4].total/886)*100;
	gotoxy(52,12);
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points.",totalf);

	textcolor(WHITE);
	gotoxy(5,13);
	cputs("The most recent finished game's score was: ");
	textcolor(YELLOW);
	cprintf("%d",game_control.lastgamesc);
	totalf = ((float)game_control.lastgamesc/886)*100;
	gotoxy(52,13);
	textcolor(BLACK);
	cprintf("  %.0f% Of Possible Points.",totalf);

	choice = menu_highscore();
	if ((choice >=1) &&(choice <6))
		{
		display_history(choice-1);
		}

	return;
	}

void new_highscore(void)
	{
	char *ptr;
	char namebuf[15],datebuf[15],sloganbuf[60];
	int higharr[6],c;

	window(1,1,80,20);
	textbackground(GREEN);
	clrscr();
	window(1,1,80,21);
	draw_border(1,1,80,20,BLACK);

	textcolor(WHITE);
	gotoxy(25,1);
	cputs("NEW HIGH SCORE DATA");
	textcolor(YELLOW);
	gotoxy(2,2);
	cputs("Enter Your Name: ");
	textcolor(RED);
	namebuf[0]=11;
	ptr=cgets(namebuf);
	strcpy(namebuf,ptr);

	gotoxy(2,3);
	textcolor(YELLOW);
	cputs("Enter the date (dd/mm/yy):");
	textcolor(RED);
	datebuf[0]=9;
	ptr=cgets(datebuf);
	strcpy(datebuf,ptr);

	gotoxy(2,4);
	textcolor(YELLOW);
	cputs("Enter Your Slogan: ");
	sloganbuf[0]=51;
	textcolor(RED);
	ptr=cgets(sloganbuf);
	strcpy(sloganbuf,ptr);

	textcolor(WHITE);
	gotoxy(2,5);
	cputs("YOU ENTERED:");
	textcolor(RED);
	gotoxy(2,6);
	cputs(namebuf);

	gotoxy(2,7);
	cputs(datebuf);

	gotoxy(2,8);
	cputs(sloganbuf);

	strcpy(hightemp.slogan,sloganbuf);
	strcpy(hightemp.date,datebuf);
	strcpy(hightemp.name,namebuf);



	}
void read_hsfile(void)
	{
	int c;//counter
	int upper;
	int lower;
	int total;
	char wildplay[15];
	char name [11];
	char slogan[51];
	char date[9];
	int scores[24];

	FILE *fptr;

	if( (fptr = fopen("zamscore.dat","rb"))==NULL)
	 {
	  fptr=fopen("zamscore.dat","wb");
	  hightemp.upper = 0;
	  hightemp.lower = 0;
	  hightemp.total = 25;
	  strcpy(hightemp.wildplay,"None");
	  strcpy(hightemp.name,"Jeff");
	  strcpy(hightemp.slogan,"Who do you love?");
	  strcpy(hightemp.date,"10/05/95");
	  for (c=0;c<24;c++)
	      {
	      hightemp.scores[c] = 0;
	      }
	 fwrite(&hightemp,sizeof(hightemp),1,fptr);
	 hightemp.total = 20;
	 fwrite(&hightemp,sizeof(hightemp),1,fptr);
	 hightemp.total = 15;
	 fwrite(&hightemp,sizeof(hightemp),1,fptr);
	 hightemp.total = 10;
	 fwrite(&hightemp,sizeof(hightemp),1,fptr);
	 hightemp.total = 5;
	 fwrite(&hightemp,sizeof(hightemp),1,fptr);
	 fclose(fptr);
	 fptr=fopen("zamscore.dat","rb");
	 }
	 fread(&highscore,sizeof(highscore[0]),5,fptr);
	 fclose(fptr);

	}

void display_history(int choice)
	{
	int total,upper,lower, ctr,leave,ctr1,ctr2,temp1,temp2;
	int higharr[6];
	float totalf,upperf,lowerf;

	upper = highscore[choice].upper;
	lower = highscore[choice].lower;
	total= highscore[choice].total;
	leave=FALSE;

	totalf = ((float)highscore[choice].total/886)*100;
	lowerf = ((float)highscore[choice].lower/750)*100;
	upperf = ((float)highscore[choice].upper/126)*100;


	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	draw_border(1,1,80,24,YELLOW);
	draw_title();
	gotoxy(32,3);
	textcolor(RED);
	cputs("HISTORICAL STATS");
	textcolor(YELLOW);
	gotoxy(15,4);
	cputs("NAME: ");
	textcolor(CYAN);
	cputs(highscore[choice].name);
	gotoxy(50,4);
	textcolor(YELLOW);
	cputs("DATE: ");
	textcolor(CYAN);
	cputs(highscore[choice].date);

	textcolor(RED);
	gotoxy(13,5);
	cputs("FINAL SCORE   :");
	textcolor(YELLOW);
	cprintf(" %d",total);

	draw_line(2,6,80,GREEN);

	gotoxy(13,7);
	textcolor(CYAN);
	cputs("TOP 6 TOTAL   :");
	textcolor(YELLOW);
	cprintf(" %d",upper);
	gotoxy(13,8);
	textcolor(CYAN);
	cputs("BONUS         :");
	textcolor(YELLOW);
	cprintf(" %d",highscore[choice].scores[23]);
	gotoxy(13,9);
	textcolor(CYAN);
	cputs("LOWER 15 TOTAL:");
	textcolor(YELLOW);
	cprintf(" %d",lower);

	textcolor(RED);
	gotoxy(33,5);
	cputs("  % OF TOTAL SCORE POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",totalf);

	gotoxy(33,7);
	textcolor(CYAN);
	cputs("  % OF TOTAL TOP 6 POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",upperf);
	gotoxy(33,8);
	textcolor(CYAN);
	cputs("  BONUS LEVEL :");
	textcolor(YELLOW);

	switch(highscore[choice].scores[23])
		{
			case(0):{
				cputs("  Level 0 - NO BONUS ");
				break;
				}
			case(30):{
				cputs("  Level 1 - Upper Total > 57");
				break;
				}
			case(35):{
				cputs("  Level 2 - Upper Total > 67");
				break;
				}
			case(40):{
				cputs("  Level 3 - Upper Total > 70");
				break;
				}
		} // end switch
	gotoxy(33,9);
	textcolor(CYAN);
	cputs("  % OF TOTAL LOWER POSSIBLE :");
	textcolor(YELLOW);
	cprintf("  %.0f%",lowerf);


	draw_box(10,10,70,18,RED);
	gotoxy(33,10);
	textcolor(WHITE);
	cputs("SCORE CARD");


	for (ctr=0;ctr<21;ctr++)
	{
		write_endscore(sc[ctr].hpos+8,sc[ctr].vpos+7,sc[ctr].name,
		    highscore[choice].scores[ctr]);
	}

	gotoxy(25,19);
	textcolor(YELLOW);
	cputs("Wild play: ");
	textcolor(WHITE);
	cprintf("%s",highscore[choice].wildplay);
	gotoxy(5,21);
	textcolor(YELLOW);
	cputs("SLOGAN: ");
	textcolor(GREEN);
	cputs(highscore[choice].slogan);

	gotoxy(35,23);
	textcolor(GREEN);
	cputs("Press Any Key");
	getch();
	high_score_table();
	}

void fire_works(void)
	{
	char c;
	int ctr1,ctr2,ctr3;

	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	draw_border(1,1,80,24,YELLOW);
	draw_title();
	c='\x7f';
	gotoxy(3,24);
	cprintf("%c",c);

	getch();

	}
void title_screen(void)
	{

	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	draw_border(1,1,80,24,YELLOW);
	draw_title();
	gotoxy(30,7);
	textcolor(WHITE);
	cputs(" By Jeff Fulton");
	gotoxy(35,8);
	textcolor(CYAN);
	cputs("(c)1995");

	textcolor(YELLOW);
	gotoxy(32,20);
	cputs("Press Any Key");

	getch();
	}