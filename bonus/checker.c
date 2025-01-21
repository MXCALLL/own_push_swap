/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:58:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 18:31:34 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>
#include <string.h>

// static int	valid_operation(char *operations)
// {
// 	char	*valid_ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
// 			"rra", "rrb", "rrr"};
// 	int		i;

// 	i = 0;
// 	while (i < 11)
// 	{
// 		if (ft_strncmp(operations, valid_ops[i],2) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_args	args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*operations;

	stack_a = NULL;
	stack_b = NULL;
	args = process_input(argc, argv);
	stack_a = insert_to_stack(&stack_a, &args.numbers, args.count);
	operations = get_next_line(0);

	while (operations)
	{
		if (ft_strncmp(operations, "sa",2) == 0)
			swap_a(&stack_a);
		else if (ft_strncmp(operations, "sb\n",2) == 0)
			swap_b(&stack_b);
		else if (ft_strncmp(operations, "ss\n",2) == 0)
			swap_both(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "pa\n",2) == 0)
			push_a(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "pb\n",2) == 0)
			push_b(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "ra\n",2) == 0)
			rotate_a(&stack_a);
		else if (ft_strncmp(operations, "rb\n",2) == 0)
			rotate_b(&stack_b);
		else if (ft_strncmp(operations, "rr\n",2) == 0)
			rotate_both(&stack_a, &stack_b);
		else if (ft_strncmp(operations, "rra\n",3) == 0)
			reverse_ra(&stack_a);
		else if (ft_strncmp(operations, "rrb\n",3) == 0)
			reverse_rb(&stack_b);
		else if (ft_strncmp(operations, "rrr\n",3) == 0)
			reverse_rboth(&stack_a, &stack_b);
		else
		{
			write(2,"Error\n",6);
			exit(1);
		}
		operations = get_next_line(0);
	}
	if (is_sorted(&stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);

	free(args.numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
