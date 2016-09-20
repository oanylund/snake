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
  item_t *test1 = malloc(sizeof(item_t));
  test1->r = 3;
  test1->c = 4;
  list_addlast(list,test1);
  item_t *test2 = malloc(sizeof(item_t));
  test2->r = 2;
  test2->c = 4;
  list_addlast(list,test2);
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
