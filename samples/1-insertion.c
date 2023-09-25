#include "sort.h"

void insertion_sort_list(listint_t **list) 
{
	listint_t *current_node, *next_node, *slh, *slh_n;

	current_node = next_node = *list;

	if (current_node == NULL || current_node->next == NULL)
		exit(0);

	slh = NULL;

	while (current_node != NULL)
	{
		current_node = next_node;
		next_node = next_node->next;

		if (slh == NULL || current_node->n < slh->n)
		{
			current_node->next = slh;
			slh = current_node;
		}
		else
		{
			slh_n = slh;
			while (slh_n != NULL)
			{
				if (slh_n->next == NULL || current_node->n < slh_n->next->n)
				{
					current_node->next = slh_n->next;
					slh_n->next = current_node;
					break;
				}
				slh_n = slh_n->next;
			}
		}
	}
	*list = slh;
}
