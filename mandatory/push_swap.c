/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/22 11:25:55 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	check_duplicates(int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_args	args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	args = process_input(argc, argv);
	stack_a = insert_to_stack(&stack_a, &args.numbers, args.count);
	if (is_sorted(&stack_a))
		return (free(args.numbers), free_stack(&stack_a), 1);
	if (args.count == 2)
		swap_a(&stack_a);
	else if (args.count == 3)
		sort_three(&stack_a);
	else if (args.count <= 5)
		sort_ffive(&stack_a, &stack_b);
	else if (args.count > 5)
		large_sort(&stack_a, &stack_b);
	free(args.numbers);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
