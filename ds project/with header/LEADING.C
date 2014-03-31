#include<graphics.h>
#include<alloc.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include<skbly7.h>
//#include "profile.c"
//#include "wheel.c"
//#include "home.c"
//#include "login.c"


void main()
{
     int gd,gm,i;
     detectgraph(&gd,&gm);
     initgraph(&gd,&gm,"C:\\TC\BGI");
     wheel();                          //for loading
     login_main();
     home_draw();		    // for home page design
     profile_draw();
     closegraph();
}