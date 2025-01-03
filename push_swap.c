/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/03 15:50:57 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void f(void)
{
	system("leaks a.out");
}

s_stack	*insert_to_fstack(s_stack **head, int **number, int size)
{
	int		i;
	s_stack *new_element;

	i = 0;
	while(i < size)
	{
		new_element = malloc(sizeof(s_stack));
		if(!new_element)
			display_error();
		new_element->content = (*number)[i];
		new_element->prev = NULL;
		new_element->next = *head;
		if (*head != NULL)
			(*head)->prev = new_element;
		*head = new_element;
		i++;
	}
	return (new_element);
}

int	is_sorted(s_stack **head)
{
	s_stack *current;
	current = *head;
	while(current->next != NULL)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
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
		stack_a = insert_to_fstack(&stack_a, &nbr,nbr_index);
		if(is_sorted(&stack_a))
			display_error();
        free(nbr);
    }
	return (0);
}
