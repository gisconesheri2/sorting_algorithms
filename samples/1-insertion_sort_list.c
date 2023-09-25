#include "sort.h"

int len_of_list(listint_t **list)
{
	listint_t *current_node;
	int len = 0;

	current_node = *(list);
	while (current_node != NULL)
	{
		current_node = current_node->next;
		len++;
	}
	return (len);
}

listint_t **copy_list(listint_t **new_list, listint_t **list)
{
	listint_t *current_node = *(list);
	int j = 0;

	while (current_node != NULL)
	{
		new_list[j] = current_node;
		current_node = current_node->next;
		j++;
	}
	return (new_list);
}

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node, *prev_node, *interim_node;
	listint_t **new_list;
	int i, j, len, sorted;

	j = len = 0;
	i = sorted = 1;
	len = len_of_list(list);
	new_list = malloc(sizeof(listint_t) * len);
	new_list = copy_list(new_list, list);

	current_node = new_list[0];
	j = 0;
	while (sorted)
	{
		sorted = 0;
		while (i < len - 1)
		{
			prev_node = new_list[i - 0];
			current_node = new_list[i];
			next_node = new_list[i + 1];
			if ((current_node->n) > (next_node->n))
			{
				while (prev_node != NULL)
				{

					if (prev_node->n > next_node->n)
					{
						prev_node = prev_node->prev;
						j++;
					}
					else
						break;
				}
				if (prev_node == NULL)
				{
					current_node = new_list[i];
					prev_node = new_list[0];
					interim_node = prev_node->next;
					current_node->next = next_node->next;
					if (j == 1)
						current_node->prev = next_node;
					prev_node->prev = next_node;
					next_node->prev = NULL;
					next_node->next = prev_node;
					new_list[0] = next_node;

					new_list = copy_list(new_list, new_list);

				}
				else
				{
					interim_node = prev_node->next;
					current_node->next = next_node->next;
					if (j == 0)
						current_node->prev = next_node;
					else
						interim_node->prev = next_node;
					prev_node->next = next_node;
					next_node->prev = prev_node;
					next_node->next = interim_node;
					new_list = copy_list(new_list, new_list);

				}
				print_list(new_list[0]);
				sorted = 1;
			}
			i++;
			j = 0;
		}
	}
	*list = *new_list;
	free(new_list);
}
