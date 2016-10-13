//function.h for advance english dictionary
//authour -Divesh Uttamchandani

#define ESC 27          //define escape key

/***********************Declaration Of Functions***************************/
int my_strcmpi(char *userword,char *indexword);
void search();                                        //gets word from user and serches for it and calls disp def
unsigned int search(char *&A);          //search funtion overloaded this searches for A and returns its wordno
void disp_def(unsigned int wordno);     //displays defination

void add();                                             //add a word to the dictionary

void abbreviations();                               //display list of abbreviations

void how_to_use();                                //displays how to use the dictionary
/*************************************************************************/


/************************Defination Of Functions**************************/
///////////////////////////////////////////////////////////////////////////////////////////////
//function that matches userword and indexword
int my_strcmpi(char *userword,char *indexword)
{
 //////////correct A/////////
 if(indexword[0]=='-'||indexword[0]=='\'')
 indexword++;
 if(indexword[0]=='-'||indexword[0]=='\'')
 indexword++;
 ////////////////////////////
 int s=strlen(userword);
 return strncmpi(userword,indexword,s);
}
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
//function to display defination
void disp_def(unsigned int wordno)
{
 OUTPUTWINDOW;
 clrscr();
 long long unsigned int t;
 defination d;

 ifstream fin(DEFINATION,ios::binary);

 if(!fin)
 {
	cout<<"error";
	getch();
 }
 else
 {
  fin.seekg(0);
  t=(wordno-1)*(long long unsigned)(sizeof(d));
  fin.seekg(t,ios::beg);
  fin.read((char*)&d,sizeof(d));
  d.display();
 }
 getch();
 fin.close();
}
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
//function to search a word
void search()
{
  char *A,*B;
  unsigned int wlist[20];
  int i=1,n,temp;

  clrscr();

 PARTITION;
  clrscr();
  for(temp=1;temp<=25;temp++)
  {
    putch('|');
  }
  //Input Word From User
  INPUTHEADER;
  puts("------------------Input Window------------------");

  OUTPUTHEADER;
  clrscr();
  puts("-------------------Defination-------------------");

  //Search Results
  WORDHEADER;
  puts("---------Search Results--------");

  USERHEADER;
  puts("----------Note To User----------");

  USERNOTE;
  clrscr();
  puts("Press Any Key To Scroll");
  putch(13);
  puts("Press (Enter) to select list");

  INPUTWINDOW;
  textattr(1+128);
  txtbkcolor;
  clrscr();
  puts("Enter Word to be Searched for:");
  gets(A);
  msgcolor;
  clrscr();
  puts("Enter Word to be Searched for:");
  putch(13);
  puts(A);

  ifstream fin(INDEX,ios::binary);

  if(!fin)
  {
  cout<<"error";
  getch();
  }
  else
  {
  fin.seekg(0);
  index_word I;
  WORDLISTWINDOW;
   clrscr();

   puts("   ");
   putch(13);
   cout<<"Searching...";

   while(fin.read((char*)&I,sizeof(I)))
    {
    B=I.getword();

    if(my_strcmpi(A,B)==0)
      {
	//20 words at a time
	if(i==1)
	clrscr();
	  if(i>20)
	  {
	  char ch;
	  ch=getch();

	   if(ch==13)
	    break;
	   else
	   {
	   clrscr();
	   i=1;
	   }
      }

    wlist[i-1]=I.retno();

	//Truncate long words
	if(strlen(B)>23)
	{
	B[20]=B[21]=B[22]='.';
	B[23]='\0';
	}

	printf(" %d)\t",i);
	puts(B);
	if(i<20)
	putch(13);

	   i++;
      }
    }

  if(i>1)
  {
    USERNOTE;
    clrscr();

    INPUTWINDOW;
    do
    {
	textattr(1+128);
	txtbkcolor;
	clrscr();
	puts("Enter Choice(Word No.)");
	putch(13);
	cin>>n;

	msgcolor;
	clrscr();
	puts("Enter Choice(Word No.)");
	putch(13);
	printf("%d",n);

	if(!(n>=1 && n<=i-1))
	{
	textattr(1+128);
	txtbkcolor;
	clrscr();
	cout<<"Invalid! Enter Again!";
	getch();
	}
    }while(!(n>=1 && n<=i-1));

  OUTPUTWINDOW;
  disp_def(wlist[n-1]);
  }

  else
   {
   WORDLISTWINDOW;
   clrscr();
   cout<<"No Match Found";
   getch();
   }
  }
   fin.close();
}
///////////////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////////
//search function overloaded
unsigned int search(char *&A)
{
  char *B;
  unsigned int wlist[20];
  char *lwlist[20];
  int i=1,n,temp,flag=1;

  clrscr();

 PARTITION;
  clrscr();
  for(temp=1;temp<=25;temp++)
  {
    putch('|');
  }
  INPUTHEADER;
  puts("------------------Input Window------------------");

  OUTPUTHEADER;
  clrscr();
  puts("-------------------Defination-------------------");

  //Search Results
  WORDHEADER;
  puts("---------Search Results--------");

  USERHEADER;
  puts("----------Note To User----------");

  USERNOTE;
  clrscr();
  puts("Press Any Key To Scroll");
  putch(13);
  puts("Press (Enter) to select list");

  INPUTWINDOW;
  puts("Enter Word to be Searched for:");
  putch(13);
  puts(A);

  ifstream fin(INDEX,ios::binary);

  if(!fin)
  {
    cout<<"error";
    getch();
  }

  else
  {
  fin.seekg(0);
  index_word I;
  WORDLISTWINDOW;
   clrscr();

   puts("   ");
   putch(13);
   cout<<"Searching...";

   while(fin.read((char*)&I,sizeof(I)))
    {
    B=I.getword();

    if(my_strcmpi(A,B)==0)
      {
	//20 words at a time
	if(i==1)
	clrscr();
	  if(i>20)
	  {
	  char ch;
	  ch=getch();

	   if(ch==13)
	    break;
	   else
	   {
	   clrscr();
	   i=1;
	   }
      }

    wlist[i-1]=I.retno();
    strcpy(lwlist[i-1],I.getword());

	//Truncate long words
	if(strlen(B)>23)
	{
	B[20]=B[21]=B[22]='.';
	B[23]='\0';
	}

	printf(" %d)\t",i);
	puts(B);
	if(i<20)
	putch(13);

	   i++;
      }
    }

  if(i>1)
  {
    USERNOTE;
    clrscr();

    INPUTWINDOW;
    do
    {
	textattr(1+128);
	txtbkcolor;
	clrscr();
	puts("Enter Choice(Word No.)");
	putch(13);
	cin>>n;

	msgcolor;
	clrscr();
	puts("Enter Choice(Word No.)");
	putch(13);
	printf("%d",n);

	if(!(n>=1 && n<=i-1))
	{
	textattr(1+128);
	txtbkcolor;
	clrscr();
	cout<<"Invalid! Press Any Key To Enter Again!";
	cout<<"\nPress Esc to Exit";
	char ch=getch();
	if(ch==ESC)
	 {
	 txtbkcolor;
	 msgcolor;
	 clrscr();
	 flag=0;
	 break;
	 }
	}
    }while(!(n>=1 && n<=i-1));
   fin.close();

  OUTPUTWINDOW;
if(flag)
{
  disp_def(wlist[n-1]);
  strcpy(A,lwlist[n-1]);
  return wlist[n-1];
}

else
    return 0;
  }

  else
   {
   WORDLISTWINDOW;
   clrscr();
   cout<<"No Match Found";
   getch();
   return 0;
   }
  }
}
////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
//function to add a word
void add()
{
 char *w,*linked_w,*def;

 w=new char[WORDMAX];
 linked_w=new char[WORDMAX];
 def=new char[DEFMAX];

 unsigned int code=0;
 int flag=0;

 index_word I;
 defination D;

 cout<<"Add A Word To The Dictionary\n";
 cout<<"\nEnter Word\t";
 gets(w);

 cout<<"\nDo You Want To Link It To An Already Existing Word?\t(Y/N)\t";

 char ch;
 ch=getche();

 if(toupper(ch)=='Y')
 {
 cout<<"\n\nEnter Linked Word\t";
 gets(linked_w);
 cout<<"\nNow You Are Being Redirected To The Search Window...";
 cout<<"\nPress Any Key";
 getch();
 code=search(linked_w);

 FULLSCREEN;
 clrscr();
 }

 if(code==0)
 {
 clrscr();
 cout<<"\nYou didn't Link It To A Word";
 cout<<"\n\nEnter Defination Of The Word\n";
 cout<<"\nPress Any Key To Continue\nPress Esc To Exit\t";
 char ch=getch();

  if(ch==ESC)
  {
  clrscr();
  cout<<"Word Not Added!!!!!!!\nPress Any Key\t";
  getch();
  return;
  }

  else
  {
  cout<<"\nEnter Defination\n";
  gets(def);
  flag=1;

  ifstream fin(INDEX,ios::binary);
  if(!fin)
  {
    cout<<"Error";  getch();
  }
  else
   {
   fin.seekg(-(int)(sizeof(I)),ios::end);
   fin.read((char*)&I,sizeof(I));
   code=I.retno();
   ++code;
   strcpy(linked_w,w);
   }
    fin.close();
  }
 }

  FULLSCREEN;
  clrscr();

  cout<<"\nWord Added";

  //copy the word to index
  I.add(w,linked_w,code);

  ofstream ind(INDEX,ios::binary|ios::app);
  if(ind)
   {
   ind.write((char*)&I,(int)sizeof(I));
   ind.close();
   I.display();
   }
  else
  {
   cout<<"Error";
   getch();
  }

  if(flag==1) 	//then add to defination also
  {
  D.add(code,w,def);
  ofstream def(DEFINATION,ios::binary|ios::app);
  if(def)
   {
   def.write((char*)&D,(int)sizeof(D));
   def.close();
   //cout<<"\n";
   //D.display();
   }
  else
    {
      cout<<"Error";
      getch();
    }
  }

  getch();
  delete w;
  delete linked_w;
  delete def;
}
////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
//Function to print abbreviations
void abbreviations()
{
ifstream fin(ABBREVIATIONS);
if(!fin)
cout<<"Error";

else
 {
 cout<<"Abbreviations Used In Dictionary\n\n";
 fin.seekg(0);
 char ch;
  while(fin.get(ch))
   {
   cout<<ch;
    if(wherey()==24)
     {
     cout<<"\nPress Any Key To Scroll";
     getch();
     clrscr();
     cout<<"Abbreviations Used In Dictionary\n\n";
     }
   }
 cout<<"\n\nPress Any Key";
 getch();
 fin.close();
 }
}
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////
//print hoe to use the dictionary
void how_to_use()
{
ifstream fin(HOWTOUSE);

if(!fin)
cout<<"Error";

else
 {
 cout<<"Organization of The Dictionary\n\n";
 fin.seekg(0);
 char ch;
  while(fin.get(ch))
   {
   cout<<ch;
    if(ch=='\n')
     {
     fin.get(ch);
     if(ch=='\n')
      {
      cout<<"\n\nPress Any Key To Scroll";
      getch();
      clrscr();
      cout<<"Organization of The Dictionary\n\n";
      }
     else
     cout<<ch;
     }
   }
 cout<<"\n\nPress Any Key";
 getch();
 fin.close();
 }
}
///////////////////////////////////////////////////////////////////////////////////////////////
/**************************************************************************/
