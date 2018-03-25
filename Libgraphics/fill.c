/***********************************************************************/
/*                                                                     */
/*                           Objective Caml                            */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1996 Institut National de Recherche en Informatique et   */
/*  Automatique.  Distributed only by permission.                      */
/*                                                                     */
/***********************************************************************/

/* $Id: fill.c,v 1.1 2002/10/09 15:12:25 peskine Exp $ */

#include <stdlib.h>
#include "libgraph.h"

void gr_fill_rect(int x, int y, int w, int h)
{
  gr_check_open();
  XFillRectangle(grdisplay, grwindow.win, grwindow.gc,
                 x, Wcvt(y) - h + 1, w, h);
  XFillRectangle(grdisplay, grbstore.win, grbstore.gc,
                 x, Bcvt(y) - h + 1, w, h);
  XFlush(grdisplay);
}





void gr_fill_poly(int* array, int npoints)
{
  XPoint * points;
  int i;

  gr_check_open();
  points = (XPoint *) malloc(npoints * sizeof(XPoint));
  for (i = 0; i < npoints; i++) {
    points[i].x = array[2*i];
    points[i].y = array[2*i+1];
  }
  for (i = 0; i < npoints; i++) {
    points[i].y = grwindow.h-points[i].y-1;
  }
  XFillPolygon(grdisplay, grwindow.win, grwindow.gc, points,
               npoints, Complex, CoordModeOrigin);
  XFillPolygon(grdisplay, grbstore.win, grbstore.gc, points,
               npoints, Complex, CoordModeOrigin);
  XFlush(grdisplay);
  free((char *) points);
}

void gr_fill_arc(int x, int y, int rx, int ry, int a1, int a2)
{
  gr_check_open();
  XFillArc(grdisplay, grwindow.win, grwindow.gc,
           x - rx, Wcvt(y) - ry, rx * 2, ry * 2, a1 * 64, (a2 - a1) * 64);
  XFillArc(grdisplay, grbstore.win, grbstore.gc,
           x - rx, Bcvt(y) - ry, rx * 2, ry * 2, a1 * 64, (a2 - a1) * 64);
  XFlush(grdisplay);
}

void gr_fill_ellipse(int x, int y, int rx, int ry)
{
  gr_fill_arc(x,y,rx,ry,0,360);
}

void gr_fill_circle(int x, int y, int r)
{
  gr_fill_arc(x,y,r,r,0,360);
}
