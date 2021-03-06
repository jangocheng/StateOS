/******************************************************************************

    @file    StateOS: osnasa.h
    @author  Rajmund Szymanski
    @date    24.01.2018
    @brief   NASA OSAPI implementation for StateOS.

 ******************************************************************************

   Copyright (c) 2018 Rajmund Szymanski. All rights reserved.

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.

 ******************************************************************************/

#ifndef __STATEOSNASA_H
#define __STATEOSNASA_H

#include <os.h>
#include <osapi.h>

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */
/*
** queues
*/
typedef struct
{
	box_t  box;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
}	OS_queue_record_t;

/* -------------------------------------------------------------------------- */
/*
** binary semaphores
*/
typedef struct
{
	sem_t  sem;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
}	OS_bin_sem_record_t;

/* -------------------------------------------------------------------------- */
/*
** counting semaphores
*/
typedef struct
{
	sem_t  sem;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
}	OS_count_sem_record_t;

/* -------------------------------------------------------------------------- */
/*
** mutexes
*/
typedef struct
{
	mtx_t  mtx;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
}	OS_mut_sem_record_t;

/* -------------------------------------------------------------------------- */
/*
** tasks
*/
typedef struct
{
	tsk_t  tsk;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
	void (*handler)(void);
	void (*delete_handler)(void);
}	OS_task_record_t;

/* -------------------------------------------------------------------------- */
/*
** timers
*/
typedef struct
{
	tmr_t  tmr;
	char   name [OS_MAX_API_NAME];
	uint32 creator;
	uint32 used;
	void (*handler)(uint32);
}	OS_timer_record_t;

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------------- */

#endif//__STATEOSNASA_H
