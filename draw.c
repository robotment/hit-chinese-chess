/***************************************************************************
 *            draw.c
 *
 *  Thu Jun 11 10:08:30 2009
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
/*
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <config.h>
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include <glade/glade.h>
#include  "draw.h"
#include  "callbacks.h"
//#include  "globe.h"

#define GLADE_FILE "res/gmchess.glade"
//side_go=RED;

void
chess_run ()
{
  GtkWidget *window, *draw_area;

  GladeXML *gxml;

  if (!read_image ())
    return;
  init_chess ();
  gxml = glade_xml_new (GLADE_FILE, NULL, NULL);
  window = glade_xml_get_widget (gxml, "window");
  if (!window)
    return;
  glade_xml_signal_autoconnect (gxml);
  draw_area = glade_xml_get_widget (gxml, "drawingarea1");
  //  必须在这里改变图片大小，否则重绘问题
  gtk_drawing_area_size ((GtkDrawingArea *) draw_area, 500, 556);
  g_signal_connect (G_OBJECT (draw_area), "expose_event",
		    G_CALLBACK (expose_event_callback), NULL);
  //init_board(draw_area);
  g_signal_connect (G_OBJECT (window), "destroy",
		    G_CALLBACK (destroy_callback), NULL);

  //添加draw_area的鼠标响应
  gtk_widget_add_events (draw_area, GDK_BUTTON_PRESS_MASK);

  g_signal_connect (G_OBJECT (draw_area), "button_press_event",
		    G_CALLBACK (button_press_event_callback), NULL);

  gtk_widget_show (window);
//	 gtk_window_stick (window->window);
  gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER_ALWAYS);
	
}
