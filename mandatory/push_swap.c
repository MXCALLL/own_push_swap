/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/23 12:07:01 by muidbell         ###   ########.fr       */
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

static int	countnbr(int argc, char **argv)
{
	int		i;
	int		j;
	int		countnbr;
	char	**argv_split;

	i = 1;
	countnbr = 0;
	while (i < argc)
	{
		argv_split = ft_split(argv[i], ' ');
		if (argv_split == NULL || argv_split[0] == NULL)
			display_error(argv_split, NULL);
		j = 0;
		while (argv_split[j])
			j++;
		countnbr += j;
		free_split(argv_split);
		i++;
	}
	return (countnbr);
}

t_args	process_input(int argc, char **argv)
{
	t_args	result;
	char	**argv_split;
	int		i;
	int		j;

	ft_check(argv);
	i = 1;
	result.count = 0;
	result.numbers = malloc(sizeof(int) * countnbr(argc, argv));
	if (!result.numbers)
		display_error(NULL, NULL);
	while (i < argc)
	{
		argv_split = ft_split(argv[i], ' ');
		if (argv_split == NULL || argv_split[0] == NULL)
			display_error(argv_split, result.numbers);
		j = 0;
		while (argv_split[j])
			result.numbers[result.count++] = ft_atoi(argv_split[j++]);
		if (check_duplicates(result.numbers, result.count))
			display_error(argv_split, result.numbers);
		free_split(argv_split);
		i++;
	}
	return (result);
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
