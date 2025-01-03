/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/03 12:57:11 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f(void)
{
	system("leaks a.out");
}

s_stack	*insert_to_stack(s_stack **head, int *number, int size)
{
	s_stack *new_element;

	new_element = malloc(sizeof(s_stack));
	if(!new_element)
		display_error();

}
int	is_sorted(s_stack **head)
{
	s_stack *current;
	current = *head;
	while(current->next != NULL)
	{
		if (current->content < current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
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
	s_stack *stack_a;
	s_stack *stack_b;

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
				display_error();
			j = 0;
			while (argv_split[j])
				j++;
			countnbr += j;
			free_split(argv_split);
			i++;
		}
		nbr = malloc(sizeof(int) * countnbr);
		if (!nbr)
			display_error();
		i = 1;
		nbr_index = 0;
        while (i < argc)
        {
            argv_split = ft_split(argv[i], ' ');
            if (argv_split == NULL || argv_split[0] == NULL)
                display_error();
            j = 0;
            while (argv_split[j])
            {
                nbr[nbr_index++] = ft_atoi(argv_split[j]);
                j++;
            }
            if (check_duplicates(nbr, nbr_index))
            {
                display_error();
                free(nbr);
                free_split(argv_split);
            }
            free_split(argv_split);
            i++;
        }
		insert_to_stack(&stack_a, &nbr,nbr_index);
        free(nbr);
    }
	return (0);
}
