/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:28:53 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/29 17:56:12 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <limits.h>

#include <stdio.h>

typedef struct t_stack
{
	int number;
	struct t_stack *next;
} t_stack;


char	**ft_split(char const *s, char c);
int		t_atoi(const char *str);

// int  is_Sorted(t_stack* stack);

#endif
