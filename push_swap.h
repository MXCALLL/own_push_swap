/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/13 11:00:23 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# include <stdio.h> // to remove

typedef struct s_stack
{
	int				content;
	int				index;
	int				push_cost; //How many commands in total
	bool			above_median; //Used to calculate "push_cost"
	bool			cheapset; //The node that is the cheapest to do commands
	struct s_stack	*target_node; //The target node of a node in the opposite stack
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

// *** Helpers function ***
char	**ft_split(char const *s, char c);
void	display_error(void);
int		ft_atoi(const char *str);
int		check_duplicates(int *numbers, int size);
void	free_split(char **split);
t_stack	*insert_to_stack(t_stack **head, int **number, int size);
int		is_sorted(t_stack **head);
int		find_min_position(t_stack *stack);
int		get_stack_size(t_stack *stack);

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
void	sort_hundred(t_stack **stack_a, t_stack **stack_b);

#endif