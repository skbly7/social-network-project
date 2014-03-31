void wheel()
{
	int i;
	outtextxy(260,240,"Loading");
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,700,480);
	for(i=0;i<50;i++)
	{
		setfillstyle(SOLID_FILL,CYAN);
		fillellipse(285,240,10*i,10*i);
		outtextxy(260,240,"Loading");
		delay(40);
		setfillstyle(SOLID_FILL,BLUE);
		fillellipse(285,240,5*i,5*i);
		outtextxy(260,240,"Loading");
		delay(40);
	}

}