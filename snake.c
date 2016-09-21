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
  item_t* tmp1;
  tmp1->r = item->r;
  tmp1->c = item->c;
  item_t* tmp2;


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

  printf("%d %d\n", item->r, item->c);
  printf("%d %d\n", tmp1->r, tmp1->c);
  while(item = list_next(list,iter))
  {

  }

  /*Iterate through the list and write to array*/
  list_iterreset(list,iter);
	while (item = list_next(list, iter))
	{
		led_out[item->r][item->c] = 1;
	}
  led_out[apple->r][apple->c] = 5;

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
