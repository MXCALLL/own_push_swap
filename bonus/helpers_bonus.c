/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:44 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/23 12:37:19 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	indexing(t_stack *stack)
{
	t_stack	*current;
	t_stack	*min_node;
	int		i;
	int		size;

	size = get_stack_size(stack);
	i = 0;
	while (i < size)
	{
		current = stack;
		min_node = NULL;
		while (current)
		{
			if (current->index == -1)
				if (!min_node || current->content < min_node->content)
					min_node = current;
			current = current->next;
		}
		if (min_node)
			min_node->index = i++;
	}
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

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check(char **argv)
{
	int		i;
	char	**split;
	int		j;

	i = 1;
	while (argv[i])
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			display_error(split, NULL);
		j = 0;
		while (split[j])
		{
			if (!is_valid_number(split[j]))
			{
				free_split(split);
				display_error(NULL, NULL);
			}
			j++;
		}
		free_split(split);
		i++;
	}
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
