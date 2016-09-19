#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "statemachine.c"
#include "snake.c"
#include <time.h>


int main(void)
{
  logic_t statemachine;
  list_t *list = list_create();
  item_t *item = malloc(sizeof(item_t));
  item->x = 4;
  item->y = 4;
  list_addfirst(list,item);
  iter_t *iter = list_createiterator(list);

//////////////////////
char userinput;
//////////////////////

  while(1)
  {
    update_matrix(list);
    temp_show_matrix(led_out);
    scanf("%c", &userinput);
    switch(userinput)
    {
      case 'w':
      while(item = list_iternext(list,iter))
        item->x--;
      break;
      case 'a':
      while(item = list_iternext(list,iter))
        item->y--;
      break;
      case 's':
      while(item = list_iternext(list,iter))
        item->x++;
      break;
      case 'd':
      while(item = list_iternext(list,iter))
        item->y++;
      break;

    }

  }

  return 0;
}
