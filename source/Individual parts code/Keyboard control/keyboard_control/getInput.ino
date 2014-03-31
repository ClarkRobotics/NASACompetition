#include <stdio.h>

void getInput() {
  char input;
  scanf("%c", "&input");
  if(input == 'h') {
    LEDOn();
  } else if(input == 'l') {
    LEDOff();
  }
}
