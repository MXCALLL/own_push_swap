/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:11:34 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 18:08:19 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(int size)
{
	if (size <= 100)
		return (size / 5);
	return (size / 11);
}

int	detect_diff(t_stack **stack_a, int size)
{
	int		diff;
	int		count;
	t_stack	*tmp;

	tmp = *stack_a;
	count = 0;
	while (tmp && tmp->next)
	{
		diff = tmp->index - tmp->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		tmp = tmp->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = chunk_size(get_stack_size(*stack_a));
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (range + i))
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else if (detect_diff(stack_a, get_stack_size(*stack_a)))
			reverse_ra(stack_a);
		else
			rotate_a(stack_a);
	}
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

void	large_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	position;
	int	size_b;

	indexing(*stack_a);
	move_to_b(stack_a, stack_b);
	while (*stack_b)
	{
		position = find_max_position(*stack_b);
		size_b = get_stack_size(*stack_b);
		if (position <= size_b / 2)
		{
			while (position-- > 0)
				rotate_b(stack_b);
		}
		else
		{
			position = size_b - position;
			while (position-- > 0)
				reverse_rb(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}
