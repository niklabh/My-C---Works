/*=========================================================*/
/*=================== CLOCK PROGRAM ====================== */
/*=============PROGRAMMER: NIKHIL RANJAN
			      B.TECH(IT)
			     GGSIPU USIT===================*/
/*=========================================================*/
/*==================RELEASE NOTES==========================*/
/*  To change clock position,size and speed only change #define
    values.Inner integer values shoild be edited with caution.
    It is wise to keep backup before editing.For queries and
    help contact me:

    mail :niklabh811@gmail.com
    phone:9013557139
							   */
/*=========================================================*/
#include<time.h>
#include<graphics.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<process.h>

#define X 300.0      //X CENTER OF CLOCK
#define Y 200.0      //Y CENTER OF CLOCK
#define S 100.0      //SIZE OF CLOCK
#define D 1000       //TIME DELAY 1000==1 SECOND

void hour_hand(int);
void min_hand(int);
void sec_hand(int);

int xm,ym,xh,yh;
time_t timer;
struct tm *tblock;

void main()
{
    int driver = DETECT,mode = DETECT;
    initgraph(&driver,&mode,"c:\\tc\\bgi");
    int s,m,h,mh,hh;
    int x,y;
    char ch[3];

   //to draw the circles and numbers
    setcolor(RED);
    circle(X,Y,S+5);
    setcolor(GREEN);
    circle(X,Y,S+50);
    circle(X,Y,S+60);
    circle(X,Y,S+55);

    float th,pi=22.0/7.0,deg;
    for(int i1=0;i1<12;i1++)
    {
    deg=(float(i1)*30.0)-90.0;
    th=(pi*(deg/180.0));
    x=int((X)+(S+30)*cos(th));
    y=int((Y)+(S+30)*sin(th));
    setcolor(YELLOW);
    switch(i1)
    {
     case 0: strcpy(ch,"12");break;
     case 1: strcpy(ch,"1"); break;
     case 2: strcpy(ch,"2"); break;
     case 3: strcpy(ch,"3"); break;
     case 4: strcpy(ch,"4"); break;
     case 5: strcpy(ch,"5"); break;
     case 6: strcpy(ch,"6"); break;
     case 7: strcpy(ch,"7"); break;
     case 8: strcpy(ch,"8"); break;
     case 9: strcpy(ch,"9"); break;
     case 10:strcpy(ch,"10"); break;
     case 11:strcpy(ch,"11"); break;
    }
    outtextxy(x,y,ch);
    }


    //main clock logic
    time(&timer);
    tblock=localtime(&timer);

    s=tblock->tm_sec;               //time is initialised with system time
    m=tblock->tm_min;

    if(tblock->tm_hour>12)
    hh=tblock->tm_hour-12;
    else
    hh=tblock->tm_hour;

    h=hh*5;

    if(tblock->tm_min<12)
    {
    mh=tblock->tm_min;
    }
    else if(tblock->tm_min>12&&tblock->tm_min<=24)
    {
    mh=tblock->tm_min-12;
    h=h+1;
    }
    else if(tblock->tm_min>24&&tblock->tm_min<=36)
    {
    mh=tblock->tm_min-24;
    h=h+2;
    }
    else if(tblock->tm_min>36&&tblock->tm_min<=48)
    {
    mh=tblock->tm_min-36;
    h=h+3;
    }
    else if(tblock->tm_min>48)
    {
    mh=tblock->tm_min-48;
    h=h+4;
    }

    while(1)                        //looks like infinite loop
    {                               //but ends at keyboard hit by use of
				    //kbhit() in sec_hand()
     sec_hand(s);s++;

     if(s>=60)
     {
      m++;
      mh++;
      s=0;
     }

     if(m>=60)
     m=0;

     if(mh>=12)
     {
      h++;
      mh=0;
     }

     if(h>=60)
     h=0;

    setcolor(BLACK); line(X,Y,xm,ym); min_hand(m);
    setcolor(BLACK); line(X,Y,xh,yh); hour_hand(h);

    }

}

void sec_hand(int i)
{
     time(&timer);
     tblock=localtime(&timer);
     setcolor(RED);
     outtextxy(200,20,asctime(tblock));

    int x,y;
    float th,pi=22.0/7.0,deg;
    deg=(float(i)*6.0)-90.0;
    th=(pi*(deg/180.0));
    x=int(X+(S-10)*cos(th));
    y=int(Y+(S-10)*sin(th));
    setcolor(LIGHTBLUE);
    line(X,Y,x,y);
    delay(D);       //THE DRIVING FORCE DELAY 1000 ms =1 SECOND

    //this is to delete previously drawn hand
    //this is main logic behind graphics movement
    //programmer can use getbkcolor() instead of BLACK

    setcolor(BLACK);
    line(X,Y,x,y);
    outtextxy(200,20,asctime(tblock));
    if(kbhit())             //program end on keyboard hit
    {
    closegraph();
    exit(0);
    }

}
void min_hand(int j)
{                                                //drawing the hands
    float deg1,th1,pi;
    int x1,y1,x,y;
    pi=22.0/7.0;
    deg1=(float(j)*6.0)-90.0;
    th1=(pi*(deg1/180.0));
    x1=int(X+(S-20)*cos(th1));
    y1=int(Y+(S-20)*sin(th1));
    xm=x1;ym=y1;
    setcolor(RED);
    line(X,Y,x1,y1);
}
void hour_hand(int j)
{
    float deg1,th1,pi;
    int x1,y1;
    pi=22.0/7.0;
    deg1=(float(j)*6.0)-90.0;
    th1=(pi*(deg1/180.0));
    x1=int(X+(S-30)*cos(th1));
    y1=int(Y+(S-30)*sin(th1));
    xh=x1;yh=y1;
    setcolor(YELLOW);
    line(X,Y,x1,y1);
}
