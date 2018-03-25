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

/* $Id: make_img.c,v 1.1 2002/10/09 15:12:26 peskine Exp $ */

#include <stdlib.h>
#include "libgraph.h"
#include "image.h"

typedef unsigned long color;

struct grimage* gr_make_image(color* m, int width, int height)
{
  struct grimage* im;
  Bool has_transp;
  XImage * idata, * imask;
  char * bdata, * bmask;
  int i, j, rgb, p;
  GC gc;

  gr_check_open();
  if (height == 0) return gr_new_image(0, 0);

  /* Build an XImage for the data part of the image */
  idata =
    XCreateImage(grdisplay, DefaultVisual(grdisplay, grscreen),
                 XDefaultDepth(grdisplay, grscreen),
                 ZPixmap, 0, NULL, width, height,
                 BitmapPad(grdisplay), 0);

  /* To optimize RGB => color id calculation */
  if( !direct_rgb ){
    /* they are declared in color.c */
    byte_order = idata->byte_order;
    bitmap_unit = idata->bitmap_unit;
    bits_per_pixel = idata->bits_per_pixel;
#ifdef DIRECT_RGB_DEBUG
    fprintf(stderr, "Byte_order: %d = %s\n", byte_order,
	    byte_order ? "LSBFirst" : "MSBFirst");
    fprintf(stderr, "Bitmp_unit: %d\n", bitmap_unit);
    fprintf(stderr, "Bits per pixel: %d\n", idata->bits_per_pixel);
#endif
    direct_rgb = True;
  }

  bdata = (char *) malloc(height * idata->bytes_per_line);
  idata->data = bdata;
  has_transp = False;

  p = 0;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      rgb = (int) m[p++];
      if (rgb == Transparent) { has_transp = True; rgb = 0; }
      XPutPixel(idata, j, i, gr_pixel_rgb(rgb));
    }
  }

  /* If the matrix contains transparent points,
     build an XImage for the mask part of the image */
  if (has_transp) {
    imask =
      XCreateImage(grdisplay, DefaultVisual(grdisplay, grscreen),
                   1, ZPixmap, 0, NULL, width, height,
                   BitmapPad(grdisplay), 0);
    bmask = (char *) malloc(height * imask->bytes_per_line);
    imask->data = bmask;

    p = 0;
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        rgb = (int) m[p++];
        XPutPixel(imask, j, i, rgb != Transparent);
      }
    }
  } else {
    imask = NULL;
  }

  /* Allocate the image and store the XImages into the Pixmaps */
  im = gr_new_image(width, height);
  gc = XCreateGC(grdisplay, Data_im(im), 0, NULL);
  XPutImage(grdisplay, Data_im(im), gc, idata, 0, 0, 0, 0, width, height);
  XDestroyImage(idata);
  XFreeGC(grdisplay, gc);
  if (has_transp) {
    Mask_im(im) = XCreatePixmap(grdisplay, grwindow.win, width, height, 1);
    gc = XCreateGC(grdisplay, Mask_im(im), 0, NULL);
    XPutImage(grdisplay, Mask_im(im), gc, imask, 0, 0, 0, 0, width, height);
    XDestroyImage(imask);
    XFreeGC(grdisplay, gc);
  }
  XFlush(grdisplay);
  return im;
}

