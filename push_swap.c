/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/07 20:51:11 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*insert_to_stack(t_stack **head, int **number, int size)
{
	int		i;
	t_stack *new_element;
	t_stack *current;

	*head = NULL;
	current  = NULL;
	i = 0;
	while(i < size)
	{
		new_element = malloc(sizeof(t_stack));
		if(!new_element)
			display_error();
		new_element->content = (*number)[i];
		new_element->index = i;
		new_element->next = NULL;
		new_element->prev = current;
		if (*head == NULL)
			*head = new_element;
		else
			current->next = new_element;
		current = new_element;
		// printf("%d:%d\n",new_element->index,new_element->content); // index view
		i++;
	}
	return (*head);
}

int	is_sorted(t_stack **head)
{
	t_stack *current;
	current = *head;
	while(current->next != NULL)
	{
		if (current->content > current->next->content)
			return(0);
		current = current->next;
	}
	return (1);
}

void	print_stack(t_stack *head)
{
    t_stack	*tmp = head;
    while (tmp)
    {
        printf("%d ", tmp->content);
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
	if (argc <= 2)
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

	if (argc == 3)
		swap_a(&stack_a);
	else if (argc == 4)
		sort_three(&stack_a);
	// else if (argc <= 6)
	// 	sort_five(&stack_a, &stack_b);

	print_stack(stack_a);
	return (0);
}
