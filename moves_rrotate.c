/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:47:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/06 19:40:01 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(s_stack **stack)
{
	s_stack		*last;
	s_stack		*slast;

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

void	reverse_ra(s_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1,"rra\n",4);
}

void	reverse_rb(s_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1,"rrb\n",4);
}

void	reverse_rboth(s_stack **stack_a, s_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1,"rrr\n",4);
}
