
/*
 * callbacks.h
 * Copyright (C) fantasy 2009 <fantasy@>
 * 
 * callbacks.h is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * callbacks.h is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef _CALLBACK_H 
#define _CALLBACK_H 
//#include "globe.h"
//#include <gtk/gtk.h>

struct board 
{
    int board_x ;
    int board_y ;
};

struct _move 
{
    struct board*src_pos ;
    int src_chessman ;
    struct board*des_pos ;
    int des_chessman ;
}
*move ;
struct move*red_move,*black_move ;

GdkPixbuf* chessman_images[20];
GdkPixbuf* buf ;
gboolean read_image();
void init_board(GtkWidget*widget);
void destroy_callback(GtkWidget*widget,gpointer data);
gboolean 
expose_event_callback(GtkWidget*widget,GdkEventExpose*event,
gpointer data);

gboolean
button_press_event_callback(GtkWidget*widget,
GdkEventButton*event,
gpointer data);
void draw_chessman(GtkWidget*widget);
void init_chess();
void redraw_src(struct board*src_pos,GtkWidget*widget);
void get_think(struct move*red_move,GtkWidget*widget);
void  get_first_select(int board_x,int board_y,int j,GtkWidget *widget);
void  draw_seleceted(int board_x,int board_y,GtkWidget *widget);
void print_board();

#endif
