#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 *
 * @list: Doubly linked list
 * Return: Void
 */
#define pointerup(A) A = A->next
#define pointerdown(A) A = A->prev

void insertion_sort_list(listint_t **list)
{
	listint_t *right = NULL;
	listint_t *left = NULL;
	listint_t *next = NULL;
	int unordered = 1;
	listint_t *swapperVector[4];

	if (list == NULL || *list == NULL)
	{
		return;
	}
	left = *list;
	right = left->next;
	while (unordered)
	{
		unordered = 0;
		while (right)
		{
			next = right->next;

			if (left->n > right->n)
			{
				unordered = 1;
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
				print_list(*list);
				if (left)
					right = left->next;
				if (!right)
					break;
			}
			right = next;
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