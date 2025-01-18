/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:44 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/19 00:47:53 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

int	is_sorted(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		i;
	int		size;

	size = get_stack_size(stack);
	i = 0;
	while (i < size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1)
				if (!min_node || current->content < min_node->content)
					min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->index = i++;
	}
}

t_stack	*insert_to_stack(t_stack **head, int **number, int size)
{
	int		i;
	t_stack	*new_element;
	t_stack	*current;

	*head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		new_element = malloc(sizeof(t_stack));
		if (!new_element)
			display_error();
		new_element->content = (*number)[i];
		new_element->index = -1;
		new_element->next = NULL;
		if (*head == NULL)
			*head = new_element;
		else
			current->next = new_element;
		current = new_element;
		i++;
	}
	return (*head);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
