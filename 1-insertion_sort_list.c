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
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Doubly linked list
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *right = NULL, *left = NULL, *tmp = NULL, *tmp2 = NULL;
	int unordered = 1;

	if (list == NULL || *list == NULL)
		return;
	left = *list, right = left->next;
	while (unordered == 1)
	{
		unordered = 0;
		while (right)
		{
			tmp = right->next, tmp2 = tmp;
			if (left->n > right->n)
			{
				unordered = 1;
				swap_nodes(&(*list), left, right), print_list(*list), tmp = right->prev;
				while (tmp)
				{
					if (tmp->n > right->n)
					{
						swap_nodes(&(*list), tmp, right), print_list(*list), tmp = right->prev;
					}
					else
					break;
				}
				if (left)
					right = left->next;
				if (!right)
					break;
			}
			right = tmp2;
			if (right)
				left = right->prev;
		}
		if (right != NULL)
			unordered = 1;
		right = (*list)->next;
		if (right)
			left = right->prev;
	}
}
