#include<graphics.h>
#include<alloc.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
#include "home.c"
#include "profile.c"
#include "wheel.c"

void main()
{
     int gd,gm,i;
     detectgraph(&gd,&gm);
     initgraph(&gd,&gm,"c:\\tc\\bgi");
     wheel();                          //for loading
     home_draw();		    // for home page design
     profile_draw();
     closegraph();
}
