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

/* $Id: sound.c,v 1.1 2002/10/09 15:12:28 peskine Exp $ */

#include "libgraph.h"

void gr_sound(int freq, int dur)
{
  XKeyboardControl kbdcontrol;

  gr_check_open();
  kbdcontrol.bell_pitch = freq;
  kbdcontrol.bell_duration = dur;
  XChangeKeyboardControl(grdisplay, KBBellPitch | KBBellDuration,
                         &kbdcontrol);
  XBell(grdisplay, 0);
  kbdcontrol.bell_pitch = -1;   /* restore default value */
  kbdcontrol.bell_duration = -1; /* restore default value */
  XChangeKeyboardControl(grdisplay, KBBellPitch | KBBellDuration,
                         &kbdcontrol);
  XFlush(grdisplay);
}


