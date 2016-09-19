#ifndef  _SNAKE_H
#define _SNAKE_H
#define N 8

char led_out[8][8] =
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
void temp_show_matrix(char a[][8]);
#endif /* _SNAKE_H */
