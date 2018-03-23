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

/* $Id: image.c,v 1.1 2002/10/09 15:12:25 peskine Exp $ */

#include <stdlib.h>
#include "libgraph.h"
#include "image.h"

static void gr_free_image(struct grimage *im)
{
  XFreePixmap(grdisplay, Data_im(im));
  if (Mask_im(im) != None) XFreePixmap(grdisplay, Mask_im(im));
}

#define Max_image_mem 1000000

struct grimage* gr_new_image(int w, int h)
{
  struct grimage *res = malloc(sizeof(struct grimage));
  Width_im(res) = w;
  Height_im(res) = h;
  Data_im(res) = XCreatePixmap(grdisplay, grwindow.win, w, h, 
                               XDefaultDepth(grdisplay, grscreen));
  Mask_im(res) = None;
  return res;
}

struct grimage* gr_create_image(int w, int h)
{
  gr_check_open();
  return gr_new_image(w, h);
}

void gr_blit_image(struct grimage *im, int x, int y)
{
  gr_check_open();
  XCopyArea(grdisplay, grbstore.win, Data_im(im), grbstore.gc,
            x, Bcvt(y) + 1 - Height_im(im),
            Width_im(im), Height_im(im),
            0, 0);
}

void gr_draw_image(struct grimage* im, int x, int y)
{
  int wy = Wcvt(y) + 1 - Height_im(im);
  int by = Bcvt(y) + 1 - Height_im(im);

  gr_check_open();
  if (Mask_im(im) != None) {
    XSetClipOrigin(grdisplay, grwindow.gc, x, wy);
    XSetClipMask(grdisplay, grwindow.gc, Mask_im(im));
    XSetClipOrigin(grdisplay, grbstore.gc, x, by);
    XSetClipMask(grdisplay, grbstore.gc, Mask_im(im));
  }
  XCopyArea(grdisplay, Data_im(im), grwindow.win, grwindow.gc,
            0, 0,
            Width_im(im), Height_im(im),
            x, wy);
  XCopyArea(grdisplay, Data_im(im), grbstore.win, grbstore.gc,
            0, 0,
            Width_im(im), Height_im(im),
            x, by);
  if (Mask_im(im) != None) {
    XSetClipMask(grdisplay, grwindow.gc, None);
    XSetClipMask(grdisplay, grbstore.gc, None);
  }
  XFlush(grdisplay);
}

struct grimage* gr_get_image(int x, int y, int w, int h)
{
  struct grimage* im;

  im = gr_create_image(w,h);
  gr_blit_image(im,x,y);
  return im;
}
            
