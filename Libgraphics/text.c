/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  en Automatique.  Distributed only by permission.                   */
/*                                                                     */
/***********************************************************************/

/* $Id: text.c,v 1.1 2002/10/09 15:12:28 peskine Exp $ */

// Pour les fonctions strlen
#include <string.h>
#include "libgraph.h"

XFontStruct * grfont = NULL;

static void gr_font(char *fontname)
{
  XFontStruct * font = XLoadQueryFont(grdisplay, fontname);
  if (font == NULL) gr_fail("cannot find font %s", fontname);
  if (grfont != NULL) XFreeFont(grdisplay, grfont);
  grfont = font;
  XSetFont(grdisplay, grwindow.gc, grfont->fid);
  XSetFont(grdisplay, grbstore.gc, grfont->fid);
}

void gr_set_font(char *fontname)
{
  gr_check_open();
  gr_font(fontname);
}

void gr_set_text_size (int z)
{
}

static void gr_draw_text(char *txt, int len)
{
  if (grfont == NULL) gr_font(DEFAULT_FONT);
  XDrawString(grdisplay, grwindow.win, grwindow.gc,
              grx, Wcvt(gry) - grfont->descent + 1, txt, len);
  XDrawString(grdisplay, grbstore.win, grbstore.gc,
              grx, Bcvt(gry) - grfont->descent + 1, txt, len);
  grx += XTextWidth(grfont, txt, len);
  XFlush(grdisplay);
}

void gr_draw_char(char chr)
{
  char str[1];
  gr_check_open();
  str[0] = chr;
  gr_draw_text(str, 1);
}
  
void gr_draw_string(char *str)
{
  gr_check_open();
  gr_draw_text(str, strlen(str));
}

void gr_text_size(char *str, int *w, int *h)
{
  gr_check_open();
  if (grfont == NULL) gr_font(DEFAULT_FONT);
  *w = XTextWidth(grfont, str, strlen(str));
  *h = grfont->ascent + grfont->descent;
}
