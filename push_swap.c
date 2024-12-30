/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/30 20:52:24 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f(void)
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	// atexit(f);
	int i = 0;
	char **argv_split;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		argv_split = ft_split(argv[1], ' ');
		while (argv_split[i])
		{
			if (valid_input(argv_split[i]))
			{
				ft_printf("Error\n");
				free_split(argv_split);
				return (1);
			}
			i++;
		}
	}
	else if (argc >= 3)
	{
		i = 1;
		while (argv[i])
		{
			if (valid_input(argv[i]))
			{
				ft_printf("Error\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}
