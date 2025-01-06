/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:07:21 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/06 19:56:34 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(s_stack **stack)
{
	s_stack *temp;
	s_stack *last;

	if(!*stack || (*stack)->next == NULL)
		return ;

	temp = *stack;
	last = *stack;

	while(last->next)
		last = last->next;

	*stack = temp->next;
	(*stack)->prev = NULL;

	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}
void	rotate_a(s_stack **stack_a)
{
	rotate(stack_a);
	write(1,"ra\n",3);
}
void	rotate_b(s_stack **stack_b)
{
	rotate(stack_b);
	write(1,"rb\n",3);
}

void	rotate_both(s_stack **stack_a, s_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1,"rr\n",3);
}
