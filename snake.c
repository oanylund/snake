#include "snake.h"

void update_matrix(list_t *list)
{
  #ifdef SNAKE_DEBUG
  system("clear");
  #endif /*SNAKE_DEBUG*/

	memset(led_out, '\0', sizeof(led_out));
	iter_t *iter = list_createiterator(list);
	item_t *item = NULL;
	while (item = list_iternext(list, iter))
	{
		led_out[item->x][item->y] = 1;
	}
}

#ifdef SNAKE_DEBUG
void temp_show_matrix(char a[][SIZE])
{
	for (char i = 0; i < 8; i++)
	{
		for (char j = 0; j < 8; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
#endif /*SNAKE_DEBUG*/
