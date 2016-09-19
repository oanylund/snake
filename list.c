#include "list.h"
#define LIST_DEBUG 1

/*!
\brief   "Creates a list an allocates memory for it"
\todo    "Has not been tested"
\return  "Returns list a pointer of type list_t first defined in list.h"
*/
list_t* list_create(void)
{
	list_t *list = malloc(sizeof(list_t));
	assert(list != NULL);

	#ifdef LIST_DEBUG
		printf("malloc allocated a list\n");
	#endif /*LIST_DEBUG*/

	list->head = NULL;
	list->num_items = 0;
	return list;
}

/*!
\brief   "Deallocate the memory for the items/nodes in the list and the list iteself"
\pre     "list cannot be NULL"
\Param   "list is of type list_t first defined in list.h"
\todo    "If a list is allocated and no node is inserted into the list, the list cannot be destroyed by the function"
\todo    "Has not yet been tested"
*/
void list_destroy(list_t *list)
{
	assert(list != NULL);
	node_t *current_node = NULL;
	node_t *free_node = list->head;

	while (free_node != NULL)
	{
		current_node = free_node->next;
		free(free_node->item);
		free(free_node);

	#ifdef LIST_DEBUG
			printf("free deallocated an item\n");
			printf("free deallocated a node\n");
	#endif /*LIST_DEBUG*/

		free_node = current_node;
		list->num_items--;
	}
	free(list);

	#ifdef LIST_DEBUG
		printf("free deallocated a list\n");
	#endif /*LIST_DEBUG*/

	list = NULL;

}

/*!
\brief   "Returns the number of items"
\param   "list of type list_t first defined in list.h"
\return  "Returns an integer containing the number of items in the list"
*/
int list_numberofitems(list_t *list)
{
	return list->num_items;
}

/*!
\brief   "Adds an item into a node and insert the node at the start of the list"
\pre     "list cannot be NULL"
\pre     "item cannot be NULL"
\param   "list of type list_t first defined in list.h"
\param   "item of type item_t first defined in ****"
\todo    "Has not yet been tested"
\todo    "Update the doxygen information about the parameter item"
*/
void list_addfirst(list_t *list, void *item)
{
	assert(list != NULL);
	assert(item != NULL);
	node_t *node = malloc(sizeof(node_t));
	assert(node != NULL);

#ifdef LIST_DEBUG
	printf("malloc allocated a node\n");
#endif /*LIST_DEBUG*/

	// List is empty, insert directly to head.
	if (list->head == NULL)
	{
		node->item = item;
		node->next = NULL;
		list->head = node;
		list->num_items++;
	}
	// List is not empty, assert to head and restablish the link.
	else
	{
		node->item = item;
		node->next = list->head;
		list->head = node;
		list->num_items++;
	}
}

/*!
\brief   "Adds an item into a node and insert the node at the end of the list"
\pre     "list cannot be NULL"
\pre     "item cannot be NULL"
\param   "list of type list_t first defined in list.h"
\param   "item of type item_t first defined in ****"
\todo    "Has not yet been tested"
\todo    "Update the doxygen information about the parameter item"
*/
void list_addlast(list_t *list, void *item)
{
	assert(list != NULL);
	assert(item != NULL);
	node_t *current_node = malloc(sizeof(node_t));
	assert(current_node != NULL);

#ifdef LIST_DEBUG
	printf("malloc allocated a node\n");
#endif /*LIST_DEBUG*/

	// List is empty, insert directly to head.
	if (list->head == NULL)
	{

		list->head = current_node;
		current_node->item = item;
		current_node->next = NULL;
		list->num_items++;
	}
	else
	{
		node_t *traverse_node = list->head;
		while (traverse_node->next != NULL)
		{
			traverse_node = traverse_node->next;
		}
		traverse_node->next = current_node;
		current_node->item = item;
		current_node->next = NULL;
		list->num_items++;
	}
}

/*!
\brief   "Searches for an item within the list and remove that item"
\pre     "list cannot be NULL"
\pre     "item cannot be NULL"
\param   "list of type list_t first defined in list.h"
\param   "item of type item_t first defined in ****"
\todo    "test the function and if the logic work at the end points."
\todo    "Update the doxygen information about the parameter item"
*/
void list_removeitem(list_t *list, void *item)
{
	assert(list != NULL);
	assert(item != NULL);
	node_t *previous_node = NULL;
	node_t *current_node = list->head;
	node_t *next_node = NULL;
	//First item is the correct item.
	if (current_node->item == item)
	{
		list->head = current_node->next;
	}
	else
	{
		next_node = current_node->next->next;
		//Find the item
		while (current_node->item != item && next_node != NULL)
		{
			previous_node = current_node;
			current_node = next_node;
			next_node = next_node->next;
		}
		previous_node->next = next_node;
	}
	//Item not found
	if (current_node->item != item)
	{
		printf("item not found");
	}
	else
	{
		list->num_items--;
		free(current_node);
#ifdef LIST_DEBUG
		printf("free deallocated: %d\n");
#endif /*LIST_DEBUG*/
	}
}

/*!
\brief   "Creates an iterator which function is to traverse the list"
\pre     "list cannot be NULL"
\param   "list of type list_t first defined in list.h"
\return  "returns iter of type iter_t first defined in list.h"
*/
iter_t* list_createiterator(list_t *list)
{
	assert(list != NULL);
	assert(list->head != NULL);
	iter_t *iter = malloc(sizeof(iter_t));
	assert(iter != NULL);

#ifdef LIST_DEBUG
	printf("malloc allocated the iterator\n");
#endif /*LIST_DEBUG*/

	iter->list = list;
	iter->node = list->head;

	return iter;
}

/*!
\brief   "Returns the current item and prepares the next item for the next call"
\param   "iter of type iter_t first defined in list.h"
\return  "returns node->item of type item_t first defined in ***"
\bug     "Not working for the last item in the list cause of the assertion?"
\todo    "Might be more functional to return NULL if the end of list is reached. while(iter->node->next != NULL)"
\todo    "Update the doxygen information about the parameter item"
*/
void* list_iternext(list_t *list, iter_t *iter)
{
	if (iter->node == NULL)
	{
		iter->node = list->head;
		list_iterreset(iter, list);
		return NULL;
	}

	else
	{
		node_t *node = iter->node;
		iter->node = iter->node->next;
		return node->item;
	}
}

/*!
\brief   "Reset the iterator to the lists head"
\param   "iter of type iter_t first defined in list.h"
\param   "list of type list_t first defined in list.h"
\bug     "Never tested"
\todo    "Update the doxygen information about the parameter item"
*/
void list_iterreset(iter_t *iter, list_t *list)
{
	iter->node = list->head;
}

/*!
\brief   "Returns the current item and prepares the next item for the next call"
\pre     "iter cannot be NULL"
\param   "iter of type iter_t first defined in list.h"
\return  "returns node->item of type item_t first defined in ***"
\todo    "Might be more functional to return NULL if the end of list is reached. while(iter->node->next != NULL)"
\todo    "Update the doxygen information about the parameter item"
*/
void list_destroyiterator(iter_t *iter)
{
	assert(iter != NULL);
	free(iter);
#ifdef LIST_DEBUG
	printf("free deallocated the iterator\n");
#endif /*LIST_DEBUG*/
}
