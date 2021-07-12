#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"

static char mode = 0;
static char blink_count = 0;
static char time = 0;

char switch_state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  // static char time = 0;
  
  
  
  /*Button functionality*/
  if(switch_state == 0){ /*First switch(Turns green LED on)*/
    enable_green();
  }
  else if (switch_state == 1){ /*Second switch (Flashes LEDs)*/

    if(time == 62){ /*Iterates mode every third of a second*/
      time = 0;
      mode++;
    }
    else if(mode > 3){ /*Reset mode to beginning when reaching the last mode*/
      mode = 0;
    }
    else{ /*Executes methods every 1 interrupt with current mode*/
      if(++blink_count == 1){
	red_brightness(mode);
	green_brightness(mode);
	time++;
	blink_count = 0;
      }
    }
    
  }
  else if (switch_state == 2){ /*Third switch (Plays jingle and flashes LEDs)*/
    
    if(time == 42){ /*Iterates mode every sixth of a second*/
      time = 0;
      mode++;
    }
    else if(mode > 13){ /*Reset mode to beginning when reaching the last mode*/
      mode = 0;
    }
    else{ /*Executes methods every 1 interrupt with current mode*/
      if(++blink_count == 1){
	song2(mode);
	light_alternate2(mode);
	time++;
	blink_count = 0;
      }
    }
    
  }
  else if (switch_state == 3){ /*Fourth switch (Turns off speaker and LEDs)*/
    disable_everything(); 
  }
}
