/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/26 15:37:26 by muidbell         ###   ########.fr       */
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

t_stack	*insert_to_stack(t_stack **head, int **number, int size)
{
	int		i;
	t_stack	*new_element;
	t_stack	*current;

	*head = NULL;
	current = NULL;
	i = 0;
	while (i < size)
	{
		new_element = malloc(sizeof(t_stack));
		if (!new_element)
			display_error(NULL, NULL);
		new_element->content = (*number)[i];
		new_element->index = -1;
		new_element->next = NULL;
		if (*head == NULL)
			*head = new_element;
		else
			current->next = new_element;
		current = new_element;
		i++;
	}
	return (*head);
}

int	is_sorted(t_stack **head)
{
	t_stack	*current;

	if (!head || !*head)
		return (0);
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
	t_op_list	*list;
	char		*op;

	list = NULL;
	op = get_next_line(0);
	while (op)
	{
		if (!is_valid_op(op))
		{
			free(op);
			free_stack(stack_a);
			free_stack(stack_b);
			free(args.numbers);
			display_error(NULL, NULL);
		}
		list = add_to_list(list, op);
		op = get_next_line(0);
	}
	exec_op(stack_a, stack_b, list);
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
