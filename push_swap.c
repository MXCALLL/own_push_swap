/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/02 14:49:45 by muidbell         ###   ########.fr       */
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
	int		i;
	int		j;
	int		nbr_index;
	int		countnbr;
	char	**argv_split;
	int		*nbr;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc  < 2)
		return (1);
	if (argc >= 2)
	{
		i = 1;
		countnbr = 0;
		while (i < argc)
		{
			argv_split = ft_split(argv[i], ' ');
			if (argv_split == NULL || argv_split[0] == NULL)
				print_error();
			j = 0;
			while (argv_split[j])
				j++;
			countnbr += j;
			free_split(argv_split);
			i++;
		}
		nbr = malloc(sizeof(int) * countnbr);
		if (!nbr)
			print_error();
		i = 1;
		nbr_index = 0;
        while (i < argc)
        {
            argv_split = ft_split(argv[i], ' ');
            if (argv_split == NULL || argv_split[0] == NULL)
                print_error();
            j = 0;
            while (argv_split[j])
            {
                nbr[nbr_index++] = ft_atoi(argv_split[j]);
                j++;
            }
            if (check_duplicates(nbr, nbr_index))
            {
                print_error();
                free(nbr);
                free_split(argv_split);
            }
            free_split(argv_split);
            i++;
        }
        // add_to_stack(&stack_a, nbr, total_numbers);
        free(nbr);
    }
	return (0);
}
