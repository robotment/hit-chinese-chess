/***************************************************************************
 *            globe.h
 *
 *  Wed Jun  3 20:50:20 2009
 *  Copyright  2009  fantasy
 *  <fantasy614@gmail.com>>
 ****************************************************************************/



#ifndef _GLOBE_H_ 
#define _GLOBE_H_ 

/*GNU solutions bool in c */
#ifdef HAVE_STDBOOL_H 
#include<stdbool.h>
#else 
#ifndef HAVE__BOOL 
#ifdef __cplusplus 
typedef bool _Bool ;
#else 
#define _Bool signed char 
#endif 
#endif 
#define bool _Bool 
#define false 0 
#define true 1 
#define __bool_true_false_are_defined 1 
#endif 

#define IP 0 

struct 
{
    enum 
    {
        RED=1,
        BLACK 
    }
    side_go ;    
}chess_state ;


extern int chessman_state[256];
struct move 
{
    int src ;
    int des ;
};

enum 
{    
    R_General=1,R_Advisor,R_Elephant,R_Horse,R_Chariot,R_Soldier,
    R_Cannon,
    RED_KING_DIE,BLACK_KING_DIE,
    NULL_CHESSMAN,
    B_General,B_Advisor,B_Elephant,B_Horse,B_Chariot,B_Soldier,
    B_Cannon,
    SELECTED_CHESSMAN,
};
#endif


