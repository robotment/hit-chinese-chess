
/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 * main.c
 * Copyright (C) fantasy 2009 <fantasy@>
	 * 
 * main.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
	 * 
 * main.c is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */




#include<gtk/gtk.h>
#include "draw.h" 



/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS 
#include<libintl.h>
#undef _ 
#define _(String)dgettext(PACKAGE,String)
#ifdef gettext_noop 
#define N_(String)gettext_noop(String)
#else 
#define N_(String)(String)
#endif 
#else 
#define textdomain(String)(String)
#define gettext(String)(String)
#define dgettext(Domain,Message)(Message)
#define dcgettext(Domain,Message,Type)(Message)
#define bindtextdomain(Domain,Directory)(Domain)
#define _(String)(String)
#define N_(String)(String)
#endif 



extern void chess_run();

int 
main(int argc,char*argv[])
{
    #ifdef ENABLE_NLS 
    bindtextdomain(GETTEXT_PACKAGE,PACKAGE_LOCALE_DIR);
    bind_textdomain_codeset(GETTEXT_PACKAGE,"UTF-8");
    textdomain(GETTEXT_PACKAGE);
    #endif 
    gtk_set_locale();
    gtk_init(&argc,&argv);
    
    chess_run();
    
    gtk_main();
    return 0 ;
}
