/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:47:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/07 10:07:12 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack **stack)
{
	t_stack		*last;
	t_stack		*slast;

	if(!*stack || (*stack)->next == NULL)
		return ;

	last = *stack;
	slast = NULL;
	while(last->next)
	{
		slast = last;
		last = last->next;
	}

	slast->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}

void	reverse_ra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1,"rra\n",4);
}

void	reverse_rb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1,"rrb\n",4);
}

void	reverse_rboth(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1,"rrr\n",4);
}
