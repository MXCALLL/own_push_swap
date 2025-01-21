/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:07:21 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/20 16:09:53 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (!*stack || (*stack)->next == NULL)
		return ;
	temp = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = temp->next;
	last->next = temp;
	temp->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);

}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);

}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);

}
