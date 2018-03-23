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

/* $Id: draw.c,v 1.1 2002/10/09 15:12:24 peskine Exp $ */

#include "libgraph.h"

void gr_plot(int x, int y)
{
  gr_check_open();
  XDrawPoint(grdisplay, grwindow.win, grwindow.gc, x, Wcvt(y));
  XDrawPoint(grdisplay, grbstore.win, grbstore.gc, x, Bcvt(y));
  XFlush(grdisplay);
}

void gr_moveto(int x, int y)
{
  grx = x;
  gry = y;
}

void gr_current_point(int *x, int *y)
{
  *x = grx;
  *y = gry;
}

void gr_lineto(int x, int y)
{
  gr_check_open();
  XDrawLine(grdisplay, grwindow.win, grwindow.gc,
            grx, Wcvt(gry), x, Wcvt(y));
  XDrawLine(grdisplay, grbstore.win, grbstore.gc,
            grx, Bcvt(gry), x, Bcvt(y));
  grx = x;
  gry = y;
  XFlush(grdisplay);
}

void gr_draw_arc(int x, int y, int rx, int ry, int a1, int a2)
{
  gr_check_open();
  XDrawArc(grdisplay, grwindow.win, grwindow.gc,
           x - rx, Wcvt(y) - ry, rx * 2, ry * 2, a1 * 64, (a2 - a1) * 64);
  XDrawArc(grdisplay, grbstore.win, grbstore.gc,
           x - rx, Bcvt(y) - ry, rx * 2, ry * 2, a1 * 64, (a2 - a1) * 64);
  XFlush(grdisplay);
}

void gr_draw_ellispe(int x, int y, int rx, int ry)
{
  gr_draw_arc(x,y,rx,ry,0,360);
}

void gr_draw_circle(int x, int y, int r)
{
  gr_draw_arc(x,y,r,r,0,360);
}

void gr_set_line_width(int width)
{
  gr_check_open();
  XSetLineAttributes(grdisplay, grwindow.gc,
                     width, LineSolid, CapRound, JoinRound);
  XSetLineAttributes(grdisplay, grbstore.gc,
                     width, LineSolid, CapRound, JoinRound);
}


void gr_draw_poly(int* array, int npoints)
{ int i;
  gr_moveto(array[0],array[1]);
  for ( i=1; i<npoints ; i++)
    gr_lineto(array[2*i],array[2*i+1]);
}
