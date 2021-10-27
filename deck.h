#ifndef _DECK_H_
#define _DECK_H_
#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - kind of card
 * @SPADE: spade type
 * @HEART: spade type
 * @CLUB: spade type
 * @DIAMOND: spade type
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART = 1,
	CLUB = 2,
	DIAMOND = 3
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct converter - struct to get a function pointer a use.
 * @character: character of read (%c, %s, %d, %i, ...).
 * @value: function pointer a function a use
 */
typedef struct converter
{
	char *character;
	unsigned int value;
} converter_t;


void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);
void swap(deck_node_t *A, deck_node_t *B, deck_node_t **deck);
int get_value_at_index(deck_node_t **deck, unsigned int index);
int get_kind_at_index(deck_node_t *head, unsigned int index);
unsigned int is_bigger(deck_node_t **deck, int first_index, int second_index);
int get_index(deck_node_t *node, deck_node_t **deck);
deck_node_t *get_dnodeint_at_index(deck_node_t *head, unsigned int index);



#endif
