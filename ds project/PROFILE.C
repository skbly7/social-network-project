void clear_profile()
{
	setfillstyle(SOLID_FILL,WHITE);
	bar(0,0,700,500);
	setfillstyle(SOLID_FILL,40);
	bar(0,50,700,60);
}
void header_profile()
{
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,0,700,50);
	setcolor(255);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
	outtextxy(0,0,"FACEBOOK");

	setcolor(255);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(500,30,"Welcome");
	outtextxy(570,30,login_user);

}

void slide_profile()
{
	setfillstyle(SOLID_FILL,BLACK);
	bar(0,60,150,500);
	setfillstyle(SOLID_FILL,30);
	bar(10,70,130,200);

	/*
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
	*/
	/////NEW LINKSSSSSSSS


	setcolor(4);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);

	outtextxy(10,230,"Links");
	setcolor(10);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	outtextxy(10,250,"About");
	outtextxy(10,265,"Friends");
	outtextxy(10,280,"Status");
	setcolor(255);
	//lines newly added
	//line(10,98,150,98);

	line(10,260,150,260);
	line(10,275,150,275);
	line(10,290,150,290);

}
void profile_page()
{
	clear_profile();
	slide_profile();
	header_profile();
	getch();
}
void profile_draw()
{
	profile_page();
}
