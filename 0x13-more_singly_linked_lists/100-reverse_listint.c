#include "lists.h"

/**
 * reverse_listint - reverse a linked list (listint_t)
 * @head: address to the first node in the list
 *
 * Return: an address to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;

	return (*head);
}
