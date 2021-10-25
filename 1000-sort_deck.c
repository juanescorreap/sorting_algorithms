#include "deck.h"
#include <string.h>

unsigned int is_bigger(deck_node_t *first, deck_node_t *second)
{
    int i;
    unsigned int value_first, value_second;

    converter_t converter_number[] = {
		{"1", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
		{"10", 10},
		{"Jack", 11},
		{"Quen", 12},
		{"King", 13},
		{0, 14}};

    for (i = 0; converter_number[i].value < 14; i++)
	{
        printf("esto imprime");
        printf("\n");
        printf("%s carta", first->card->value);
        printf("\n");
		if (strcmp(converter_number[i].character, first->card->value) == 0)
        {
			value_first = (converter_number[i].value);
        }
        printf("esto no");
        printf("\n");
	}
    for (i = 0; converter_number[i].value < 14; i++)
	{
		if (strcmp(converter_number[i].character, second->card->value) == 0)
			value_second = (converter_number[i].value);
	}



    if (first->card->kind > second->card->kind)
    {
        return (1);
    }
    if (first->card->kind == second->card->kind)
    {
        if (value_first > value_second)
            return (1);
        else
            return (0);
    }
    
	return (0);
}


/**
 * swap_nodes - Function that takes two nodes belonging to a
 * doubly linked deck and swaps their positions
 * @left: First node to be swapped
 * @right: second node to be swapped
 * @deck: deck to which the nodes belong
 * Return: Void
 */
void swap_nodes(deck_node_t **deck, deck_node_t *left, deck_node_t *right)
{
	deck_node_t *swapperVector[4];

	swapperVector[0] = left->next;
	swapperVector[1] = left->prev;
	swapperVector[2] = right->next;
	swapperVector[3] = right->prev;
	if (*deck == swapperVector[3])
	{
		*deck = right;
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
 * sift_down - Sorts an array on a max heap recursively.
 * @array: Array to be sorted.
 * @n: size of the array to heap.
 * @i: index to star the heap from.
 * Return: void.
 */
void sift_down(deck_node_t **deck, int n, int i)
{
	int largest = 0;
	int l = (2 * (i + 1)) - 1;
	int r = l + 1;

	if (r < n && is_bigger(deck[r], deck[l]))
		largest = r;
	else if (l < n && is_bigger(deck[l], deck[r]))
		largest = l;
	else
	{
		largest = i;
	}
	if (is_bigger(deck[i], deck[largest]))
	{
		largest = i;
	}
	if (largest != i)
	{
		swap_nodes(deck, deck[i], deck[largest]);
		sift_down(deck, n, largest);
	}
}

/**
 * sort_deck - Sorts an array using the heap sort algorithm.
 * @deck: deck to be sorted.
 * Return: void.
 */
void sort_deck(deck_node_t **deck)
{
	int i;

	for (i = 52 / 2 - 1; i >= 0; i--)
	{
		sift_down(deck, 52, i);
	}

	for (i = 52 - 1; i > 0; i--)
	{
		swap_nodes(deck, deck[0], deck[i]);
		sift_down(deck, i, 0);
	}
}
