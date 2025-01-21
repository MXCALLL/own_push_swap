/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:03:25 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 18:20:25 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <stdio.h>
# include "../push_swap.h"
# include "get_next_line.h"

// *** Input check ***
// t_args	process_input(int argc, char **argv);
// int		countnbr(int argc, char **argv);
// void	display_error(char **split, int *numbers);
// void	free_stack(t_stack **stack);
// void	free_split(char **split);
// char	**ft_split(char const *s, char c);
// int		ft_atoi(const char *str);
// int		check_duplicates(int *numbers, int size);

// char	*get_next_line(int fd);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif