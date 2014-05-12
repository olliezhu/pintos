#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>
#include <list.h>

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
int64_t timer_elapsed (int64_t);

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

/* Alarm structure. */
//extern static struct list alarm_list;
static struct list alarm_list;

struct alarm
  {
    struct thread *thread;     /* the thread this alarm will go off for */
    int64_t wake_tick;      /* timer_ticks() */

    struct list_elem elem;  /* for alarm_list */
  };

void set_alarm (int64_t wake_tick);
void alarm_off (struct alarm *a);

#endif /* devices/timer.h */
