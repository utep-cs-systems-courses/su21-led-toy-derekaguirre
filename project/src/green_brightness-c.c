#include <msp430.h>
#include "led.h"

void green_bright();
void green_medium();
void green_dim();
void disable_green();
/*argument?*/
/*Selects a brightness mode for green LED*/
void green_brightness(int brightness){ 
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
