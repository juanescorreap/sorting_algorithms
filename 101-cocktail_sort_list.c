#include "sort.h"
/**
 * swap_nodes - Function that takes two nodes belonging to a
 * doubly linked list and swaps their positions
 * @node: base node to be swapped
 * @list: List to which the nodes belong
 * Return: Void
 */
void swap_nodes(listint_t **list, listint_t **node)
{
	listint_t *pt = *node, *pt1, *pt2;

	if (!(*node)->prev)
		*list = (*node)->next;

	pt = pt2 = *node;
	pt1 = pt->next;

	pt->next = pt1->next;
	pt2 = pt->prev;
	pt->prev = pt1;
	pt1->next = pt;
	pt1->prev = pt2;

	if (pt1->prev)
		pt1->prev->next = pt1;

	if (pt->next)
		pt->next->prev = pt;

	*node = pt1;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Doubly linked list
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tmp;
	int a = 0, b = -1, c = -1;

	if (list == NULL || *list == NULL)
		return;
	current = *list;

	while (c >= b)
	{
		b++;
		while (current->next && a != c)
		{
			if (current->n > current->next->n)
			{
				tmp = current;
				swap_nodes(list, &tmp);
				print_list(*list);
				current = tmp;
			}
			a++;
			current = current->next;
		}
		if (b == 0)
			c = a;
		c--;
		while (current->prev && a >= b)
		{
			if (current->n < current->prev->n)
			{
				tmp = current->prev;
				swap_nodes(list, &tmp);
				print_list(*list);
				current = tmp->next;
			}
			a--;
			current = current->prev;
		}
	}
}
