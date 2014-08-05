
#include "stu.h"

#ifdef UL
#undef UL
#define UL 1
#endif

void init_fu(FU *fu, int f);
void init_0(FU *fu);
void init_1(FU *fu);
void init_2(FU *fu);
void init_3(FU *fu);
void init_4(FU *fu);
void init_5(FU *fu);
void init_6(FU *fu);

void init_fu(FU *fu, int s)
{
	switch(s)
	{
		case 0 : { init_0(fu); break; }
		case 1 : { init_1(fu); break; }
		case 2 : { init_2(fu); break; }
		case 3 : { init_3(fu); break; }
		case 4 : { init_4(fu); break; }
		case 5 : { init_5(fu); break; }
		case 6 : { init_6(fu); break; }
		default: { /* do nothing */ }
	}
}

void init_0(FU *fu)
{
	fu->s = 0; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = UL;   fu->b.y = 0;
	fu->c.x = 0;  fu->c.y = UL;
	fu->d.x = UL; fu->d.y = UL;
}

void init_1(FU *fu)
{
	fu->s = 1; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = UL; fu->b.y = 0;
	fu->c.x = UL*2; fu->c.y = 0;
	fu->d.x = UL*3; fu->d.y = 0;
}

void init_2(FU *fu)
{
	fu->s = 2; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = 0; fu->b.y = UL;
	fu->c.x = 0; fu->c.y = UL*2;
	fu->d.x = UL; fu->d.y = UL*2;
}

void init_3(FU *fu)
{
	fu->s = 3; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = 0; fu->b.y = UL;
	fu->c.x = 0; fu->c.y = UL*2;
	fu->d.x = -1*UL; fu->d.y = UL*2;
}

void init_4(FU *fu)
{
	fu->s = 4; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = 0; fu->b.y = UL;
	fu->c.x = UL; fu->c.y = UL;
	fu->d.x = UL; fu->d.y = UL*2;
}

void init_5(FU *fu)
{
	fu->s = 5; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = -1*UL; fu->b.y = UL;
	fu->c.x = 0; fu->c.y = UL;
	fu->d.x = -1*UL; fu->d.y = UL*2;
}

void init_6(FU *fu)
{
	fu->s = 6; fu->f = 0;
	fu->dx = fu->dy = 0;
	fu->a.x = fu->a.y = 0;
	fu->b.x = -1*UL; fu->b.y = UL;
	fu->c.x = 0; fu->c.y = UL;
	fu->d.x = UL; fu->d.y = UL;
}