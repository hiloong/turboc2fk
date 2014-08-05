#include <graphics.h>
#include "stu.h"

extern int MAP[YCNT+1][XCNT+2];

void init_graph(void);
void close_graph(void);
void draw_game_map(void);
void draw_unit(int x, int y);
void draw_fu_(FU *fu);
void draw_fu(FU *fu);
void cls_fu(FU *fu);
void cls_unit2(int x, int y);
void draw_unit2(int x, int y);
void draw_unitx(int x, int y);
void draw_line(int y);

void draw_line(int y)
{
	int i;

	for(i= 1; i <= XCNT;  i++)
	{
		draw_unitx(y, i);
	}
}


void draw_unitx(int y, int x)
{
	if(MAP[y][x] == 1)	draw_unit2(x*UL, y*UL);
	else			cls_unit2(x*UL, y*UL);
}

void init_graph(void)
{
	int gmode, gdriver;

	gmode = VGA; gdriver = VGAHI;
	initgraph(&gmode, &gdriver , "c:\\turboc2" );
}

void close_graph(void)
{
	closegraph();
}

void draw_game_map(void)
{
	rectangle(GMI-2+UL, GMJ-2, GMX+2+UL, GMY+2);
	rectangle(GMI+UL, GMJ, GMX+UL, GMY);
}

void draw_unit(x, y)
{
	rectangle(x+1+GMI, y+1+GMJ, x+UL-1+GMI, y+UL-1+GMJ);
	rectangle(x+1+GMI+5, y+1+GMJ+5, x+UL-1+GMI-5, y+UL-1+GMJ-5);
}

void cls_unit2(x, y)
{
	setcolor(BLACK);
	draw_unit(x,y);
}

void draw_unit2(x, y)
{
	setcolor(WHITE);
	draw_unit(x, y);
}

void draw_fu_(FU *fu)
{
	draw_unit(fu->a.x*UL+fu->dx*UL, fu->a.y*UL+fu->dy*UL);
	draw_unit(fu->b.x*UL+fu->dx*UL, fu->b.y*UL+fu->dy*UL);
	draw_unit(fu->c.x*UL+fu->dx*UL, fu->c.y*UL+fu->dy*UL);
	draw_unit(fu->d.x*UL+fu->dx*UL, fu->d.y*UL+fu->dy*UL);
}

void draw_fu(FU *fu)
{
	setcolor(WHITE);
	draw_fu_(fu);
}

void cls_fu(FU *fu)
{
	setcolor(BLACK);
	draw_fu_(fu);
}