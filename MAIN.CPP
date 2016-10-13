/***************************************************************************/
/********************  Name    :-Divesh Uttamchandani   ********************/
/********************  Class   :-XII  A                 ********************/
/********************  Session :-2014-2015              ********************/
/***************************************************************************/
/********************      Computer Science Project    *********************/
/********************     Advance English Dictionary   *********************/
/***************************************************************************/


/*********************** Give Path of the Files Here ***********************/
#define bgi_loc		"g:/bgi"
#define my_graphics	"g:/cs/project/XII/include/graph.h"
#define fonts_styles	"g:/cs/project/XII/include/styles.h"
#define classes		"g:/cs/project/XII/include/classes.cpp"
#define functions	"g:/cs/project/XII/include/function.h"

#define INDEX		"g:/cs/project/XII/files/m_index.dic"
#define DEFINATION	"g:/cs/project/XII/files/m_def.dic"
#define ABBREVIATIONS	"g:/cs/project/XII/files/abbr.txt"
#define HOWTOUSE	"g:/cs/project/XII/files/use.txt"
/***************************************************************************/

////////////////Variable To Avoid Blinking For The First Time////////////////
int no_of_times=0;
/////////////////////////////////////////////////////////////////////////////

////////////////////////// Including Header Files ///////////////////////////
#include <fstream.h>
#include <ctype.h>
#include <conio.h>
#include <graphics.h>
#include <process.h>
#include <dos.h>
#include <string.h>
#include <stdio.h>
#include classes
#include fonts_styles
#include my_graphics
#include functions
/////////////////////////////////////////////////////////////////////////////

//******************************Void Main()********************************//
void main()
{
 intro();
 erase_name();

 do
 {
  int choice=0;
  main_menu(choice);//gets the choice from the user
		    //1)Search A Word
		    //2)Add A Word
		    //3)Abbreviations
		    //4)How To Use
		    //5)Exit
  FULLSCREEN;
  txtbkcolor;
  msgcolor;
  clrscr();

  switch(choice)
  {
   case 1: search();
	 break;

   case 2: add();
	 break;

   case 3: abbreviations();
	 break;

   case 4: how_to_use();
	 break;

   case 5: break;
   }

  if(choice==5)
  break;


  FULLSCREEN;    //clear all the screens
  clrscr();

  cout<<"\n\n\n\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t     Press Y to Continue "<<char(174)<<"-";
  cout<<"\n\t\t\t Press Any Other Key To Exit -"<<char(175);
  no_of_times++;
  }while(toupper(getche())=='Y');

end();
}
//*******************************End Of Main*******************************//
