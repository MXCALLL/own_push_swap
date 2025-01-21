/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:47:58 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 21:11:00 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*slast;

	if (!*stack || (*stack)->next == NULL)
		return ;
	last = *stack;
	slast = NULL;
	while (last->next)
	{
		slast = last;
		last = last->next;
	}
	slast->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	reverse_ra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
}

void	reverse_rb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
}

void	reverse_rboth(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
