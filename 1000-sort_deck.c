#include "deck.h"
#include <string.h>

/**
 * get_index - get index of the node
 * @node:node to get index
 * @deck:deck
 * Return: index
 */
int get_index(deck_node_t *node, deck_node_t **deck)
{
	int i;
	deck_node_t **tmp = deck;

	for (i = 0; tmp; i++)
	{
		if (tmp[0] == node)
		{
			return (i);
		}
		tmp = &(tmp[0]->next);
	}
	return (0);
}

/**
 * areTheyNeighbours - check if neighbours
 * @A:node A
 * @B:node B
 * Return: 1 or 0
 */
int areTheyNeighbours(deck_node_t *A, deck_node_t *B)
{
	return ((A->next == B && B->prev == A) || (A->prev == B && B->next == A));
}

/**
 * refreshOuterPointers - refreshes null
 * @A:node A
 * Return: void
 */
void refreshOuterPointers(deck_node_t *A)
{
	if (A->prev != NULL)
		A->prev->next = A;

	if (A->next != NULL)
		A->next->prev = A;
}

/**
 * swap - swap nodes
 * @A:node A
 * @B:node b
 * @deck:deck
 * Return: void
 */
void swap(deck_node_t *A, deck_node_t *B, deck_node_t **deck)
{
	deck_node_t *swapperVector[4];
	deck_node_t *temp;
	int index_A, index_B;

	index_A = get_index(A, deck), index_B = get_index(B, deck);
	if (A == B)
		return;
	if (index_B < index_A)
		temp = A, A = B, B = temp;
	swapperVector[0] = A->prev, swapperVector[1] = B->prev;
	swapperVector[2] = A->next, swapperVector[3] = B->next;
	if (areTheyNeighbours(A, B))
	{	A->prev = swapperVector[2], B->prev = swapperVector[0];
		A->next = swapperVector[3],	B->next = swapperVector[1];
		if (swapperVector[0] != NULL)
			swapperVector[0]->next = B;
		if (swapperVector[3] != NULL)
			swapperVector[3]->prev = A;
	}
	else
	{	A->prev = swapperVector[1], B->prev = swapperVector[0];
		A->next = swapperVector[3],	B->next = swapperVector[2];
		if (swapperVector[2] == swapperVector[1])
		{	swapperVector[2]->prev = B, swapperVector[3]->prev = A;
			swapperVector[2]->next = A;
			if (swapperVector[0] != NULL)
				swapperVector[0]->next = B;
			if (swapperVector[3] != NULL)
				swapperVector[3]->prev = A;
		}
		else
		{	swapperVector[2]->prev = B,	swapperVector[1]->next = A;
			if (swapperVector[0] != NULL)
				swapperVector[0]->next = B;
			if (swapperVector[3] != NULL)
				swapperVector[3]->prev = A;
		}
	}
	if (*deck == A)
		*deck = B;
}

/**
 * get_dnodeint_at_index - get node by index
 * @head:list
 * @index:index of element
 * Return: element by index
 */
deck_node_t *get_dnodeint_at_index(deck_node_t *head, unsigned int index)
{
	unsigned int c;

	for (c = 0; c < index && head->next; c++)
		head = head->next;
	if (c < index)
		return (NULL);
	return (head);
}

/**
 * get_kind_at_index - get kind at node by index
 * @head:list
 * @index:index of element
 * Return: kind of the card
 */
int get_kind_at_index(deck_node_t *head, unsigned int index)
{
	unsigned int c;
	int kinds[4] = {0, 1, 2, 3};

	for (c = 0; c < index && head->next; c++)
		head = head->next;
	if (c < index)
		return (0);

	return (kinds[head->card->kind]);
}

/**
 * get_value_at_index - get value at node by index
 * @deck:list
 * @index:index of element
 * Return: value of the card
 */
int get_value_at_index(deck_node_t **deck, unsigned int index)
{
	int i;
	deck_node_t *first;
	int value, kind;

	first = get_dnodeint_at_index(*deck, index);
	kind = get_kind_at_index(*deck, index);

	converter_t converter_number[] = {
		{"Ace", 1},
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
		{"Queen", 12},
		{"King", 13},
		{0, 14}};

	for (i = 0; converter_number[i].value < 14; i++)
	{
		if (strcmp(converter_number[i].character, first->card->value) == 0)
		{
			value = (converter_number[i].value);
			break;
		}
	}

	return (value + (13 * kind));
}

/**
 * partition - Partition an array and using pivot
 * @deck: Array
 * @low: int
 * @high: int
 * Return: index of pivote (int)
 */
int partition(deck_node_t **deck, int low, int high)
{
	int pivot = get_value_at_index(deck, high);
	int i = low, j = high;

	while (1)
	{
		while (get_value_at_index(deck, i) < pivot)
			i++;
		while (get_value_at_index(deck, j) > pivot)
			j--;

		if (i < j)
		{
			swap(get_dnodeint_at_index(*deck, i), get_dnodeint_at_index(*deck, j), deck);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * hoare_qsort - Sorting Recursively an deck
 * @deck: Array to be sorted
 * @low: The lowest value of the array
 * @high: highest value of the array
 * @size: Size of The Array
 * Return: void
 */
void hoare_qsort(deck_node_t **deck, int low, int high, int size)
{
	int i;

	if (low < high)
	{
		i = partition(deck, low, high);
		if (i > low)
			hoare_qsort(deck, low, i, size);
		hoare_qsort(deck, i + 1, high, size);
	}
}
/**
 * sort_deck - Quick Sort Algorithm using hoare partition
 * @deck: Array to sort
 * Return: Sorted Array (void)
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || 52 < 2)
		return;
	hoare_qsort(deck, 0, 52 - 1, 52);
}
