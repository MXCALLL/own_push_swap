/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:02:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/08 22:47:34 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int		second;
	int		last;
	t_stack	*temp;

	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	second = (*stack_a)->next->content;
	last = temp->content;
	if ((*stack_a)->content > second && second > last)
	{
		swap_a(stack_a);
		reverse_ra(stack_a);
	}
	else if ((*stack_a)->content > second && second < last && last < (*stack_a)->content)
		rotate_a(stack_a);
	else if ((*stack_a)->content > second && second < last)
		swap_a(stack_a);
	else if ((*stack_a)->content < second && second > last && (*stack_a)->content > last)
		reverse_ra(stack_a);
	else if ((*stack_a)->content < second && second > last)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
}

static int	find_min_position(t_stack *stack)
{
    int	min_val = INT_MAX;
    int	pos = 0;
    int	i = 0;
    while (stack)
    {
        if (stack->content < min_val)
        {
            min_val = stack->content;
            pos = i;
        }
        stack = stack->next;
        i++;
    }
    return (pos);
}

static void	rotate_to_top(t_stack **stack, int pos, int size)
{
    if (pos < size / 2)
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

void	sort_ffive(t_stack **stack_a, t_stack **stack_b, int argc)
{
    while (argc > 3)
    {
        int pos = find_min_position(*stack_a);
        rotate_to_top(stack_a, pos, argc - 1);
        push_b(stack_a, stack_b);
        argc--;
    }
    sort_three(stack_a);
    while (*stack_b)
        push_a(stack_a, stack_b);
}
