/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:32:09 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/06 17:35:19 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(s_stack **stack)
{
	s_stack *temp;

	if(!*stack || (*stack)->next ==  NULL)
		return ;

	temp = *stack;

	*stack = temp->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}
void	swap_a(s_stack **stack_a)
{
	swap(stack_a);
	write(1,"sa\n",3);
}
void	swap_b(s_stack **stack_b)
{
	swap(stack_b);
	write(1,"sb\n",3);
}

void	swap_both(s_stack **stack_a, s_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1,"ss\n",3);
}
