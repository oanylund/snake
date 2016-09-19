#include "snake.h"

void update_matrix(list_t *list)
{
	//memset(matrix, 0, sizeof(matrix[0][0]*8*8));
	iter_t *iter = list_createiterator(list);
	item_t *item = NULL;
	while (item = list_iternext(iter, list))
	{
		led_out[item->x][item->y] = 1;
	}
}

void temp_show_matrix(char a[][N])
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
