/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/09 11:55:47 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

# include <stdio.h> // to remove

typedef struct stacks
{
	int				content;
	int				index;
	struct stacks	*prev;
	struct stacks	*next;
}	t_stack;

// *** Helpers function ***
char	**ft_split(char const *s, char c);
void	display_error(void);
int		ft_atoi(const char *str);
int		check_duplicates(int *numbers, int size);
void	free_split(char **split);
t_stack	*insert_to_stack(t_stack **head, int **number, int size);
int		it_stack_sorted(t_stack **head);

// *** Operations ***
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);

void	reverse_ra(t_stack **stack_a);
void	reverse_rb(t_stack **stack_b);
void	reverse_rboth(t_stack **stack_a, t_stack **stack_b);

// *** Algorithm Sorting ***
void	sort_three(t_stack **stack_a);
void	sort_ffive(t_stack **stack_a, t_stack **stack_b);
void	sort_large_algo(t_stack **stack_a, t_stack **stack_b);

#endif