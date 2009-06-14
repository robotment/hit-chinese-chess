
/*
		engine.h
		by:fantasy614@gmail.com
		2009/6/2
 		
*/

#ifndef _ENGINE_H 
#define  _ENGINE_H
#include "globe.h" 
bool intichess();
//void endchess ();
struct move*think(struct move*red_move);
bool Isright(struct 	move  *side_move);
typedef int side ;
void printboard();
//loc    *pos, *p;
#endif
