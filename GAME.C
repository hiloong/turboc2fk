#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <graphics.h>

#include "allf.h"
#include "stu.h"

#define TRUE 1
#define FALSE 0
#define bool int
#define Debug

MAP[YCNT+1][XCNT+2];
FU fu_next;
int score;


void game(void);
void init_map(void);

bool unit_free(int x, int y);
bool fu_free(FU *fu);
bool left_free(FU *fu);
bool right_free(FU *fu);
bool down_free(FU *fu);
bool change_free(FU *fu);
void make_fu(FU *fu);
void stop(FU *fu);
void move_fu(FU *fu, int x);
bool game_over(void);
void get_score(FU *fu);
void get_score_(int y);

void move_a(FU *fu);
void move_s(FU *fu);
void move_d(FU *fu);
void move_change(FU *fu);

void move_ss(FU *fu);
bool is_cls_line(int y);

bool is_cls_line(int y)
{
	int x,s;

	for(x = s = 1; x < XCNT+1; x++)
		s *= MAP[y][x];
	return s;
}

void draw_map2(void)
{
	int x, y;

	for(y = 0; y < YCNT+1; y++)
	{
		for(x = 1; x < XCNT+1; x++)
		{
			if(MAP[y][x] == 1)
			{
				int N = 10;
				setcolor(WHITE);
				rectangle(x*N+N+1,y*N+N+1,(x+1)*N+N-1,(y+1)*N+N-1);
			}
			else
			{
				int N = 10;
				setcolor(BLACK);
				rectangle(x*N+N+1,y*N+N+1,(x+1)*N+N-1,(y+1)*N+N-1);
			}
		}
	}
}


void get_score(FU *fu)
{
	int i;

	get_score_(fu->a.y+fu->dy);
	get_score_(fu->b.y+fu->dy);
	get_score_(fu->c.y+fu->dy);
	get_score_(fu->d.y+fu->dy);
}

void get_score_(int y)
{
	int i,s;

	while(is_cls_line(y))
	{
		score++;
		out_score(score);
		for(i = y; i > 0; i--)
		{
			int x;
			for(x = 1; x <= XCNT; x++)
			{
				MAP[i][x] = MAP[i-1][x];
			}
			draw_line(i);
		}


	}
}

void move_a(FU *fu)
{
	if(left_free(fu))
	{
		cls_fu(fu);
		fu->dx--;
		draw_fu(fu);
	}
}

void move_ss(FU *fu)
{
loop:
	if(down_free(fu))
	{
		cls_fu(fu);
		fu->dy++;
		draw_fu(fu);
	}
	if(down_free(fu))	goto loop;
}


void move_s(FU *fu)
{
	if(down_free(fu))
	{
		cls_fu(fu);
		fu->dy++;
		draw_fu(fu);
	}
}


void move_d(FU *fu)
{
	if(right_free(fu))
	{
		cls_fu(fu);
		fu->dx++;
		draw_fu(fu);
	}
}

void move_change(FU *fu)
{
	if(change_free(fu))
	{
		cls_fu(fu);
		change_fu(fu);
		draw_fu(fu);
	}
}

bool game_over(void)
{
	int x;


/*
	if(score == 10)
	{
		int i;
		closegraph();

		for(i = 0; i <= 3; i++)
		{
			printf("YOU WIN THE GAME \t anykey to exit() \n ");
		}
		getch();
		exit(0);
	}

*/
	for(x = 1; x <= XCNT; x++)
	{
		if(MAP[0][x] == 1)
		{
			getch();
			return 1;
		}
	}
	return 0;
}

void move_fu(FU *fu, int x)
{
	if(x == 0)	fu->dx--;
	else if(x == 1) fu->dy++;
	else if(x == 2) fu->dx++;
	else fu->dy--;
}

void stop(FU *fu)
{
	draw_fu(fu);
	MAP[fu->a.y+fu->dy][fu->a.x+fu->dx] = 1;
	MAP[fu->b.y+fu->dy][fu->b.x+fu->dx] = 1;
	MAP[fu->c.y+fu->dy][fu->c.x+fu->dx] = 1;
	MAP[fu->d.y+fu->dy][fu->d.x+fu->dx] = 1;
}

void make_fu(FU *fu)
{
	int s;
	srand((unsigned)clock());
	s = rand()%7;

	fu->s = s;
	init_fu(fu, s);
	move(fu,5, 0);
}


void init_map(void)
{
	int i;

	for(i = 0; i < YCNT+1; i++)
	{
		MAP[i][0] = 1;   MAP[i][XCNT+1] = 1  ;
	}

	for(i = 0; i < XCNT+2; i++) 	MAP[YCNT][i] = 1;
}

bool unit_free(int x, int y)
{
	return (MAP[y][x] == 0);
}

bool fu_free(FU *fu)
{
	return (unit_free(fu->a.x+fu->dx, fu->a.y+fu->dy)\
	&& unit_free(fu->b.x+fu->dx, fu->b.y+fu->dy)\
	&& unit_free(fu->c.x+fu->dx, fu->c.y+fu->dy)\
	&& unit_free(fu->d.x+fu->dx, fu->d.y+fu->dy) );
}

bool left_free(FU *fu)
{
	int r;

	fu->dx--;
	r = fu_free(fu);
	fu->dx++;
	return r;
}

bool right_free(FU *fu)
{
	int r;

	fu->dx++;
	r = fu_free(fu);
	fu->dx--;
	return r;
}

bool down_free(FU *fu)
{
	int r;

	fu->dy++;
	r = fu_free(fu);
	fu->dy--;
	return r;
}


bool change_free(FU *fu)
{
	FU ff;
	ff.a.x = fu->a.x, ff.a.y = fu->a.y;
	ff.b.x = fu->b.x, ff.b.y = fu->b.y;
	ff.c.x = fu->c.x, ff.c.y = fu->c.y;
	ff.d.x = fu->d.x, ff.d.y = fu->d.y;
	ff.s = fu->s , ff.f = fu->f;
	ff.dx = fu->dx, ff.dy = fu->dy;
	change_fu(&ff);
	return (fu_free(&ff));
}


void game(void)
{
	FU ifu;
	FU *fu = &ifu;
	clock_t t1, t2;
	init_graph();
	init_map();
	draw_game_map();
	out_score(score);
	make_fu(fu);
	draw_fu(fu);
	t1 = t2 = clock();
	while(!game_over())
	{
		t1 = clock();
	loop:
		if(bioskey(1))
		{
			char c;
			int i = bioskey(0);
			c = (char) i;
			if(c == 'a' || c == 'A') { move_a(fu); }
			else if(c == 's' || c == 'S') { move_ss(fu); goto next; }
			else if(c == 'd' || c == 'D') { move_d(fu); }
			else if(c == ' ') { move_change(fu); }
			else if(c == 'p' || c == 'P') { getch() ; }
			else if(c == 'q' || c == 'Q') { exit(0) ; }
			else { /* do nothing */ ; }
		}
		t2 = clock();
		if(t2-t1 < 15) goto loop;

		if(down_free(fu))
		{
			cls_fu(fu);
			fu->dy++;
			draw_fu(fu);
		}
		else
		{
		next:
			stop(fu);
			get_score(fu);
			make_fu(fu);
		}
#ifndef Debug
		draw_map2();
#endif
	};
	close_graph();
}


void main()
{
	game();
	getch();
}