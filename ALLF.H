#include "stu.h"

#ifndef _ALLF_H
#define _ALLF_H

extern void init_graph(void);
extern void close_graph(void);
extern void draw_game_map(void);
extern void draw_fu(FU *fu);
extern void cls_fu(FU *fu);
extern void init_fu(FU *fu, int s);
extern void change_fu(FU *fu);
extern void draw_unit2(int x, int y);
extern void cls_unit2(int x, int y);
extern void draw_line(int y);
extern void draw_unitx(int x, int y);
extern void out_score(int x);

extern void move(FU *fu, int x, int y);
#endif