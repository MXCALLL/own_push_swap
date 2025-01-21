/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:53:41 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 21:10:52 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;

	if (*stack_b == NULL)
		return ;
	temp_b = *stack_b;
	*stack_b = (*stack_b)->next;
	temp_b->next = *stack_a;
	*stack_a = temp_b;
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;

	if (*stack_a == NULL)
		return ;
	temp_a = *stack_a;
	*stack_a = (*stack_a)->next;
	temp_a->next = *stack_b;
	*stack_b = temp_a;
}
