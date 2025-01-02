/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/02 11:26:54 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>

typedef struct s_stack
{
	int		number;
	struct t_stack *prev;
	struct t_stack *next;
} t_stack;

char	**ft_split(char const *s, char c);
void	print_error(void);
int		ft_atoi(const char *str);
int		check_duplicates(int *numbers, int size);
void	free_split(char **split);

// int  is_Sorted(t_stack* stack);

#endif
