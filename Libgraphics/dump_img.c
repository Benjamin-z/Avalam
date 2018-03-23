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

/* $Id: dump_img.c,v 1.1 2002/10/09 15:12:24 peskine Exp $ */

#include <stdlib.h>
#include "libgraph.h"
#include "image.h"

typedef unsigned long color;

color* gr_dump_image(struct grimage* image)
{
  int width, height, i, j, p;
  XImage * idata, * imask;
  color* m;

  gr_check_open();
  width = Width_im(image);
  height = Height_im(image);
  m = (color*) malloc(width * height);

  idata =
    XGetImage(grdisplay, Data_im(image), 0, 0, width, height, (-1), ZPixmap);
  p = 0;
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      m[p++] = gr_rgb_pixel(XGetPixel(idata, j, i));
  XDestroyImage(idata);

  if (Mask_im(image) != None) {
    imask =
      XGetImage(grdisplay, Mask_im(image), 0, 0, width, height, 1, ZPixmap);
    p = 0;
    for (i = 0; i < height; i++)
      for (j = 0; j < width; j++)
	if (XGetPixel(imask, j, i) == 0)
	  m[p++] = Transparent;
    XDestroyImage(imask);
  }
  return m;
}


    
