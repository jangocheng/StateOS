/******************************************************************************

    @file    StateOS: oscore.c
    @author  Rajmund Szymanski
    @date    08.12.2016
    @brief   StateOS port file for ARM Cotrex-M uC.

 ******************************************************************************

    StateOS - Copyright (C) 2013 Rajmund Szymanski.

    This file is part of StateOS distribution.

    StateOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation; either version 3 of the License,
    or (at your option) any later version.

    StateOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#if defined(__ARMCOMPILER_VERSION)

#include <stddef.h>
#include <oskernel.h>

/* -------------------------------------------------------------------------- */

__attribute__((naked))
void PendSV_Handler( void )
{
	__asm volatile
	(
#if __CORTEX_M < 3

"	mrs   r0,    PSP               \n"
"	subs  r0,  # 36                \n"
"	stm   r0!, { r4  - r7 }        \n"
"	mov   r3,    r8                \n"
"	mov   r4,    r9                \n"
"	mov   r5,    r10               \n"
"	mov   r6,    r11               \n"
"	mov   r7,    lr                \n"
"	stm   r0!, { r3  - r7 }        \n"
"	subs  r0,  # 36                \n"

#else //__CORTEX_M

"	mrs   r0,    PSP               \n"
#if __FPU_USED
"	tst   lr,  # 16                \n"
"	it    eq                       \n"
"vstmdbeq r0!, { s16 - s31 }       \n"
#endif
"	stmdb r0!, { r4  - r11, lr }   \n"

#endif//__CORTEX_M

"	bl    core_tsk_handler         \n"

#if __CORTEX_M < 3

"	adds  r0,  # 16                \n"
"	ldm   r0!, { r3  - r7 }        \n"
"	mov   r8,    r3                \n"
"	mov   r9,    r4                \n"
"	mov   r10,   r5                \n"
"	mov   r11,   r6                \n"
"	mov   lr,    r7                \n"
"	subs  r0,  # 36                \n"
"	ldm   r0!, { r4  - r7 }        \n"
"	adds  r0,  # 20                \n"
"	msr   PSP,   r0                \n"
"	bx    lr                       \n"

#else //__CORTEX_M

"	ldmia r0!, { r4  - r11, lr }   \n"
#if __FPU_USED
"	tst   lr,  # 16                \n"
"	it    eq                       \n"
"vldmiaeq r0!, { s16 - s31 }       \n"
#endif
"	msr   PSP,   r0                \n"
"	bx    lr                       \n"

#endif//__CORTEX_M

:::	"memory"
	);
}

/* -------------------------------------------------------------------------- */

__attribute__((naked))
void core_tsk_flip()
{
	__asm volatile
	(
"	mov   sp,    r0                \n"
"	bl    core_tsk_break           \n"
	
:::	"memory"
	);
}
	
/* -------------------------------------------------------------------------- */

#endif // __ARMCOMPILER_VERSION
