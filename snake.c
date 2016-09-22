#include "snake.h"

char led_out[SIZE][SIZE] =
{
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 },
  { 0,0,0,0,0,0,0,0 }
};

#ifdef INTERFACE_TERMINAL
char userinput;
#endif /*INTERFACE_TERMINAL*/

void initialize_game(item_t *item, item_t *apple)
{
  //show high score
  //reset array
  item->r = 4;
  item->c = 4;
  apple->r = 5;
  apple->c = 2;
  srand(time(NULL));
}

char check_position_taken(list_t* list, iter_t* iter, item_t* point) {
  item_t* item;
  while(item = list_next(list,iter)) {
    if( (point->r == item->r) && (point->c == item->c) ) {
      return 1;
    }
  }
  return 0;
}

void reposition_apple(list_t* list, item_t* apple) {
  iter_t* iter = list_createiterator(list);
  do {
      apple->r = rand() % (SIZE - 2) + 1;
      apple->c = rand() % (SIZE - 2) + 1;
  } while (check_position_taken(list, iter, apple));
  list_destroyiterator(iter);
}

void update_matrix(list_t *list,item_t *apple)
{
  #ifdef INTERFACE_TERMINAL
  system("clear");
  printf("NUMITEMS: %d\n", list->num_items);
  #endif /*INTERFACE_TERMINAL*/

	memset(led_out, '\0', sizeof(led_out));
  iter_t* iter = list_createiterator(list);
  item_t* item = list_next(list,iter);
  item_t tmp1;
  item_t tmp2;
  memcpy(&tmp1,item,sizeof(item_t));

  #ifdef INTERFACE_TERMINAL
    switch(userinput)
    {
      case 'w':
        item->r--;
      break;
      case 'a':
        item->c--;
      break;
      case 's':
        item->r++;
      break;
      case 'd':
        item->c++;
      break;
    }
  #endif /*INTERFACE_TERMINAL*/

  while(item = list_next(list,iter))
  {
    tmp2.r = item->r;
    tmp2.c = item->c;
    item->r = tmp1.r;
    item->c = tmp1.c;
    tmp1.r = tmp2.r;
    tmp1.c = tmp2.c;
  }

  list_iterreset(list,iter);
  item = list_next(list, iter);
  if(item->r == apple->r && item->c == apple->c) {
    item = malloc(sizeof(item_t));
    item->r = tmp1.r;
    item->c = tmp1.c;
    list_addlast(list,item);

    // Generate new apple position
    reposition_apple(list, apple);
  }

  led_out[apple->r][apple->c] = 5;
  /*Iterate through the list and write to array*/
  list_iterreset(list,iter);
	while (item = list_next(list, iter))
	{
		led_out[item->r][item->c] = 1;
	}
  list_destroyiterator(iter);
}

#ifdef INTERFACE_TERMINAL
  void temp_interface(char a[][SIZE])
  {
  	for (char i = 0; i < SIZE; i++)
  	{
  		for (char j = 0; j < SIZE; j++)
  		{
  			printf("%d ", a[i][j]);
  		}
  		printf("\n");
  	}
  	printf("\n\n");
  }
#endif /*INTERFACE_TERMINAL*/
