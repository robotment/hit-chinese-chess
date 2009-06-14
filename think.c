
/***************************************************************************
 *            think.c
 *
 *  Wed Jun 10 18:08:50 2009
 *  Copyright  2009  fantasy
 *  <fantasy@<host>>
 ****************************************************************************/

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
	 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#include "think.h" 
//#include "globe.h" 
#include <gtk/gtk.h>


const int Horse_step[8][2]=
{
    {        14,1     }    ,
    {        18,-1     }    ,
    {        -14,-1     }    ,
    {        -18,1     }    ,
    {        31,-16     }    ,
    {        33,-16     }    ,   
	{        -31,16     }    ,
    {        -33,16     }
}
;


const int Advisor_step[4][2]=
{
    {        15,1     }    ,
    {        17,1     }    ,
    {        -15,-1     }    ,
    {        -17,-1     }
}
;

const int Elephant_step[4]=
{
    -30,-34,30,34 
}
;

const int Soldier_step[3]=
{
   1,-1,16
};

const int General_step[4]=
{
   1,-1,-16,16
};
//enum side{RED,BLACK};

 const int chessman[256]=
{
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,9,8,7,6,100,6,7,8,9,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,5,0,0,0,0,0,5,0,-1,-1,-1,-1,
    -1,-1,-1,4,0,4,0,4,0,4,0,4,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,14,0,14,0,14,0,14,0,14,-1,-1,-1,-1,
    -1,-1,-1,0,15,0,0,0,0,0,15,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,19,18,17,16,200,16,17,18,19,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 
}
;



 const int infort[256]=
{
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,5,0,0,0,5,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,5,0,0,2,3,2,0,0,5,-1,-1,-1,-1,
    -1,-1,-1,0,0,0,3,2,3,0,0,0,-1,-1,-1,-1,
    -1,-1,-1,0,0,5,2,3,2,5,0,0,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 
}
;


bool 
check_Horse(int src,int des)
{
	int check,i ;
	check=src-des ;
	/*check=check>0?chech:-check;
	 if(check!=14&&check!=18&&check!=31&&check!=33)
	 return false;
	 */
	//	g_print("check horse\n");
	for(i=0;i<8;i++)
	{
		if(Horse_step[i][0]==check)
		{
			src+=Horse_step[i][1];

			g_print("\n\n	the src is %d  %d\n",src,chessman_state[src]);
			if(chessman_state[src])
				return false ;
			else 
				return true ;
		}
	}

	return false ;
}



bool 
check_Advisor(int src,int des)
{
	int check ,i;
	check=src-des ;
	for(i=0;i<4;i++)
	{
		if(Advisor_step[i][0]==check)
		{
			if(infort[des]==2)
				return true ;
			else 
				return false ;
		}
	}
	return false;

}



bool 
check_Soldier(int src,int des)
{

	int check ,i;
	check=src-des ;

	//没过河
	if(src>128 )
	{
		if(check==16)
		return true;
		else 
		return false;
	}
	for(i=0;i<4;i++)
	{
		if(Soldier_step[i]==check)
		{
				return true ;		 

		}
	}
	
	return false ;
}

bool check_General(int src,int des){
	int check ,i;
	check=src-des ;
	for(i=0;i<4;i++)
	{
		if(General_step[i]==check)
		{
			if(infort[des]==2||infort[des]==3 )
				return true ;
			else 
				return false ;
		}
	}
	return false;
}


bool check_Elephant(int src,int des)
{
	int check ,i;
	check=src-des ;
	for(i=0;i<4;i++)
	{
		if(Elephant_step[i]==check)
		{
			if(chessman_state[(des+src)/2]>0)
				return false ;
			else 
				return true ;
		}
	}
	return false;

}
;
bool is_same_side(int src,int des)
{
if((chessman_state[des]>0&&chessman_state[des]<10 &&chessman_state[src]>10)||
	   (chessman_state[src]>0&&chessman_state[src]<10 &&chessman_state[des]>10))
		return true;
	else
		return false;
}
bool check_Cannon(int src,int des)
{
	int i;
	int max,min;
	int temp=0;

	if(chessman_state[des]==0)		
		return check_Chariot( src, des);
	max=(src-des>0)?src:des;
	min=(src-des<0)?src:des;
	

	if(is_same_side( src, des))
		{
			if(src/16==des/16)
			{
				for(i=min+1;i<max;i++)
					if(chessman_state[i]>0)
					{
						if(temp==0)
							temp=1;
						else
							return false;
					}
				if(temp==0)
					return false;
				else
			return true;	
				
		
	}
	
	if(src%16==des%16)
	{
		for(i=min+16;i<max;i=i+16)
		if(chessman_state[i]>0)
			{
				if(temp==0)
					temp=1;
				else
					return false;
			}
		
		if(temp==0)
			return false;
		else
			return true;	
	}
	}
	return  false;
}
;

bool check_Chariot(int src,int des)
{
	int i;
	int max,min;

	max=(src-des>0)?src:des;
	min=(src-des<0)?src:des;
	
	
	if(src/16==des/16)
	{
		for(i=min+1;i<max;i++)
			if(chessman_state[i]>0)
			return false;
		 return true;
		
	}
	
	if(src%16==des%16)
	{
		for(i=min+16;i<max;i=i+16)
			if(chessman_state[i]>0)
			return false;
		 return true;		
	}
	return  false;
};

