/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/31 19:06:41 by muidbell         ###   ########.fr       */
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
	int		nbr;

	// t_stack *stack_a;


	if (argc  < 2)
		return (1);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			argv_split = ft_split(argv[i], ' ');
			if (argv_split == NULL || argv_split[0] == NULL)
			{
				ft_printf("Error\n");
				exit(1);
			}
			j = 0;
			while (argv_split[j])
			{
				if(argv_split[j] == argv_split[j+1])
				{
					ft_printf("duplicate");
					exit(1);
				}
				nbr = ft_atoi(argv_split[j]);
				j++;
			}
			// nbr = ft_atoi(&argv_split);
			// add_to_stack(nbr);
			// free_split(argv_split);
			i++;
		}
	}
	return (0);
}
