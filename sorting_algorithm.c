/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:02:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/08 23:27:27 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stack_size(t_stack *stack)
{
	int size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return size;
}

static int	find_min_position(t_stack *stack)
{
	int min_val = INT_MAX;
	int pos = 0;
	int i = 0;
	t_stack *temp = stack;

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
	return pos;
}

static void	rotate_to_top(t_stack **stack, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rotate_a(stack);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			reverse_ra(stack);
	}
}

void	sort_three(t_stack **stack_a)
{
	int     first;
	int     second;
	int     last;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if (first > second && second > last)
	{
		swap_a(stack_a);
		reverse_ra(stack_a);
	}
	else if (first > second && second < last && first > last)
		rotate_a(stack_a);
	else if (first > second && second < last)
		swap_a(stack_a);
	else if (first < second && second > last && first > last)
		reverse_ra(stack_a);
	else if (first < second && second > last)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
}

void	sort_ffive(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int position;

	while ((size = get_stack_size(*stack_a)) > 3)
	{
		position = find_min_position(*stack_a);
		rotate_to_top(stack_a, position, size);
		push_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}
