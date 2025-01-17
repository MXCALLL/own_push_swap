/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:11:34 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/17 17:44:24 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    chunk_size(int size)
{
    if (size <= 100)
        return (size / 5);
    return (size / 11);
}

void move_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int     i;
    int     range;

    i = 0;
    range = chunk_size(get_stack_size(*stack_a));
    while (*stack_a)
    {
        if ((*stack_a)->index <= i)
        {
            push_b(stack_a, stack_b);
            rotate_b(stack_b);
            i++;
        }
        else if ((*stack_a)->index <= (range + i))
        {
            push_b(stack_a, stack_b);
            i++;
        }
        else
            rotate_a(stack_a);
    }
}

void    large_sort(t_stack **stack_a, t_stack **stack_b)
{
    int     position;
    int     size_b;

    indexing(*stack_a);
    move_to_b(stack_a, stack_b);

	// pushing back to A
    while (*stack_b)
    {
        position = find_max_position(*stack_b);
        size_b = get_stack_size(*stack_b);

        if (position <= size_b / 2)
        {
            while (position-- > 0)
                rotate_b(stack_b);
        }
        else
        {
            position = size_b - position;
            while (position-- > 0)
                reverse_rb(stack_b);
        }
        push_a(stack_a, stack_b);
    }
}
