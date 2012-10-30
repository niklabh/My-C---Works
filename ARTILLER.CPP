/*==================================================================*/
/*==================Artillery game==================================*/
/*Programmer:
  Nikhil Ranjan
  GGSIPU USIT
  B.tech(IT) 2nd year*/
/*===================================================================*/
/*Instruction:
  You are a artillery trying to hit a random target.
  Press: a/d to increase/decrease power.
	 w/s to increase/decrease angle.
	 x to fire.
	 e to exit.*/
/*====================================================================*/
/*Programmer Notes:
  ---Still got some bugs. Try not for increasing angle beyond 70'.
  ---Always keep the power > 0.
  ---Sometime target may not appears.
  ---Sorry for crappy Programming writing and poor comments.*/
/*====================================================================*/
#include<iostream.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>

//nozzel stuff
int X=135,Y=314,X1=100,Y1=350;

void shell(int x,int y);
void shell2(int x,int y);
void nozzel(int an);
void shellpath(int,int);


int xposofob;
void ob(int);



void main()
{

  float a1,a2;
  int s1,s2;
  char ch;

  //graphic initialisation
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"..//bgi");

  cleardevice();
  randomize();



  rectangle(10,10,630,470);
  rectangle(20,20,620,460);

  settextstyle(1,0,6);
  outtextxy(250,180,"Artillery");
  settextstyle(0,0,1);
  outtextxy(380,420,"Press any key to continue....");
  getch();
  cleardevice();



  //niche ka area
  rectangle(10,400,630,470);
  rectangle(20,410,620,460);
  outtextxy(45,430,"Power:");

  gotoxy(10,3);cout<<45;

  rectangle(102,420,455,445);

  outtextxy(24,37,"Angle:");
  circle(95,35,2);
  rectangle(10,10,120,80);
  rectangle(13,13,117,77);

  gotoxy(25,5);cout<<"Power increase/decrease: a/d";
  gotoxy(25,6);cout<<"Angle increase/decrease: w/s";
  gotoxy(25,7);cout<<"Fire:  x";
  gotoxy(25,8);cout<<"Exit: e";
  gotoxy(25,9);cout<<"Try to hit the target";

  setcolor(WHITE);
  line(X1,Y1,X,Y);
  line(X1+4,Y1+4,X+4,Y+4);
  line(X1,Y1,X1+4,Y1+4);
  line(X,Y,X+4,Y+4);


  shell2(105,350);

  //artillery machine
  rectangle(80,350,125,375);
  circle(90,375,3);
  circle(90,375,2);
  circle(115,375,3);
  circle(115,375,3);

  //ground
  rectangle(10,377,630,380);

  int i=2;int j=45;

  xposofob=200+random(550);


  while(1){

  setcolor(WHITE);
  xposofob=200+random(550);
  ob(xposofob);


  do{
     ch=getche();
     if(ch=='d'&&i<350)
     {
      setcolor(WHITE);
      line(103+i,422,103+i,443);
      i++;
     }
     if(ch=='a'&&i>0)
     {
      setcolor(BLACK);
      line(103+i,422,103+i,443);
      i--;
     }
     if(ch=='w'&&j<90)
     {
      j++;
      gotoxy(10,3);cout<<j;
      nozzel(j);
     }
     if(ch=='s'&&j>0)
     {
      j--;
      gotoxy(10,3);cout<<j;
      nozzel(j);
     }
     if(ch=='e')
     {
       closegraph();
       exit(0);
     }
    }while(ch!='x');


   rectangle(10,377,630,380);
   shellpath(i,j);
   setcolor(BLACK);
   ob(xposofob);
   delay(50);

 }



}             //end of main

void ob(int x)
{
  circle(x,370,10);
  circle(x,370,6);
  circle(x,370,2);
}

void nozzel(int an)
{
  float rad;
  setcolor(BLACK);
  line(X1,Y1,X,Y);
  line(X1+4,Y1+4,X+4,Y+4);
  line(X1,Y1,X1+4,Y1+4);
  line(X,Y,X+4,Y+4);

  rad=(22.0/7.0)*an/180.0;
  X=X1+(int)50.0*cos(rad);
  Y=Y1-(int)50.0*sin(rad);
  setcolor(WHITE);
  line(X1,Y1,X,Y);
  line(X1+4,Y1+4,X+4,Y+4);
  line(X1,Y1,X1+4,Y1+4);
  line(X,Y,X+4,Y+4);

  shell(105,350);


  outtextxy(24,37,"Angle:");
  circle(95,35,2);
  rectangle(10,10,120,80);
  rectangle(13,13,117,77);

  //this is the tank nozzel

}
void shellpath(int pow,int an)
{
  float xi,yi,xf,yf;
  int x,y;
  xi=X+8;  yi=Y-2;

  xf=xi;
  int ctr=0;

  float rad;
  rad=(22.0/7.0)*an/180.0;
  float v=2*pow;

  y=100;
  while(y<380)
  {
  xf++;
  yf=yi-(tan(rad)*(xf-xi))+((1.0/2.0)*9.8*(xf-xi)*(xf-xi)/v*cos(rad));
  x=(int)xf;
  y=(int)yf;
  setcolor(WHITE);
  shell(x,y);
  delay(20);
  setcolor(BLACK);
  shell(x,y);
  gotoxy(8,8);  cout<<"x:"<<x;
  gotoxy(8,9);  cout<<"y:"<<y;
  ctr++;
  }
  int diff=abs(x-xposofob);
  int score=500-diff;
  gotoxy(50,20);cout<<"SCORE:"<<score;


}
//two objects in the game
void shell(int x,int y)
{
  circle(x,y,4);
  circle(x,y,3);
  circle(x,y,2);
  circle(x,y,1);
}

void shell2(int x,int y)
{
  circle(x,y,6);
  circle(x,y,5);
  circle(x,y,4);
  circle(x,y,2);
}

