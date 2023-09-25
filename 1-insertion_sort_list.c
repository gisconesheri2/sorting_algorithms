#include "sort.h"

/**
 * len_of_list - gets the length of the linked list
 * @list: linked list
 *
 * Return: length of linked list
 */
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
/**
 * copy_list - generates a sized array of pointers
 * @new_list: list to contain the newlly arranged pointers
 * @list: old arrangement
 *
 * Return: an organised array of pointers
 */
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

/**
 * insertion_sort_list - sorts a linked list on ints via insertion sort
 * @list: linkedlist to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *next_node;
	listint_t **new_list;
	int i, len;

	i = len = 0;
	len = len_of_list(list);
	new_list = malloc(sizeof(listint_t) * len);
	new_list = copy_list(new_list, list);
	while (i < len - 1)
	{
		current_node = new_list[i];
		next_node = new_list[i + 1];
		if ((current_node->n) > (next_node->n))
		{
			while (current_node->n > next_node->n)
			{
				if (next_node->next != NULL)
					next_node->next->prev = current_node;
				if (current_node->prev == NULL)
				{
					current_node->next = next_node->next;
					next_node->prev = current_node->prev;
					next_node->next = current_node;
					current_node->prev = next_node;
					new_list[0] = next_node;
					new_list = copy_list(new_list, new_list);
					print_list(new_list[0]);
					break;
				}
				current_node->prev->next = next_node;
				current_node->next = next_node->next;
				next_node->prev = current_node->prev;
				next_node->next = current_node;
				current_node->prev = next_node;
				current_node = next_node->prev;
				new_list = copy_list(new_list, new_list);
				print_list(new_list[0]);
			}
		}
		i++;
	}
	*list = *new_list;
	free(new_list);
}
