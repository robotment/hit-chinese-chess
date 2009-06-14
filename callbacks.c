/*
 * callbacks.c
 * Copyright (C) fantasy 2009 <fantasy@>
	 *
 * callbacks.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
	 *
 * callbacks.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H 
#include<config.h>
#endif 
#include<gtk/gtk.h>
#include<stdlib.h>
#include "callbacks.h" 
#include "globe.h" 
#include "engine.h" 

void 
init_chess()
{
    move=(struct _move*)malloc(sizeof(struct _move*));
    move->src_pos=(struct board*)malloc(sizeof(struct board*));
    move->des_pos=(struct board*)malloc(sizeof(struct board*));
    red_move=(struct move*)malloc(sizeof(struct move*));
    black_move=(struct move*)malloc(sizeof(struct move*));
    chess_state.side_go=RED ;
}

void 
destroy_callback(GtkWidget*widget,gpointer data)
{
    g_print("hello");
    gtk_main_quit();
}

gboolean 
expose_event_callback(GtkWidget*widget,GdkEventExpose*event,
gpointer data)
{
    static int i=1 ;
    if(i==1)
    init_board(widget);
    i++;
    //draw_chessman(widget);
    return TRUE ;
}

void 
init_board(GtkWidget*widget)
{
    
    int bufWidth,bufHeight ;
    //      int i,j,k;
    
    GError*error=NULL ;
    
    buf=gdk_pixbuf_new_from_file("res/board.png",&error);
    
    
    // g_print("hello");
    
    bufWidth=gdk_pixbuf_get_width(buf);
    bufHeight=gdk_pixbuf_get_height(buf);
    
    // gtk_drawing_area_size  ((GtkDrawingArea*)widget,bufWidth,       bufHeight);
    
    gdk_draw_pixbuf(widget->window,NULL,buf,0,0,0,0,
    bufWidth,bufHeight,GDK_RGB_DITHER_NORMAL,0,0);
    draw_chessman(widget);
    g_print("draw board\n");
    
}


void draw_chessman(GtkWidget*widget)
{
    int i ;
    int board_x,board_y ;
    for(i=0;i<256;i++)
    {
        if(chessman_state[i]!=-1||chessman_state[i]!=0)
        board_x=i%16-3 ;
        board_y=i/16-3 ;
        gdk_draw_pixbuf(widget->window,NULL,
        chessman_images[chessman_state[i]],0,0,
        55*board_x,55*board_y,
        57,57,GDK_RGB_DITHER_NORMAL,57,57);
    }
}

gboolean read_image()
{
    int i ;
    GError*error=NULL ;
    chessman_images[R_General]=
    gdk_pixbuf_new_from_file("res/R_General.png",&error);
    chessman_images[R_Advisor]=
    gdk_pixbuf_new_from_file("res/R_Advisor.png",&error);
    chessman_images[R_Elephant]=
    gdk_pixbuf_new_from_file("res/R_Elephant.png",&error);
    chessman_images[R_Horse]=
    gdk_pixbuf_new_from_file("res/R_Horse.png",&error);
    chessman_images[R_Chariot]=
    gdk_pixbuf_new_from_file("res/R_Chariot.png",&error);
    chessman_images[R_Soldier]=
    gdk_pixbuf_new_from_file("res/R_Soldier.png",&error);
    chessman_images[R_Cannon]=
    gdk_pixbuf_new_from_file("res/R_Cannon.png",&error);
    
    chessman_images[B_General]=
    gdk_pixbuf_new_from_file("res/B_General.png",&error);
    chessman_images[B_Advisor]=
    gdk_pixbuf_new_from_file("res/B_Advisor.png",&error);
    chessman_images[B_Elephant]=
    gdk_pixbuf_new_from_file("res/B_Elephant.png",&error);
    chessman_images[B_Horse]=
    gdk_pixbuf_new_from_file("res/B_Horse.png",&error);
    chessman_images[B_Chariot]=
    gdk_pixbuf_new_from_file("res/B_Chariot.png",&error);
    chessman_images[B_Soldier]=
    gdk_pixbuf_new_from_file("res/B_Soldier.png",&error);
    chessman_images[B_Cannon]=
    gdk_pixbuf_new_from_file("res/B_Cannon.png",&error);
    
    chessman_images[RED_KING_DIE]=
    gdk_pixbuf_new_from_file("res/red_king_die.png",&error);
    chessman_images[BLACK_KING_DIE]=
    gdk_pixbuf_new_from_file("res/black_king_die.png",&error);
    
    
    chessman_images[SELECTED_CHESSMAN]=
    gdk_pixbuf_new_from_file("res/select.png",&error);
    chessman_images[NULL_CHESSMAN]=
    gdk_pixbuf_new_from_file("res/null.png",&error);
    
    
    for(i=1;i<18;i++)
    if(!chessman_images[i])
    {
        g_print("error   %d\n",i);
        return FALSE ;
    }
    
    return TRUE ;
}

gboolean button_press_event_callback(GtkWidget*widget,GdkEventButton*event,gpointer data)
{
    
    int x=event->x ;
    int y=event->y ;
    int board_x,board_y ;
    int j ;
    //int src,des;
    static int click=1 ;
	static int temp;
    //if(chess_state.side_go==BLACK)
          //return FALSE;
 

    board_x=x/55 ;
    board_y=y/55 ;
     print_board();
    j=board_x+3+(board_y+3)*16 ;
	g_print("select  chess[j] click %d  \n",chessman_state[j]);    
    if(click%2==1)//第一次选中
    {
        if(chessman_state[j]<=0||chessman_state[j]>7)
        {

            return TRUE ;
        }
		/*	if(click!=1)
		{
				redraw_src(move->src_pos,widget);	
				gdk_draw_pixbuf(widget->window,NULL,chessman_images[move->src_chessman],0,0,
         	 	 55*(move->src_pos->board_x),55*(move->src_pos->board_y),57,57,
     	     	  GDK_RGB_DITHER_NORMAL,57,57);
		}*/
		
		//将选中棋子存入状态
 		draw_seleceted( board_x, board_y,widget);
		get_first_select(board_x,board_y,j,widget);       
		    }
    else 
    {
        if(chessman_state[j]>0&&chessman_state[j]<=7)//第二次选中自己的子，重新将这个子选中
        {            
		//	if(j==temp)
		//		return  FALSE;
            redraw_src(move->src_pos,widget);
			gdk_draw_pixbuf(widget->window,NULL,chessman_images[move->src_chessman],0,0,
         	 	 55*(move->src_pos->board_x),55*(move->src_pos->board_y),57,57,
     	     	  GDK_RGB_DITHER_NORMAL,57,57);
           	draw_seleceted( board_x, board_y,widget);
           // click--;            
            get_first_select(board_x,board_y,j,widget);
            return TRUE ;
        }
		
        red_move->des=board_x+3+(board_y+3)*16 ;
        red_move->src=move->src_pos->board_x+3+(move->src_pos->board_y+3)*16 ;

		g_print("\nisright  chess_src   %d\nisright  chess_des     %d   \n", red_move->src,red_move->des);

		
        if(!Isright(red_move))
		{
		 	redraw_src(move->src_pos,widget);
            gdk_draw_pixbuf(widget->window,NULL,chessman_images[move->src_chessman],0,0,
            55*(move->src_pos->board_x),55*(move->src_pos->board_y),57,57,
            GDK_RGB_DITHER_NORMAL,57,57);
			click--;
			return  TRUE;
		}
		
        chess_state.side_go=BLACK ;        
		
        chessman_state[red_move->des]=chessman_state[red_move->src];
		chessman_state[red_move->src]=0 ;                 
        
        redraw_src(move->src_pos,widget);
        //  gdk_draw_pixbuf (widget->window, NULL,
        //	       chessman_images[move->src_chessman], 0, 0,
        //	       55 * board_x, 55 * board_y, 57, 57,
        //	       GDK_RGB_DITHER_NORMAL, 57, 57);
		
        gdk_draw_pixbuf(widget->window,NULL,chessman_images[move->src_chessman],0,0,
        55*(board_x),55*(board_y),57,57,
        GDK_RGB_DITHER_NORMAL,57,57);
		
		// get_think(red_move,widget);
        g_print("draw   chess_src   %d\n  src_pos->board_x   %d   \nsrc_pos->board_y  %d\n",move->src_chessman,move->src_pos->board_x,move->src_pos->board_y);
        
    }
    
    click++;
    temp=j;
    return TRUE ;
    
}

void 
redraw_src(struct board*src_pos,GtkWidget*widget)
{
    GdkPixbuf*get_chessman ;
    get_chessman=gdk_pixbuf_new_subpixbuf(buf,
    55*(src_pos->board_x),
    55*(src_pos->board_y),
    57,
    57);
    gdk_draw_pixbuf(widget->window,NULL,get_chessman,0,0,
    55*(src_pos->board_x),55*(src_pos->board_y),57,57,
    GDK_RGB_DITHER_NORMAL,57,57);

	
    //	g_print ("draw   chess_src   %d\n  src_pos->board_x   %d   \nsrc_pos->board_y  %d\n", src_chessman,src_pos->board_x,src_pos->board_y);
}


void get_think(struct move*red_move,GtkWidget*widget)
{
   
    int board_x,board_y ;
    black_move=think(red_move);    
    move->src_pos->board_x=(black_move->src)%16-3 ;
    move->src_pos->board_y=(black_move->src)/16-3 ;
    
    redraw_src(move->src_pos,widget);
    
    board_x=(black_move->des)%16-3 ;
    board_y=(black_move->des)/16-3 ;  
	
    gdk_draw_pixbuf(widget->window,NULL,chessman_images[chessman_state[black_move->src]],0,0,    55*(board_x),55*(board_y),57,57,
    GDK_RGB_DITHER_NORMAL,57,57);

	g_print("chessman_state[black_move->src]  %d\n",chessman_state[black_move->src]);
    g_print("引擎的直接放回  x  %d\n",black_move->src);
    g_print("引擎的源  棋盘   x  %d   y   %d\n",move->src_pos->board_x,move->src_pos->board_y);
    //	g_print("get think   chessman_state[black_move->src]  %d    %d %d\n",chessman_state[black_move->src],board_x,board_y);
    //执行完这一步将由红方下
    chess_state.side_go=RED ;
    //修改棋盘状态
    chessman_state[black_move->des]=chessman_state[black_move->src];
    chessman_state[black_move->src]=0;
    
    gdk_draw_pixbuf(widget->window,NULL,chessman_images[SELECTED_CHESSMAN],
    0,0,55*board_x,55*board_y,57,57,
    GDK_RGB_DITHER_NORMAL,57,57);
    move->src_pos->board_x=(black_move->des)%16-3 ;
    move->src_pos->board_y=(black_move->des)/16-3 ;
    move->src_chessman=chessman_state[black_move->src];
}


void  get_first_select(int board_x,int board_y,int j,GtkWidget *widget)
{
		move->src_pos->board_x=board_x ;
        move->src_pos->board_y=board_y ;        
        move->src_chessman=chessman_state[j];		
       
}
void  draw_seleceted(int board_x,int board_y,GtkWidget *widget)
{ 
			gdk_draw_pixbuf(widget->window,NULL,chessman_images[SELECTED_CHESSMAN],
        	0,0,55*board_x,55*board_y,57,57,
       		 GDK_RGB_DITHER_NORMAL,57,57);
 		//	gdk_draw_pixbuf(widget->window,NULL,chessman_images[move->src_chessman],0,0,
          //  55*(move->src_pos->board_x),55*(move->src_pos->board_y),57,57,
            //GDK_RGB_DITHER_NORMAL,57,57);
}


void print_board()
{
		int i;

	g_print("callback\n");
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
