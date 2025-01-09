/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/09 12:30:23 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int check_duplicates(int *numbers, int size)
{
	int		i;
	int		j;
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_stack(t_stack *head)
{
    t_stack	*tmp = head;
    while (tmp)
    {
        printf("%d:%d ", tmp->index,tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
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
	if (argc < 2)
		return (1);

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
            free(nbr);
	        display_error();
    	}
    	free_split(argv_split);
		i++;
	}
	stack_a = insert_to_stack(&stack_a, &nbr,nbr_index);
	if(is_sorted(&stack_a))
		return (free(nbr),1);
	free(nbr);

	if (nbr_index == 2)
		swap_a(&stack_a);
	else if (nbr_index == 3)
		sort_three(&stack_a);
	else if (nbr_index <= 5)
		sort_ffive(&stack_a, &stack_b);
	// else if (argc > 5)
	// 	sort_large_algo(&stack_a, &stack_b);
	else
		printf("Nothing\n");

	print_stack(stack_a);
	// print_stack(stack_b);
	return (0);
}
