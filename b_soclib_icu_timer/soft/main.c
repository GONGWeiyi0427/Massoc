/*
 *
 * SOCLIB_GPL_HEADER_BEGIN
 *
 * This file is part of SoCLib, GNU GPLv2.
 *
 * SoCLib is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * SoCLib is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SoCLib; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * SOCLIB_GPL_HEADER_END
 *
 * Copyright (c) UPMC, Lip6, SoC
 *         Nicolas Pouillon <nipo@ssji.net>, 2006-2007
 *
 * Maintainers: nipo
 */

#include "system.h"

#include "../segmentation.h"

#include "soclib/icu.h"
#include <stdio.h>
//Add timer library
#include "soclib/timer.h"

//Period for timer
static const int period = 300000;

//Interruption flag
volatile static uint32_t irq_flag;


volatile static uint32_t cptms=0;

void irq_handler(int irq)
{
  // TME exercise: write the ISR for the timer interrupt.
  // Refer to the ICU specification.
  uint32_t interrupt_vector;
  uint32_t timer;

  cptms++;
  cptms=cptms%10;
  printf("irq cptms=%d\n", cptms);

  interrupt_vector = soclib_io_get(base(ICU), ICU_IT_VECTOR);

  switch (interrupt_vector)
    {
    case 0:
      //Get the timer value
      timer = soclib_io_get(base(TIMER), 0*TIMER_SPAN+TIMER_VALUE);
      // Reset the timer interrupts
      soclib_io_set(base(TIMER), 0*TIMER_SPAN+TIMER_RESETIRQ, 0);
      irq_flag=1;
      break;
    }


}

int main(void)
{
  // TME exercise: setup interrupt handler.
  irq_flag=0;     //Set flag to 0

  set_irq_handler(irq_handler);     //Set irq handler

  printf("Node 0 says hello !\n");

  // TME exercise: setup the ICU and enable timer0 interrupt.
  soclib_io_set(base(ICU), ICU_MASK_SET, 1);                                              //Mask the ICU
  soclib_io_set(base(TIMER), 0*TIMER_SPAN+TIMER_PERIOD, period);                          //Set timer parameter
  soclib_io_set(base(TIMER), 0*TIMER_SPAN+TIMER_MODE, TIMER_RUNNING|TIMER_IRQ_ENABLED);   //Run the timer and enable the interrution
  // TME exercise: enable interrupts.
  enable_hw_irq(0);     //Enable hardware interrupts
  irq_enable();

  while (1)
    {
      // TME exercise: fill-in infinite loop.
      // Wait for the interrupt signal and set to 0
      if (irq_flag==1)
        {
          irq_flag=0;
        }
    }

  return 0;
}
