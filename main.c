#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "statemachine.c"
#include "snake.c"




int main(void)
{
  logic_t statemachine;



  while(1)
  {
    switch(statemachine.current_state)
    {
      case ERROR:
      break;
      case ENTRY:
      break;
      case FOO:
      break;
      case BAR:
      break;
    }







  }

  return 0;
}
