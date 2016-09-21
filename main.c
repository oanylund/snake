//////////////////////
static char userinput;
//////////////////////

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
  item_t *apple = malloc(sizeof(item_t));
  list_addlast(list,item);
  iter_t *iter = list_createiterator(list);
  initialize_game(item,apple);

  ////////////////////
  item = malloc(sizeof(item_t));
  item->r = 3;
  item->c = 4;
  list_addlast(list,item);
  item = malloc(sizeof(item_t));
  item->r = 2;
  item->c = 4;
  list_addlast(list,item);
  ///////////////////
  while(1)
  {
    //////////////////////
    scanf("%c", &userinput);
    //////////////////////

    update_matrix(list,apple);
    temp_interface(led_out);



  }

  return 0;
}
