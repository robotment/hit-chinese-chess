
#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <time.h> 
#include "engine.h"
//#include "globe.h"
#include "think.h"




bool intichess()
{    
	return true ;    
}
;



void endchess();


struct move* think(struct move*red_move)
{
	struct move*black_move ;
	int rand_x ;
	srand((unsigned)time(NULL));

	black_move=(struct move*)malloc(sizeof(struct move*));

	rand_x=rand()%256 ;
	while(1)
	{
		rand_x=rand()%256 ;
		if(chessman_state[rand_x]>10)
			break;
	}
	black_move->src=rand_x ;

	while(1)
	{
		rand_x=rand()%256 ;
		if(chessman_state[rand_x]>=0&&chessman_state[rand_x]<=10)
			break;
	}
	black_move->des=rand_x ;
	return black_move ;

};

/*
 typedef struct _loc{
	 int  chessman;
	 int  pos;
	 struct _loc *next;
	 }loc;

	 */




bool Isright(struct 	move  *side_move)
{


	int src=side_move->src ;
	int des=side_move->des ;
	
	bool flag=false;
	side side_state ;

	side_state=chessman_state[src]/10 ;
 	printboard();

	if(chessman_state[src]<0||chessman_state[des]<0)
		return false ;
	
	g_print("engine %d\n",chessman_state[src]);

	
	if(chessman_state[des])
	{
		if(chessman_state[des]/10==side_state)
		return false ;
	}
g_print("engine %d\n",chessman_state[src]);

	
	switch(chessman_state[src])
	{
		case   4 :
		case   14:
			g_print("check horse");
			flag=check_Horse(src,des);
			break ;

		case R_General:
		case B_General:
			flag=check_General(src,des);
			break;

		case   B_Soldier :
		case   R_Soldier:
			flag=check_Soldier(src,des);			
			break ;

		case   R_Cannon :
		case   B_Cannon:
			flag=check_Cannon(src,des);
			break ;

		case R_Advisor:
		case B_Advisor:
			flag=check_Advisor(src,des);
			break;

		case   R_Chariot :
		case   B_Chariot:
			flag=check_Chariot(src,des);
			break;


		case B_Elephant:
		case R_Elephant:
			flag=check_Elephant(src,des);
			break ;

	}

	/*      
	 p=pos;
	 while(p->next)
	 {
		 if(p->pos)
		 p=p->next;
}
*/
	return flag ;

}
;

void printboard()
{
		int i;
		for(i=0;i<256;i++)
	{
		if(chessman_state[i]!=-1)
		{
				g_print("%2d  ",chessman_state[i]);
			
		}	
		if(i%16==0)
				g_print("\n");
	}
}
