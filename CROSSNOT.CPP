/*=======================================================*/
/*CROSS AND NOT*/
/* programmer: NIKHIL RANJAN (niklabh811@gmail.com)*/
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#define true 1
#define false 0
int index;
int ar[10];
int XJ,OJ;
int a[3][3];

void drawgrid()
{
  line(300,100,300,250);
  line(350,100,350,250);
  line(250,150,400,150);
  line(250,200,400,200);
}
void show()
{
  int i;
  gotoxy(10,10);cout<<index;
  for(i=0;i<9;i++)
   {
       gotoxy(10+i,2);cout<<ar[i];}
       int j;
   for(i=0;i<3;i++)
     {
       for(j=0;j<3;j++)
       {
	 gotoxy(40+j,2+i);cout<<a[i][j];
       }
     }
}
int chkfrwin()
{
   if(index>8)
    return false;
   show();
   if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]==a[0][0]&&a[0][0]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]==a[1][0]&&a[1][0]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]==a[2][0]&&a[2][0]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]&&a[2][0]==a[0][0]&&a[0][0]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[2][1]==a[0][1]&&a[0][1]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]&&a[2][2]==a[0][2]&&a[0][2]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]==a[0][0]&&a[0][0]==1)
   {
     XJ=1;
     return false;
   }
   else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]==a[0][2]&&a[0][2]==1)
   {
     XJ=1;
     return false;
   }

   else if(a[0][0]==a[0][1]&&a[0][1]==a[0][2]&&a[0][2]==a[0][0]&&a[0][0]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[1][0]==a[1][1]&&a[1][1]==a[1][2]&&a[1][2]==a[1][0]&&a[1][0]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[2][0]==a[2][1]&&a[2][1]==a[2][2]&&a[2][2]==a[2][0]&&a[2][0]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[0][0]==a[1][0]&&a[1][0]==a[2][0]&&a[2][0]==a[0][0]&&a[0][0]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[0][1]==a[1][1]&&a[1][1]==a[2][1]&&a[2][1]==a[0][1]&&a[0][1]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[0][2]==a[1][2]&&a[1][2]==a[2][2]&&a[2][2]==a[0][2]&&a[0][2]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[0][0]==a[1][1]&&a[1][1]==a[2][2]&&a[2][2]==a[0][0]&&a[0][0]==2)
   {
     OJ=1;
     return false;
   }
   else if(a[0][2]==a[1][1]&&a[1][1]==a[2][0]&&a[2][0]==a[0][2]&&a[0][2]==2)
   {
     OJ=1;
     return false;
   }
   else
   return true;
}

int chkfrin(int input)
{
   show();
   for(int i=0;i<9;i++)
   {
     if(input==ar[i])
      return 1;
   }

   return 0;
}
void update(int input)
{
  show();
  ar[index]=input;
  index++;
}
void paintux(int input)
{
  show();
  int X,Y;
  switch(input)
  {
     case 1: X=275;Y=125;a[0][0]=1;break;
     case 2: X=325;Y=125;a[0][1]=1;break;
     case 3: X=375;Y=125;a[0][2]=1;break;

     case 4: X=275;Y=175;a[1][0]=1;break;
     case 5: X=325;Y=175;a[1][1]=1;break;
     case 6: X=375;Y=175;a[1][2]=1;break;

     case 7: X=275;Y=225;a[2][0]=1;break;
     case 8: X=325;Y=225;a[2][1]=1;break;
     case 9: X=375;Y=225;a[2][2]=1;break;
     default: outtextxy(10,10,"errorsomewhere");

  }
  line(X-10,Y-10,X+10,Y+10);
  line(X+10,Y-10,X-10,Y+10);
}
void paintuo(int input)
{
  int X,Y;
  switch(input)
  {
     case 1: X=275;Y=125;a[0][0]=2;break;
     case 2: X=325;Y=125;a[0][1]=2;break;
     case 3: X=375;Y=125;a[0][2]=2;break;

     case 4: X=275;Y=175;a[1][0]=2;break;
     case 5: X=325;Y=175;a[1][1]=2;break;
     case 6: X=375;Y=175;a[1][2]=2;break;

     case 7: X=275;Y=225;a[2][0]=2;break;
     case 8: X=325;Y=225;a[2][1]=2;break;
     case 9: X=375;Y=225;a[2][2]=2;break;
     default: outtextxy(10,10,"errorsomewhere");

  }
  circle(X,Y,10);
}

void userin()
{
  int input;

  gotoxy(27,25);cout<<"Input(1-9):";
  do{
  gotoxy(38,25);cin>>input;
  }while(chkfrin(input));

  update(input);
  paintux(input);
}
int randgenrt();
void comin()
{
  int input;
  input=randgenrt();
  update(input);
  paintuo(input);
}
int randgenrt()
{
  int rand,flag=1;
  while(flag)
  {
    rand=1+random(9);
    if(!chkfrin(rand))
    flag=0;
  }
  return rand;
}
void winresult();

void drawwelcome()
{
  rectangle(10,10,630,470);
  outtextxy(100,100,"TicTacToe");
  drawgrid();
  gotoxy(10,25);cout<<"Enter the position 1 2 3 4 5 6 7 8 9 to place your chance.";
  getch();
  cleardevice();

}
void main()
{
   int gd=DETECT,gm=DETECT;
   initgraph(&gd,&gm,"..//bgi");
   cleardevice();
   randomize();
   drawwelcome();
   int ch=random(2);
   int i,j;

   XJ=0;
   OJ=0;

   for(i=0;i<9;i++)
     ar[i]=0;

   index=0;

   for(i=0;i<3;i++)
     for(j=0;j<3;j++)
       a[i][j]=0;
   drawgrid();


   while(chkfrwin())
   {
      if(ch)
      {
	userin();
	show();
	comin();
	show();
      }
      else
      {
	comin();
	show();
	userin();
	show();
      }

  }

  winresult();
  closegraph();

}
void winresult()
{
   //cleardevice();
   rectangle(10,10,630,470);
   rectangle(15,15,625,465);
   if(XJ==1)
   {
     outtextxy(300,400,"Congrats!!YOU WIN!");
   }

   if(OJ==1)
   {
     outtextxy(300,400,"Computer Wins!!you lose!");
   }

   if(OJ==0&&XJ==0)
   {
     outtextxy(300,400,"Tie!you suck");
   }

   getch();

}