/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/19 15:25:21 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_args
{
	int		*numbers;
	int		count;
}	t_args;

// *** Helpers function ***
char	**ft_split(char const *s, char c);
void	display_error(void);
int		ft_atoi(const char *str);
int		check_duplicates(int *numbers, int size);
void	free_split(char **split);
t_stack	*insert_to_stack(t_stack **head, int **number, int size);
int		is_sorted(t_stack **head);
int		find_min_position(t_stack *stack);
int		find_max_position(t_stack *stack);
void	rotate_to_top(t_stack **stack, int pos, int size);
int		get_stack_size(t_stack *stack);
void	indexing(t_stack *stack);
int		chunk_size(int stack_size);
void	move_to_b(t_stack **stack_a, t_stack **stack_b);
t_args	process_input(int argc, char **argv);
int		detect_diff(t_stack **stack_a, int size);
void	free_stack(t_stack **stack);
void	free_split_number(char **split, int *number);

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
void	large_sort(t_stack **stack_a, t_stack **stack_b);

#endif