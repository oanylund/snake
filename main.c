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
  update_matrix(list);
  temp_show_matrix(led_out);
  item->x--;
  item->y;
  list_addfirst(list,item);
  update_matrix(list);
  temp_show_matrix(led_out);

  // while(1)
  // {
  //
  //
  //
  // }

  return 0;
}
