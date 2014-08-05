#ifndef _STU_H
#define _STU_H

#define UL 20

#define GMI 200
#define GMJ 20
#define XCNT 10
#define YCNT 20
#define GMX (GMI+XCNT*UL)
#define GMY (GMJ+YCNT*UL)


typedef struct point
{
	int x, y;
} POINT;


typedef struct four_unit
{
	POINT a, b, c, d;
	int f; 	/* flag */
	int s; 	/* shap */
	int dx, dy;
} FU;

#endif