//A simple game
//you have to catch the square
//controls
//left: a
//right: d
//up: w
//down: s
//exit : x
//By Nikhil Ranjan
//GGSIPU USIT B.Tech(IT)
#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
void drawob(int,int,int);
void drawob2(int,int);
void drawob3(int,int);
void drawob4(int,int);
void drawob5(int,int);
void drawwelcome();
void dead();
void main()
{
   int X=320;
   int Y=100;
   int s=10;
   int x,y,x1,y1;
   char input;
   randomize();
   int driver = DETECT,mode;
   initgraph(&driver,&mode,"c:\\tc\\bgi");
   drawwelcome();
   cleardevice();
   rectangle(10,10,630,470);
   drawob(X,Y,s);
   x1=10+random(600);
   y1=10+random(400);
   int x2=10+random(600);
   int y2=10+random(400);
   int x3=10+random(600);
   int y3=10+random(400);

   while(1)
   {

      x=10+random(600);
      y=10+random(400);



     while(1)
     {

	  int ran=random(10);
	  if(ran==9||ran==7||ran==5)
	  {
	    x+=5;y+=5;
	  }
	  else if(ran==8||ran==6)
	  {
	    x+=5;y-=5;
	  }
	  else if(ran==7||ran==2||ran==3)
	  {
	    x-=5;y+=5;
	  }
	  else if(ran==1||ran==4)
	  {
	    x-=5;y-=5;
	  }
	  else
	  {
	   x+=5;
	  }
	  setcolor(WHITE);
	  drawob2(x,y);


	  ran=random(10);
	  if(ran==7||ran==5)
	  {
	    x1+=4;y1+=6;
	  }
	  else if(ran==9||ran==8||ran==6)
	  {
	    x1+=5;y1-=3;
	  }
	  else if(ran==7||ran==2||ran==4)
	  {
	    x1-=8;y1+=3;
	  }
	  else if(ran==1||ran==3)
	  {
	    x1-=4;y1-=9;
	  }
	  else
	  {
	   x1+=2;
	  }
	  setcolor(WHITE);
	  drawob3(x1,y1);


	  ran=random(10);
	  if(ran==7||ran==5)
	  {
	    x2+=5;y2+=5;
	  }
	  else if(ran==9||ran==8||ran==6)
	  {
	    x2+=5;y2-=5;
	  }
	  else if(ran==7||ran==2||ran==4)
	  {
	    x2-=3;y2+=8;
	  }
	  else if(ran==1||ran==3)
	  {
	    x2-=6;y2-=7;
	  }
	  else
	  {
	   x2+=5;
	  }
	  setcolor(WHITE);
	  drawob4(x2,y2);


	   ran=random(10);
	  if(ran==7||ran==5||ran==3)
	  {
	    x3+=8;y3+=6;
	  }
	  else if(ran==9||ran==8||ran==6)
	  {
	    x3+=5;y3-=4;
	  }
	  else if(ran==7||ran==2)
	  {
	    x3-=8;y3+=2;
	  }
	  else if(ran==1||ran==4)
	  {
	    x3-=6;y3-=8;
	  }
	  else
	  {
	   x3+=6;
	  }
	  setcolor(WHITE);
	  drawob5(x3,y3);


	  input = getche();
	  switch(input)
	  {
		case 'w':
		setcolor(BLACK);
		drawob(X,Y,s);
		setcolor(WHITE);
		Y=Y-10;
		drawob(X,Y,s);
		break;
		case 'a':
		setcolor(BLACK);
		drawob(X,Y,s);
		setcolor(WHITE);
		X=X-10;
		drawob(X,Y,s);
		break;
		case 's':
		setcolor(BLACK);
		drawob(X,Y,s);
		setcolor(WHITE);
		Y=Y+10;
		drawob(X,Y,s);
		break;
		case 'd':
		setcolor(BLACK);
		drawob(X,Y,s);
		setcolor(WHITE);
		X=X+10;
		drawob(X,Y,s);
		break;
		case 'x':
		exit(0);
		break;
	  }
	  setcolor(BLACK);
	  drawob2(x,y);
	  drawob3(x1,y1);
	  drawob4(x2,y2);
	  drawob5(x3,y3);

     if(X<(x+10)&&X>(x-10)&&Y<(y+10)&&Y>(y-10))
     {
       s++;
       setcolor(BLACK);
       drawob2(x,y);
       drawob3(x1,y1);
       drawob4(x2,y2);
       drawob5(x3,y3);
       setcolor(WHITE);
       drawob(X,Y,s);
       break;
     }

     if(X<(x1+10)&&X>(x1-10)&&Y<(y1+10)&&Y>(y1-10))
     {
       dead();
     }

     if(X<(x2+10)&&X>(x2-10)&&Y<(y2+10)&&Y>(y2-10))
     {
       dead();
     }

     if(X<(x3+10)&&X>(x3-10)&&Y<(y3+10)&&Y>(y3-10))
     {
       dead();
     }

     if(X<10||X>630||Y<10||Y>470)
     dead();
     }
   }
}

void drawob(int x,int y,int size)
{
  for(int i=size;i>5;i--)
  {
      circle(x,y,i);
  }
}
void drawob2(int x,int y)
{
 rectangle(x-5,y-5,x+5,y+5);
}
void drawob3(int x,int y)
{
  line(x,y-5,x-5,y+5) ;
  line(x-5,y+5,x+5,y+5);
  line(x+5,y+5,x,y-5);
  line(x-5,y-3,x+5,y-3);
  line(x-5,y-3,x,y+7);
  line(x,y+7,x+5,y-3);
}

void drawob4(int x,int y)
{
  line(x,y-5,x-5,y+5) ;
  line(x-5,y+5,x+5,y+5);
  line(x+5,y+5,x,y-5);
  line(x-5,y-3,x+5,y-3);
  line(x-5,y-3,x,y+7);
  line(x,y+7,x+5,y-3);
}

void drawob5(int x,int y)
{
  line(x,y-5,x-5,y+5) ;
  line(x-5,y+5,x+5,y+5);
  line(x+5,y+5,x,y-5);
  line(x-5,y-3,x+5,y-3);
  line(x-5,y-3,x,y+7);
  line(x,y+7,x+5,y-3);
}

void drawwelcome()
{
  rectangle(10,10,630,470);
  rectangle(15,15,625,465);
  outtextxy(100,50,"Welcome To EAT & GROW");
  settextstyle(4,0,4);
    setcolor(BLUE);
    outtextxy(30,200,"LOADING");
    setcolor(CYAN);
    rectangle(190,200,620,240);
    for(int i=0;i<442;i++)
    {
     setcolor(YELLOW);
     line(190+i,202,190+i,238);
     delay(5);
    }
  cleardevice();
  rectangle(10,10,630,470);
  gotoxy(25,5);cout<<"controls: ";
  gotoxy(25,6);cout<<"left: a";
  gotoxy(25,7);cout<<"right: d";
  gotoxy(25,8);cout<<"up: w";
  gotoxy(25,9);cout<<"down: s";
  gotoxy(25,10);cout<<"Exit: x";
  gotoxy(25,13);cout<<"EAT square avoid star.";
  gotoxy(25,15);cout<<"Press any key to continue...";
  getch();

}
void dead()
{
    cleardevice();
    setcolor(YELLOW);
    rectangle(10,10,630,470);
    settextstyle(1,0,3);
    outtextxy(200,100,"YOU ARE DEAD");
    getch();
    exit(0);

}