#include <msp430.h>
#include "stateMachines.h"
#include "led.h"

static char state = 0;

void enable_red(){ /*Turns on red LED*/
  red_on = 1;
  led_changed = 1;
  led_update();
}
void disable_red(){ /*Turns off the red LED*/
  red_on = 0;
  led_changed = 1;
  led_update();
}
void enable_green(){ /*Turns on the green LED*/
  green_on = 1;
  led_changed = 1;
  led_update();
}
void disable_green(){ /*Turns off the green LED*/
  green_on = 0;
  led_changed = 1;
  led_update();
}



void red_bright(){ /*Bright brightness for red LED*/
  
  switch (state) {
  case 0:
    enable_red();
    state = 1;
    break;
  case 1:
    enable_red();
    state = 2;
    break;
  case 2:
    disable_red();
    state = 0;
    break;
  }
}

void red_medium(){ /*Medium brightness for red LED*/
  
  switch (state) {
  case 0:
    enable_red();
    state = 1;
    break;
  case 1:
    disable_red();
    state = 0;
    break;
  }
}
void red_dim(){ /*Medium brightness for red LED*/
  
  switch (state) {
  case 0:
    enable_red();
    state = 1;
    break;
  case 1:
    disable_red();
    state = 2;
    break;
  case 2:
    disable_red();
    state = 0;
    break;
  }
}

void red_brightness(int brightness){ /*Selects a brightness mode*/
  switch(brightness){
  case 0:
    red_bright();
    break;
  case 1:
    red_medium();
    break;
  case 2:
    red_dim();
    break;
  case 3:
    disable_red();
    break;
  }
}
