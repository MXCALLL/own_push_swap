/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:53:41 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/05 20:27:54 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *temp_b;

	if(*stack_b == NULL)
		return;

	temp_b = *stack_b;
	*stack_b = (*stack_b)->next;

	temp_b->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = temp_b;
	temp_b->prev = NULL;
	*stack_a = temp_b;
}

void	push_b(s_stack **stack_a, s_stack **stack_b)
{
	s_stack *temp_a;

	if(*stack_a == NULL)
		return;

	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;

	temp_a->next = *stack_b;
	if (*stack_b)
		(*stack_b)->prev = temp_a;
	temp_a->prev = NULL;
	*stack_b = temp_a;
}
