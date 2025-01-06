/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/06 19:45:13 by muidbell         ###   ########.fr       */
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
}	s_stack;

char	**ft_split(char const *s, char c);
void	display_error(void);
int		ft_atoi(const char *str);
int		check_duplicates(int *numbers, int size);
void	free_split(char **split);
s_stack	*insert_to_fstack(s_stack **head, int **number, int size);
int		is_sorted(s_stack **head);

void	push_a(s_stack **stack_a, s_stack **stack_b);
void	push_b(s_stack **stack_a, s_stack **stack_b);

void	swap_a(s_stack **stack_a);
void	swap_b(s_stack **stack_b);
void	swap_both(s_stack **stack_a, s_stack **stack_b);

void	rotate_a(s_stack **stack_a);
void	rotate_b(s_stack **stack_b);
void	rotate_both(s_stack **stack_a, s_stack **stack_b);

void	reverse_ra(s_stack **stack_a);
void	reverse_rb(s_stack **stack_b);
void	reverse_rboth(s_stack **stack_a,s_stack **stack_b);

#endif
