/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/31 10:34:56 by muidbell         ###   ########.fr       */
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
	int i;
	int j;
	char **argv_split;

	if (argc == 1)
		return (1);

	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			argv_split = ft_split(argv[i], ' ');
			j = 0;
			while (argv_split[j])
			{
				if (valid_input(argv_split[j]))
				{
					ft_printf("Error\n");
					free_split(argv_split);
					return (1);
				}
				j++;
			}
			free_split(argv_split);
			i++;
		}
	}
	return (0);
}
