#ifndef  _SNAKE_H
#define _SNAKE_H
#include <string.h> /*For memset in function update_matrix*/

#define SIZE 8
#define SNAKE_DEBUG



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

typedef struct item item_t;
struct item
{
  char x;
  char y;
};
void update_matrix(list_t *list);
void temp_show_matrix(char a[][SIZE]);
#endif /* _SNAKE_H */
