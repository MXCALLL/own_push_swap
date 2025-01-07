/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:02:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/07 20:46:57 by muidbell         ###   ########.fr       */
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

// void	sort_five(t_stack **stack_a, t_stack **stack_b)
// {
// 	int		current;
// 	t_stack *first;
// 	t_stack *second;

// 	first = *stack_a;
// 	while (first->next)
// 	{

// 	}
// }
