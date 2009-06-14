
/***************************************************************************
 *            think.h
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
#ifndef 	_THINK_H_
#define   _THINK_H_
#include "globe.h" 

typedef struct _loc 
{
    int chessman ;
    int pos ;
    struct _loc*next ;
}loc ;

//解决重复定义问题
extern const int Horse_step[8][2];
extern const int Advisor_step[4][2];
extern const int Elephant_step[4];
extern const int General_step[4];
extern const int Soldier_step[3];
extern const int chessman[256];
extern const int infort[256];

bool check_Horse(int src,int des);
bool check_Advisor(int src,int des);
bool check_Soldier(int src,int des);
bool check_General(int src,int des);
bool check_Elephant(int src,int des);
bool check_Cannon(int src,int des);
bool check_Chariot(int src,int des);
bool is_same_side(int src,int des);
#endif
