
#include "stu.h"

#ifdef UL
#undef UL
#define UL 1
#endif

void change_fu(FU *fu);

void ch0(FU *fu);
void ch1(FU *fu);
void ch2(FU *fu);
void ch3(FU *fu);
void ch4(FU *fu);
void ch5(FU *fu);
void ch6(FU *fu);

void change_fu(FU *fu)
{
	switch(fu->s)
	{
		case 0 : { ch0(fu); break; }
		case 1 : { ch1(fu); break; }
		case 2 : { ch2(fu); break; }
		case 3 : { ch3(fu); break; }
		case 4 : { ch4(fu); break; }
		case 5 : { ch5(fu); break; }
		case 6 : { ch6(fu); break; }
		defualt : { /* do nothing */ }
	}
}


void ch0(FU *fu)
{
	switch(fu->f)
	{
		case 0 : { fu->f = 1; break; }
		case 1 : { fu->f = 2; break; }
		case 2 : { fu->f = 3; break; }
		case 3 : { fu->f = 0; break; }
		default : { fu->f = 0;}
	}
}

void ch1(FU *fu)
{
	int i, j;

	i = fu->b.x ; j = fu->b.y;
	switch(fu->f)
	{
		case 0 :
		{
			fu->a.x = fu->c.x = fu->d.x = i;
			fu->a.y = j-UL;	fu->c.y = j+UL;
			fu->d.y = j+2*UL;
			fu->f = 1;  break;
		}
		case 1 :
		{
			fu->a.x = i-UL; fu->c.x = i+UL; fu->d.x = i+2*UL;
			fu->a.y = fu->c.y = fu->d.y = j;
			fu->f = 0;   break;
		}
		default : { /* do nothing */ }
	}
}

void ch2(FU *fu)
{
	int i, j;

	i = fu->b.x ; j = fu->b.y;
	switch(fu->f)
	{
		case 0 :
		{
			fu->a.x = i+UL; fu->a.y = j;
			fu->c.x = i-UL; fu->c.y = j;
			fu->d.x = i-UL; fu->d.y = j+UL;
			fu->f = 1;  break;
		}
		case 1 :
		{
			fu->a.x = i; fu->a.y = j+UL;
			fu->c.x = i; fu->c.y = j-UL;
			fu->d.x = i-UL; fu->d.y = j-UL;
			fu->f = 2;   break;
		}
		case 2 :
		{
			fu->a.x = i-UL; fu->a.y = j;
			fu->c.x = i+UL; fu->c.y = j;
			fu->d.x = i+UL; fu->d.y = j-UL;
			fu->f = 3;    break;
		}
		case 3 :
		{
			fu->a.x = i; fu->a.y = j-UL;
			fu->c.x = i; fu->c.y = j+UL;
			fu->d.x = i+UL; fu->d.y = j+UL;
			fu->f = 0;   break;
		}
		default : { /* do nothing */ }
	}
}

void ch3(FU *fu)
{
	int i, j;

	i = fu->b.x; j = fu->b.y;
	switch(fu->f)
	{
		case 0 :
		{
			fu->a.x = i+UL; fu->a.y = j;
			fu->c.x = i-UL; fu->c.y = j;
			fu->d.x = i-UL; fu->d.y = j-UL;
			fu->f = 1;  break;
		}
		case 1 :
		{
			fu->a.x = i; fu->a.y = j+UL;
			fu->c.x = i; fu->c.y = j-UL;
			fu->d.x = i+UL; fu->d.y = j-UL;
			fu->f = 2; break;
		}
		case 2:
		{
			fu->a.x = i-UL; fu->a.y = j;
			fu->c.x = i+UL; fu->c.y = j;
			fu->d.x = i+UL; fu->d.y = j+UL;
			fu->f = 3; break;
		}
		case 3:
		{
			fu->a.x = i; fu->a.y = j-UL;
			fu->c.x = i; fu->c.y = j+UL;
			fu->d.x = i-UL; fu->d.y = j+UL;
			fu->f = 0; break;
		}
		default : { /* do nothing */ }
	}
}

void ch4(FU *fu)
{
	int i, j;

	i = fu->b.x; j = fu->b.y;
	switch(fu->f)
	{
		case 0:
		{
			fu->a.x = i+UL; fu->a.y = j;
			fu->c.x = i; fu->c.y = j+UL;
			fu->d.x = i-UL; fu->d.y = j+UL;
			fu->f = 1; break;
		}
		case 1:
		{
			fu->a.x = i; fu->a.y = j+UL;
			fu->c.x = i-UL; fu->c.y = j;
			fu->d.x = i-UL; fu->d.y = j-UL;
			fu->f = 2; break;
		}
		case 2:
		{
			fu->a.x = i-UL; fu->a.y = j;
			fu->c.x = i; fu->c.y = j-UL;
			fu->d.x = i+UL; fu->d.y = j-UL;
			fu->f = 3; break;
		}
		case 3:
		{
			fu->a.x = i; fu->a.y = j-UL;
			fu->c.x = i+UL; fu->c.y = j;
			fu->d.x = i+UL; fu->d.y = j+UL;
			fu->f = 0; break;
		}
		default : { /* do nothing */ }
	}
}

void ch5(FU *fu)
{
	int i, j;

	i = fu->b.x; j = fu->b.y;
	switch(fu->f)
	{
		case 0:
		{
			fu->a.x = i+UL; fu->a.y = j+UL;
			fu->c.x = i; fu->c.y = j+UL;
			fu->d.x = i-UL; fu->d.y = j;
			fu->f = 1; break;
		}
		case 1:
		{
			fu->a.x = i-UL; fu->a.y = j+UL;
			fu->c.x = i-UL; fu->c.y = j;
			fu->d.x = i; fu->d.y = j-UL;
			fu->f = 2; break;
		}
		case 2:
		{
			fu->a.x = i-UL; fu->a.y = j-UL;
			fu->c.x = i; fu->c.y = j-UL;
			fu->d.x = i+UL; fu->d.y = j;
			fu->f = 3; break;
		}
		case 3:
		{
			fu->a.x = i+UL; fu->a.y = j-UL;
			fu->c.x = i+UL; fu->c.y = j;
			fu->d.x = i; fu->d.y = j+UL;
			fu->f = 0; break;
		}
		default : {}
	}
}

void ch6(FU *fu)
{
	int i, j;

	i = fu->c.x; j = fu->c.y;
	switch(fu->f)
	{
		case 0:
		{
			fu->a.x = i+UL; fu->a.y = j;
			fu->b.x = i; fu->b.y = j-UL;
			fu->d.x = i; fu->d.y = j+UL;
			fu->f = 1; break;
		}
		case 1:
		{
			fu->a.x = i; fu->a.y = j+UL;
			fu->b.x = i+UL; fu->b.y = j;
			fu->d.x = i-UL; fu->d.y = j;
			fu->f = 2; break;
		}
		case 2:
		{
			fu->a.x = i-UL; fu->a.y = j;
			fu->b.x = i; fu->b.y = j+UL;
			fu->d.x = i; fu->d.y = j-UL;
			fu->f = 3; break;
		}
		case 3:
		{
			fu->a.x = i; fu->a.y = j-UL;
			fu->b.x = i-UL; fu->b.y = j;
			fu->d.x = i+UL; fu->d.y = j;
			fu->f = 0; break;
		}
		default : { /* do noting */ }
	}
}