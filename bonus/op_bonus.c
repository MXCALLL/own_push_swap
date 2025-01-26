/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:33:41 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/26 15:37:30 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_valid_op(char *op)
{
	return (!ft_strncmp(op, "sa\n", 3) || !ft_strncmp(op, "sb\n", 3)
		|| !ft_strncmp(op, "ss\n", 3) || !ft_strncmp(op, "pa\n", 3)
		|| !ft_strncmp(op, "pb\n", 3) || !ft_strncmp(op, "ra\n", 3)
		|| !ft_strncmp(op, "rb\n", 3) || !ft_strncmp(op, "rr\n", 3)
		|| !ft_strncmp(op, "rra\n", 4) || !ft_strncmp(op, "rrb\n", 4)
		|| !ft_strncmp(op, "rrr\n", 4));
}

t_op_list	*add_to_list(t_op_list *list, char *op)
{
	t_op_list	*new;
	t_op_list	*last;

	new = malloc(sizeof(t_op_list));
	if (!new)
		return (NULL);
	new->op = op;
	new->next = NULL;
	if (!list)
		return (new);
	last = list;
	while (last->next)
		last = last->next;
	last->next = new;
	return (list);
}

void	exec_op(t_stack **stack_a, t_stack **stack_b, t_op_list *list)
{
	t_op_list	*tmp;

	tmp = list;
	while (tmp)
	{
		perform_operation(tmp->op, stack_a, stack_b);
		free(tmp->op);
		tmp = tmp->next;
	}
	free(list);
}
