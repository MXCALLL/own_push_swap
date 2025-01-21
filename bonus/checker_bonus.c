/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 22:06:52 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_args	args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operations;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	args = process_input(argc, argv);
	stack_a = insert_to_stack(&stack_a, &args.numbers, args.count);
	operations = get_next_line(0);
	while (operations)
	{
		if (ft_strncmp(operations, "sa\n", 3) == 0)
			swap_a(&stack_a);
		else if (ft_strncmp(operations, "sb\n", 3) == 0)
			swap_b(&stack_b);
		else if (ft_strncmp(operations, "ss\n", 3) == 0)
			swap_both(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "pa\n", 3) == 0)
			push_a(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "pb\n", 3) == 0)
			push_b(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "ra\n", 3) == 0)
			rotate_a(&stack_a);
		else if (ft_strncmp(operations, "rb\n", 3) == 0)
			rotate_b(&stack_b);
		else if (ft_strncmp(operations, "rr\n", 3) == 0)
			rotate_both(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "rra\n", 4) == 0)
			reverse_ra(&stack_a);
		else if (ft_strncmp(operations, "rrb\n", 4) == 0)
			reverse_rb(&stack_b);
		else if (ft_strncmp(operations, "rrr\n", 4) == 0)
			reverse_rboth(&stack_a, &stack_b);
		else
		{
			free(operations);
			display_error(NULL, args.numbers);
		}
		free(operations);
		operations = get_next_line(0);
	}
	if (is_sorted(&stack_a) && !stack_b && stack_a)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(operations);
	free(args.numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
