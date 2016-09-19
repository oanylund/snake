#ifndef _LIST_H
#define _LIST_H
#include <assert.h>

typedef struct node node_t;
struct node
{
  node_t	*next;
  void		*item;
};

typedef struct list list_t;
struct list
{
  node_t *head;
  int num_items;
};

typedef struct iter iter_t;
struct iter
{
  list_t *list;
  node_t *node;
};

/*Prototype*/
list_t* list_create           (void);
void	  list_destroy          (list_t *list);
int		  list_numberofitems    (list_t *list);
void    list_addfirst         (list_t *list, void *item);
void    list_addlast          (list_t *list, void *item);
void    list_removeitem       (list_t *list, void *item);
iter_t* list_createiterator   (list_t *list);
void*	  list_iternext         (iter_t *iter, list_t *list);
void	  list_iterreset        (iter_t *iter, list_t *list);
void	  list_destroyiterator  (iter_t *iter);

#endif /*_LIST_H*/
