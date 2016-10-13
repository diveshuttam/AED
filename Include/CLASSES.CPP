//classes.cpp for advance english dictionary
//authour -Divesh Uttamchandani
#define WORDMAX        80
#define DEFMAX	       6000

class index_word
{
  char        w[WORDMAX];
  char linked_w[WORDMAX];
  unsigned int wordno;	//wno of the linked word
  public:

  index_word()
  {
      strcpy(w,"NULL");
      strcpy(linked_w,"NULL");
      wordno=0;
  }

  ~index_word()
  {
      ;
  }

  void add(char w1[], char linked_w1[],unsigned int code)
  {
  strcpy(w,w1);
  strcpy(linked_w,linked_w1);
  wordno=code;
  }

  void display()
  {
  cout<<"\n\nWORD\t"<<w;
  cout<<"\nLinked word\t"<<linked_w;
  cout<<"\nCode\t"<<wordno;
  }

  char *getword()
  {
  return w;
  }

  unsigned int retno()
  {
  return wordno;
  }
};

class defination
{
  unsigned int wordno;
  char        w[WORDMAX];
  char	      d[DEFMAX];

  public:
   defination()
  {
      strcpy(w,"NULL");
      strcpy(d,"NULL");
      wordno=0;
  }

  ~defination()
  {
      ;
  }

  void add(unsigned int wno,char *w1,char *d1)
  {
  strcpy(w,w1);
  strcpy(d,d1);
  wordno=wno;
  }

  void display()
  {
  int i=0;
  cout<<"\n";//<<"WORD\t";
  puts(w);
  cout<<"\n";//Defination\n";
  while(d[i]!='\0')
  {
    if(i%45==0 && i!=0)
    {
    if(d[i-1]!=' ' && d[i]!=' ')
    cout<<'-';
    cout<<"\n";
    }

    if(i%(45*15)==0 && i!=0)
    {
        cout<<"\nPress Any Key To Scroll";
        getch();
        clrscr();
    }
    cout<<d[i];
    i++;
  }
  }
};
