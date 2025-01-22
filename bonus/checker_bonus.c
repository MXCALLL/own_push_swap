/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/22 13:37:21 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	perform_operation(char *op, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(op, "sa\n", 3))
		swap_a(stack_a);
	else if (!ft_strncmp(op, "sb\n", 3))
		swap_b(stack_b);
	else if (!ft_strncmp(op, "ss\n", 3))
		swap_both(stack_a, stack_b);
	else if (!ft_strncmp(op, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(op, "pb\n", 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(op, "ra\n", 3))
		rotate_a(stack_a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rotate_b(stack_b);
	else if (!ft_strncmp(op, "rr\n", 3))
		rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(op, "rra\n", 4))
		reverse_ra(stack_a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		reverse_rb(stack_b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		reverse_rboth(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	is_sorted(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current->next != NULL)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	do_operations(t_stack **stack_a, t_stack **stack_b, t_args args)
{
	char	*operations;

	operations = get_next_line(0);
	while (operations)
	{
		if (!perform_operation(operations, stack_a, stack_b))
		{
			free(operations);
			free_stack(stack_a);
			free_stack(stack_b);
			free(args.numbers);
			display_error(NULL, NULL);
		}
		free(operations);
		operations = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = process_input(argc, argv);
	stack_a = insert_to_stack(&stack_a, &args.numbers, args.count);
	do_operations(&stack_a, &stack_b, args);
	if (is_sorted(&stack_a) && !stack_b && stack_a)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(args.numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
