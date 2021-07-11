#include <msp430.h>
#include "stateMachines.h"
static char time = 0;
static char mode = 0;
static char blink_count = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  if(time == 249){ /*Iterates mode every second*/
    time = 0;
    mode++;
  }
  if(mode > 3){ /*Reset mode to beginning when reaching the last mode*/
    mode = 0;
  }
  else{
    if (++blink_count == 1) { /*Executes the brightness every 1 interrupt with current mode*/
      red_brightness(mode);
      time++;
      blink_count = 0;
    }
  }
}
