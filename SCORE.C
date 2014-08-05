#include <graphics.h>
#include <stdlib.h>

#define U 5
#define XC 8
#define YC 17
#define dx 500
#define dy 300
#define dx1 dx
#define dy1 100
#define dx2 dx1+U*9
#define dy2 dy1
#define dx3 dx2+U*9
#define dy3 dy1

void prt_i(int x, int y, int i);
void out_score(int n);
void out_score1(int x);
void out_score2(int y);
void out_score3(int z);
void out(int x, int y, int n);
void cls8(void);
void cls8_1(void);
void cls8_2(void);
void cls8_3(void);

void cls8_1(void)
{
	int i, x , y;

	x = dx1, y = dy1;
	for(i = 1; i <= 7; i++)
	{
		prt_i(x, y, i);
	}
}

void cls8_2(void)
{
	int i, x, y;

	x = dx2, y = dy2;
	for(i = 1; i <= 7; i++)
	{
		prt_i(x, y, i);
	}
}

void cls8_3(void)
{
	int i, x, y;

	x = dx3, y = dy3;
	for(i = 1; i <= 7; i++)
	{
		prt_i(x, y, i);
	}
}

void cls8(void)
{

	setfillstyle(SOLID_FILL, BLACK);

	cls8_1();
	cls8_2();
	cls8_3();


}

void out(int x, int y, int n)
{
	switch(n)
	{
		case 0:
		{
			int i;

			for(i = 1; i <= 6; i++)	prt_i(x, y, i);
			break;
		}
		case 1:
		{
			prt_i(x, y, 1);
			prt_i(x, y, 6);
			break;
		}
		case 2:
		{
			prt_i(x, y, 2);
			prt_i(x, y, 3);
			prt_i(x, y, 5);
			prt_i(x, y, 6);
			prt_i(x, y, 7);
			break;
		}
		case 3:
		{
			prt_i(x, y, 2);
			prt_i(x, y, 3);
			prt_i(x, y, 4);
			prt_i(x, y, 5);
			prt_i(x, y, 7);
			break;
		}
		case 4:
		{
			prt_i(x, y, 1);
			prt_i(x, y, 3);
			prt_i(x, y, 4);
			prt_i(x, y, 7);
			break;
		}
		case 5:
		{
			prt_i(x, y, 1);
			prt_i(x, y, 2);
			prt_i(x, y, 4);
			prt_i(x, y, 5);
			prt_i(x, y, 7);
			break;
		}
		case 6:
		{
			prt_i(x, y, 1);
			prt_i(x, y, 2);
			prt_i(x, y, 4);
			prt_i(x, y, 5);
			prt_i(x, y, 6);
			prt_i(x, y, 7);
			break;
		}
		case 7:
		{
			prt_i(x, y, 2);
			prt_i(x, y, 3);
			prt_i(x, y, 4);
			break;
		}
		case 8:
		{
			int i;

			for(i = 1; i <= 7; i++)
			{
				prt_i(x, y, i);
			}
			break;
		}
		case 9:
		{
			prt_i(x, y, 1);
			prt_i(x, y, 2);
			prt_i(x, y, 3);
			prt_i(x, y, 4);
			prt_i(x, y, 5);
			prt_i(x, y, 7);
			break;
		}
		default : { /* do nothing */ }

	}
}


void out_score(int n)
{
	int x, y, z;
	x = n/100;
	y = n/10%10;
	z = n%10;

	cls8();
	setfillstyle(SOLID_FILL, WHITE);
	out_score1(x);
	out_score2(y);
	out_score3(z);
}

void out_score1(int x)
{
	int i, j;

	i = dx1, j = dy1;
	out(i, j, x);
}

void out_score2(int x)
{
	int i, j;

	i = dx2, j = dy2;
	out(i, j, x);
}

void out_score3(int x)
{
	int i, j;

	i = dx3, j = dy3;
	out(i, j, x);
}

void prt_i(int x, int y, int i)
{
	switch(i)
	{
		case 1 :bar(x+0, y+0, x+U, y+8*U); break;
		case 2 :bar(x+0, y+0, x+U*8, y+U); break;
		case 3 :bar(x+7*U, y+0, x+U*8, y+8*U); break;
		case 4 :bar(x+7*U, y+8*U, x+U*8, y+17*U); break;
		case 5 :bar(x+0, y+16*U, x+U*8, y+17*U); break;
		case 6 :bar(x+0, y+8*U, x+U, y+17*U); break;
		case 7 :bar(x+0, y+8*U, x+8*U, y+9*U); break;
		default: { /* do nothing */; }
	}
}


