#include "sort.h"
/**
 * swap_nodes - Function that takes two nodes belonging to a
 * doubly linked list and swaps their positions
 * @left: First node to be swapped
 * @right: second node to be swapped
 * @list: List to which the nodes belong
 * Return: Void
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	listint_t *swapperVector[4];

	swapperVector[0] = left->next;
	swapperVector[1] = left->prev;
	swapperVector[2] = right->next;
	swapperVector[3] = right->prev;
	if (*list == swapperVector[3])
	{
		*list = right;
	}
	if (swapperVector[3]->prev)
	{
		swapperVector[3]->prev->next = swapperVector[0];
	}
	if (right->next)
	{
		right->next->prev = swapperVector[3];
	}
	swapperVector[3]->next = swapperVector[2];
	swapperVector[3]->prev = swapperVector[0];
	right->next = swapperVector[3];
	right->prev = swapperVector[1];
}
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Doubly linked list
 * Return: Void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL, *tmp = NULL;
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
				swap_nodes(&(*list), tmp, tmp->next);
				print_list(*list);
				current = tmp;
			}
			a++;
			current = current->next;
		}
		if (b == 0)
			c = a;
		c--;
		while(current->prev && a >= b)
		{
			if (current->n < current->prev->n)
			{
				tmp = current->prev;
				swap_nodes(&(*list), current, current->prev);
				print_list(*list);
				current = tmp->next;
			}
			a--;
			current = current->prev;
		}
	}
}