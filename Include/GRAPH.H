//Graph.h for advance english dictionary
//authour -Divesh Uttamchandani

//Defining Co-ordinates Of mid points
#define xmax getmaxx()
#define ymax getmaxy()
#define midx xmax/2
#define midy ymax/2

/**************************************************************************/
/***********************Declaration Of Functions***************************/
/**************************************************************************/
//////////////////////////funtion to initialize graphics/////////////////////////////
void graphics_initialize();
////////////////////Functions For Introduction Animation///////////////////
void intro();
    void erase_name();
///////////////////////////////////////////////////////////////////////////


//////////////Functions For Printing Menu And Getting Choice///////////////
void main_menu(int &choice);
    void print_menu();
    int get_choice();
///////////////////////////////////////////////////////////////////////////


/////////////////////Function For End Thanks Animation/////////////////////
void end();
///////////////////////////////////////////////////////////////////////////


//////////////Function Which Helps In Key Controlled Delay/////////////////
void mydelay(int time, int &flag);
///////////////////////////////////////////////////////////////////////////
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/



/*************************************************************************/
/************************Defination Of Functions**************************/
/*************************************************************************/

void graphics_initialize()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, bgi_loc);

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      cout<<"Graphics error: %s\n"<<grapherrormsg(errorcode);
      cout<<"Press any key to halt:";
      getch();
      exit(1);
   }

   bkcolor;
}

//the function prints topic and my name.
//it uses kbhit for pausing and skipping the animation
//if user presses any key (exept enter) it gets into the statement if(kbhit)
//and than getch(). to mimic pause play
//it breaks out of the animation loop if user presses enter
void intro()
{
   graphics_initialize();
   int x = xmax;
   int y = ymax;
   int i,j;

   for(i=x, j=0; i>40; i--,j++)
   {
    delay(20);

    erasercolor;
    bar(x,y,0,0);

    topicstyle;
    topiccolor;
    outtextxy(i,10,"Advance English Dictionary");

    if(j<=200)
     {
      namestyle;
      namecolor_intro;
      outtextxy(j,350,"Made By :-Divesh Uttamchandani");
      outtextxy(j,400,"Class     :-XII -A");

      th_style;
      outtextxy(j+179,397,"th");
     }

    if(j>=200)
    {
    y=80;
    }

    if(kbhit()!=0)
    {
	 if(getch()==13)
		 break;
	 else
		 getch();
    }
}
   cleardevice();
   topicstyle;
   topiccolor;
   outtextxy(40,10,"Advance English Dictionary");


   namestyle;
   namecolor_intro;
   outtextxy(200,350,"Made By :-Divesh Uttamchandani");
   outtextxy(200,400,"Class     :-XII -A");

   th_style;
   outtextxy(200+179,397,"th");
   delay(500);
}



//it erases my name from the screen
//skips animation if any key is pressed using my delay
void erase_name()
{
   //graphics initialized in intro

   int flag=0;		//for mydelay
   mydelay(500,flag);

   erasercolor;
   for(int i=195;i<=xmax;i++)
   {
   bar(0,300,i,ymax);
   mydelay(5,flag);
   }
   cleardevice();
  // closegraph(); //transfered to main menu
}


//it prints the main menu. and gets choice from the user using
//functions print_menu() and get_choice()
//NOTE:-graphics are initialized in this function only if the user is
//coming back to this menu 2nd and later times
//else the graphics are brought forward from intro.
//(As i Don't Want The Screen To Blink due to closegraph)
//for the above purpose it uses global variable no_of_times
void main_menu(int &choice)
{
   if(no_of_times>=1)      //As i Don't Want The Screen To Blink due to
   graphics_initialize();			   	   //closegraph


   topicstyle;
   topiccolor;
   outtextxy(40,10,"Advance English Dictionary");

   print_menu();

   choice=get_choice();

   cleardevice();
   closegraph();
}


//the function prints the menu
void print_menu()
{
int flag=0; 	//for mydelay

mydelay(500,flag);

mainmenustyle;
mainmenucolor;
outtextxy(250,120,"Main Menu");

mydelay(700,flag);

optionsstyle;
optionscolor;

outtextxy(230,180,"1) Search A Word");

mydelay(700,flag);
outtextxy(230,220,"2) Add A Word");

mydelay(700,flag);
outtextxy(230,260,"3) Abbreviations");

mydelay(700,flag);
outtextxy(230,300,"4) How To Use");

mydelay(700,flag);
outtextxy(230,340,"5) Exit");


menumsgcolor;
menumsgstyle;
delay(20);
outtextxy(140,410,"Use Arrow Keys To Move The Selection");

delay(20);
outtextxy(220,440,"Press \'Enter\' To Enter");
}


//function helps in getting user's choice using arrow keys
//it draws and changes the selection box(rectangle) at required position.
//it returns choice whose value is from 1 to 5
//1) Search A Word
//2) Add A Word
//3) Abbreviations
//4) How to Use
//5) Exit
int get_choice()
{
//grapics inherited from main_menu()
delay(100);
int choice=1;
int y1=180;
int y2=217;
int ch=0;

do
{
choiceboxcolor;
rectangle(200,y1,440,y2);   //print the box

ch=getch();

switch(ch)
	{
	case 72:    //down arrow key
	    erasercolor;
		rectangle(200,y1,440,y2);  //erase the previous rectangle
		y1-=40;
		y2-=40;
		choice--;
		break;

	case 80:   //up arrow key
	    erasercolor;
		rectangle(200,y1,440,y2);  //erase the previous rectangle
		y1+=40;
		y2+=40;
		choice++;
		break;
	}
  if(choice<1) 		//if less than about the program
  {
  y1+=40,y2+=40;       //since y1 & y2 also get decrement in switch by 40
  choice++;
  }

  if(choice>5)          //if greater than exit
  {
  y1-=40,y2-=40;        //since y1 & y2 also get increment in switch by 40
  choice--;
  }
}while(ch!=13);

return choice;
}

//thankyou note similar to intro
void end()
{
   graphics_initialize();

   int x = xmax;
   int y = ymax;

   int i,j;

   for(i=x, j=0; i>210; i--,j++)
   {
    delay(20);

    erasercolor;
    bar(x,y,0,0);

    thanksstyle;
    thankscolor;
    outtextxy(i,100,"Thank You");

    if(j<=100)
     {
      namestyle;
      namecolor_end;
      outtextxy(j,350,"Made By :-Divesh Uttamchandani");
      outtextxy(j,400,"Class     :-XII -A");

      th_style;
      outtextxy(j+179,397,"th");
     }

    if(j>=100)
    {
    y=250;
    }

    if(kbhit()!=0)
    {
	 if(getch()==13)
		 break;
	 else
		 getch();
    }
}
   cleardevice();
   thanksstyle;
   thankscolor;
   outtextxy(210,100,"Thank You");


   namestyle;
   namecolor_end;
   outtextxy(100,350,"Made By :-Divesh Uttamchandani");
   outtextxy(100,400,"Class     :-XII -A");

   th_style;
   outtextxy(100+179,397,"th");
   /* clean up */
   for(i=0;i<3000;i++)
   {
   if( !(kbhit()) )
	delay(1);
   else
	break;
   }

   cleardevice();
   closegraph();
   exit(0);
}

//mydelay function holds responsible for key based delay
//it only delays if parameter flag is 0 i.e no key is pressed untill now
//if key is pressed in b/w it changes the value of flag to 1 (flag is called
//by ref. here)and breaks of the loop
//next time when it is invoked as it changed the value of flag to 1 it doesn't
//enters the loop untill flag given is again turned to 0
void mydelay(int time,int &flag)
{
if(flag==0)
    {
	for(int i=0;i<=time;i++)
	{
	    if(kbhit()!=0)
	    {
		getch();
		flag=1;
		break;
	    }
	    else
		delay(1);
	}
    }
}
/**************************************************************************/
/**************************************************************************/
/**************************************************************************/
