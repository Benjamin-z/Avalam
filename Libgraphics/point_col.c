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

/* $Id: point_col.c,v 1.1 2002/10/09 15:12:27 peskine Exp $ */

#include "libgraph.h"

unsigned long gr_point_color(int x, int y)
{
  XImage * im;
  int rgb;

  gr_check_open();
  im = XGetImage(grdisplay, grbstore.win, x, Bcvt(y), 1, 1, (-1), ZPixmap);
  rgb = gr_rgb_pixel(XGetPixel(im, 0, 0));
  XDestroyImage(im);
  return rgb;
}

                     
