

void clear_home()
{
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,700,500);
	setfillstyle(SOLID_FILL,40);
	bar(0,50,700,60);
}
void header_home()
{
	setfillstyle(SOLID_FILL,240);
	bar(0,0,700,50);
	setcolor(255);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	outtextxy(0,0,"FACEBOOK");

	setcolor(255);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(500,30,"Welcome");
	outtextxy(570,30,login_user);

}
void slide_home()
{
	setfillstyle(SOLID_FILL,240);
	bar(0,60,150,500);

	setcolor(4);
	outtextxy(10,80,"Links");
	setcolor(10);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(10,100,"Messages");
	outtextxy(10,115,"Friend");
	outtextxy(60,115,"Requests");
	outtextxy(10,130,"Notifications");
	setcolor(255);
	//lines newly added
	//line(10,98,150,98);

	line(10,110,150,110);
	line(10,125,150,125);
	line(10,140,150,140);
	//////////////////////////
	/////NEW LINKSSSSSSSS


	setcolor(4);
	outtextxy(10,180,"More");
	setcolor(10);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(10,200,"Profile");
	outtextxy(10,215,"Games");
	outtextxy(55,215,"Center");
	outtextxy(10,230,"Credits");
	setcolor(255);
	//lines newly added
	//line(10,98,150,98);

	line(10,210,150,210);
	line(10,225,150,225);
	line(10,240,150,240);

}
void home_page()
{
	clear_home();
	slide_home();
	header_home();
}
void home_draw()
{
	home_page();



	getch();
}