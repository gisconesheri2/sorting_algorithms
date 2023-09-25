#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - double linked list node
 *
 * @n: integer stored in the node
 * @prev: pointer to the previous element in the list
 * @next: pointer to the next element in the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
#endif
