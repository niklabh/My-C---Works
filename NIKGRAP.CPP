/* ==============  Program Description  ============= */
/*   programmer name :  nikhil ranjan                 */
/*     (niklabh811@gmail.com)                         */
/*   VARIOUS Graphics.                                */
/* ================================================== */
#include<iostream.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
#define S 5
#define N 45
#define D 15


void main()
{
    int     driver = DETECT,mode;

    initgraph(&driver,&mode,"c:\\tc\\bgi");

     outtextxy(100,100,"Press any key to continue...");
     getch();
     cleardevice();


     int x1=55+20,y1=10;      int x2=520+20,y2=10-S;

     int x4=55+20,y4=460;     int x3=520+20,y3=460;

     int ctr=0;
     while(ctr<N)
     {
     x2-=S;  y2+=S;
     line(x1,y1,x2,y2); delay(D);
     x3-=S; y3-=S;
     line(x2,y2,x3,y3); delay(D);
     x4+=S;  y4-=S;
     line(x4,y4,x3,y3); delay(D);
     x1+=S;  y1+=S;
     line(x1,y1,x4,y4); delay(D);
      ctr++;
     }
     getch();
    setcolor(RED);
    setbkcolor(LIGHTGREEN);

  //involute
    float r,t;
    int x,y;
    r=0.001;
    int ctr1=0;
    while(ctr1<80)
    {
     for(int i=0;i<100;i++)
     {
      x=((int)r*cos(t))+308;
      y=((int)r*sin(t))+233;
      t=t+0.01;
      r=r+0.03;
      putpixel(x,y,BLUE);
     }
     ctr1++;
     delay(30);
    }

    getch();
    setcolor(RED);

    int big =200;
    int i=0,a,b;
    while(i<big)
    {
    a=random(630);
    b=random(460);
    line(a,b,315,230);
    i++;
    delay(30);
    }

    getch();
    for(i=1;i<7;i++)
    {
    cleardevice();
    settextstyle(8,0,i);
    outtextxy(250-(i*15),200,"NIKHIL RANJAN");
    delay(100);
    }
    getch();
    cleardevice();
    setbkcolor(BLACK);
     int x5,y5;
    float th,pi=22.0/7.0,deg;
    int j;
    for(j=1;j<4;j++){
    for(i=0;i<60;i++)
    {
    deg=(float(i)*6.0)-90.0;
    th=(pi*(deg/180.0));
    x5=int(300+150*cos(th));
    y5=int(230+150*sin(th));
    setcolor(j);
    line(300,230,x5,y5);
    delay(50);
    }
    }
    for(i=0;i<60;i++)
    {
    deg=(float(i)*6.0)-90.0;
    th=(pi*(deg/180.0));
    x5=int(300+150*cos(th));
    y5=int(230+150*sin(th));
    setcolor(BLACK);
    line(300,230,x5,y5);
    delay(100);
    setcolor(LIGHTBLUE);
    line(300,230,x5,y5);
    }
    getch();
    closegraph();
}