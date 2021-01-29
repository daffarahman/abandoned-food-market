#include <iostream>
#include <graphics.h>
#include <conio2.h>

int main()
{
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, "C://tc//bgi");
	cleardevice();
	outtextxy(100,100,"microsoft");
	getch();
	closegraph();
}
