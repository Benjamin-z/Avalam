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

/* $Id: events.c,v 1.1 2002/10/09 15:12:25 peskine Exp $ */

#include <stdlib.h>
#include <signal.h>
#include "libgraph.h"

static unsigned char gr_queue[SIZE_QUEUE];
static int gr_head = 0;       /* position of next read */
static int gr_tail = 0;       /* position of next write */

#define QueueIsEmpty (gr_head == gr_tail)
#define QueueIsFull  (gr_head == gr_tail + 1)

void gr_enqueue_char(unsigned char c)
{
  if (QueueIsFull) return;
  gr_queue[gr_tail] = c;
  gr_tail++;
  if (gr_tail >= SIZE_QUEUE) gr_tail = 0;
}

struct status* gr_wait_event(int eventmask)
{
  struct status *res;
  int mask;
  Bool poll;
  int mouse_x, mouse_y, button, key;
  Window rootwin, childwin;
  int root_x, root_y, win_x, win_y;
  unsigned int modifiers;
#ifdef POSIX_SIGNALS
  struct sigaction sigact, oldsig;
#else
  void (*oldsig)();
#endif
  XEvent event;

  gr_check_open();
  mask = 0;
  poll = False;
  if (eventmask & BUTTON_DOWN)
    mask |= ButtonPressMask | OwnerGrabButtonMask;
  if (eventmask & BUTTON_UP)
    mask |= ButtonReleaseMask | OwnerGrabButtonMask;
  if (eventmask & KEY_PRESSED)
    mask |= KeyPressMask;
  if (eventmask & MOUSE_MOTION)
      mask |= PointerMotionMask;
  if (eventmask & POLL)
      poll = True;

  mouse_x = -1;
  mouse_y = -1;
  button = 0;
  key = 0x100;

  if (poll) {
    if (XQueryPointer(grdisplay, grwindow.win,
                      &rootwin, &childwin,
                      &root_x, &root_y, &win_x, &win_y,
                      &modifiers)) {
      mouse_x = win_x;
      mouse_y = win_y;
    }
    button = modifiers & Button1Mask;
    if (!QueueIsEmpty) key = gr_queue[gr_head];
  } else {
    if ((mask & KeyPressMask) && !QueueIsEmpty) {
      key = gr_queue[gr_head];
      gr_head++;
      if (gr_head >= SIZE_QUEUE) gr_head = 0;
    } else {
#ifdef POSIX_SIGNALS
      sigact.sa_handler = SIG_IGN;
      sigaction(EVENT_SIGNAL, &sigact, &oldsig);
#else
      oldsig =  (void (*)()) signal(EVENT_SIGNAL, SIG_IGN);
#endif
      XSelectInput(grdisplay, grwindow.win, DEFAULT_EVENT_MASK | mask);
    again:
      XNextEvent(grdisplay, &event);
      switch(event.type) {
      case ButtonPress:
      case ButtonRelease:
        mouse_x = event.xbutton.x;
        mouse_y = event.xbutton.y;
        button = event.type == ButtonPress;
        break;
      case MotionNotify:
        mouse_x = event.xmotion.x;
        mouse_y = event.xmotion.y;
        button = event.xmotion.state & Button1Mask;
        break;
      case KeyPress:
        gr_handle_simple_event(&event);
        /* Some KeyPress events do not enqueue any characters (e.g. pressing
           Ctrl), because they expand via XLookupString to the empty string.
           Therefore we need to check again whether the char queue is empty. */
        if ((mask & KeyPressMask) == 0 || QueueIsEmpty) goto again;
        key = gr_queue[gr_head];
        gr_head++;
        if (gr_head >= SIZE_QUEUE) gr_head = 0;
        break;
      default:
        gr_handle_simple_event(&event);
        goto again;
      }
#ifdef POSIX_SIGNALS
      sigaction(EVENT_SIGNAL, &oldsig, NULL);
#else
      signal(EVENT_SIGNAL, (void (*)(int)) oldsig);
#endif
      XSelectInput(grdisplay, grwindow.win, DEFAULT_EVENT_MASK);
      XFlush(grdisplay);
    }
  }
  res = (struct status *) malloc(sizeof(struct status));
  res->mouse_x = mouse_x;
  res->mouse_y = (mouse_y == -1 ? -1 : Wcvt(mouse_y));
  res->button = button;
  res->key_pressed = (key != 0x100);
  res->key = key & 0xFF;
  return res;
}

void gr_mouse_pos(int *x, int *y)
{
  struct status * st;
  st = gr_wait_event(POLL);
  *x = st->mouse_x;
  *y = st->mouse_y;
}

Bool gr_button_down(void)
{
  struct status * st;
  st = gr_wait_event(POLL);
  return st->button;
}

Bool gr_key_pressed(void)
{
  struct status * st;
  st = gr_wait_event(POLL);
  return st->key_pressed;
}

char gr_read_key(void)
{
  struct status * st;
  st = gr_wait_event(KEY_PRESSED);
  return st->key;
}

