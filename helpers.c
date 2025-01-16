/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:44 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/16 16:01:25 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	write(1,"Error\n",7);
	exit(1);
}

int	is_sorted(t_stack **head)
{
	t_stack *current;
	current = *head;
	while(current->next != NULL)
	{
		if (current->content > current->next->content)
			return(0);
		current = current->next;
	}
	return (1);
}

t_stack	*insert_to_stack(t_stack **head, int **number, int size)
{
	int		i;
	t_stack *new_element;
	t_stack *current;

	*head = NULL;
	current  = NULL;
	i = 0;
	while(i < size)
	{
		new_element = malloc(sizeof(t_stack));
		if(!new_element)
			display_error();
		new_element->content = (*number)[i];
		new_element->index = -1; // flag detect not indexed (for large sort)
		new_element->next = NULL;
		if (*head == NULL)
			*head = new_element;
		else
			current->next = new_element;
		current = new_element;
		// printf("%d:%d\n",new_element->index,new_element->content); // index view
		i++;
	}
	return (*head);
}

void	free_split(char **split)
{
	int		i;

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

int	find_min_position(t_stack *stack)
{
	int		min_val;
	int		pos;
	int		i;
	t_stack	*temp;

	if (!stack)
    	return (-1);
	temp = stack;
	min_val = INT_MAX; // if it's INT_MIN it would never reach min value cause is the smallest value possible
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->content < min_val)
		{
			min_val = temp->content;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}
int	find_max_position(t_stack *stack)
{
	int		max_val;
	int		pos;
	int		i;
	t_stack	*temp;

	if (!stack)
    	return (-1);
	temp = stack;
	max_val = INT_MIN;
	pos = 0;
	i = 0;
	while (temp)
	{
		if (temp->index > max_val)
		{
			max_val = temp->index;
			pos = i;
		}
		temp = temp->next;
		i++;
	}
	return (pos);
}
