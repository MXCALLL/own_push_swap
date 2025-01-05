/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/05 20:30:25 by muidbell         ###   ########.fr       */
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

#endif
