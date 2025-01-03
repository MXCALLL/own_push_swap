/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:14:44 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/03 12:28:46 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	write(1,"Error\n",7);
	exit(1);
}
int check_duplicates(int *numbers, int size)
{
	int		i;
	int		j;
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_split(char **split)
{
	int		i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
