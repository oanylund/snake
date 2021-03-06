#ifndef  _SNAKE_H
#define _SNAKE_H
#include <string.h> /*For memset in function update_matrix*/
#include <time.h>

#define SIZE 8
#define SNAKE_DEBUG
#define INTERFACE_TERMINAL
//#define INTERFACE_MATRIX

#if INTERFACE_MATRIX
  #define LED_LEDPORT PORTB
  #define UP    ((LED_LEDPORT) & (1<<(DB0)))
  #define DOWN  ((LED_LEDPORT) & (1<<(DB1)))
  #define LEFT  ((LED_LEDPORT) & (1<<(DB2)))
  #define RIGHT ((LED_LEDPORT) & (1<<(DB3)))
#endif /*INTERFACE_MATRIX*/

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
  char r;
  char c;
};

void update_matrix(list_t *list,item_t *apple);
void temp_interface(char a[][SIZE]);
#endif /* _SNAKE_H */
