#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

/*Tones*/
#define t1 2500
#define t2 3000
#define t3 2800
#define t4 3900
#define t5 4300
#define t6 3400

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
  led_update();
}
void disable_green(){ /*Turns off the green LED*/
  green_on = 0;
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
void red_dim(){ /*Dim brightness for red LED*/
  
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



void green_bright(){ /*Bright brightness for green LED*/
  
  switch (state) {
  case 0:
    enable_green();
    state = 1;
    break;
  case 1:
    enable_green();
    state = 2;
    break;
  case 2:
    disable_green();
    state = 0;
    break;
  }
}
void green_medium(){ /*Medium brightness for green LED*/
  
  switch (state) {
  case 0:
    enable_green();
    state = 1;
    break;
  case 1:
    disable_green();
    state = 0;
    break;
  }
}
void green_dim(){ /*Dim brightness for green LED*/
  
  switch (state) {
  case 0:
    enable_green();
    state = 1;
    break;
  case 1:
    disable_green();
    state = 2;
    break;
  case 2:
    disable_green();
    state = 0;
    break;
  }
}




void red_brightness(int brightness){ /*Selects a brightness mode for red LED*/
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
void green_brightness(int brightness){ /*Selects a brightness mode for green LED*/
  switch(brightness){
  case 0:
    green_bright();
    break;
  case 1:
    green_medium();
    break;
  case 2:
    green_dim();
    break;
  case 3:
    disable_green();
    break;
  }
}



void light_alternate2(int state){ /*Flashes the green and red LEDs*/
  switch(state){
  case 0:
    green_bright();
    red_dim();
    state = 1;
    break;
  case 1:
    green_medium();
    red_medium();
    state = 2;
    break;
  case 2:
    green_dim();
    red_bright();
    state = 3;
    break;
  case 3:
    red_medium();
    green_medium();
    state = 4;
    break;
  case 4:
    red_dim();
    green_bright();
    state = 5;
    break;
  case 5:
    red_medium();
    green_medium();
    state = 6;
    break;
  case 6:
    red_bright();
    green_bright();
    break;
    state = 0;
  }
}


void song2(int state){ /*Plays a simple tune*/
  
  switch(state){
  case 0:
    buzzer_set_period(t1);
    state = 1;
    break;
  case 1:
    buzzer_set_period(0);
    state = 2;
    break;
  case 2:
    buzzer_set_period(t2);
    state = 3;
    break;
  case 3:
    buzzer_set_period(0);
    state = 4;
    break;
  case 4:
    buzzer_set_period(t3);
    state = 5;
    break;
  case 5:
    buzzer_set_period(0);
    state = 6;
    break;
  case 6:
    buzzer_set_period(t4);
    state = 7;
    break;
  case 7:
    buzzer_set_period(0);
    state = 8;
    break;
  case 8:
    buzzer_set_period(t5);
    state = 9;
    break;
  case 9:
    buzzer_set_period(0);
    state = 10;
    break;
  case 10:
    buzzer_set_period(t4);
    state = 11;
    break;
  case 11:
    buzzer_set_period(0);
    state = 12;
    break;
  case 12:
    buzzer_set_period(t6);
    state = 12;
    break;
  case 13:
    buzzer_set_period(0);
    state = 0;
    break;
  }
}

void disable_everything(){ /*Turn off LEDs and speaker*/
  disable_red();
  disable_green();
  buzzer_set_period(0);
}
