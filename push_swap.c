/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:29:03 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/27 18:01:29 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int check_error(char *str)
{
	int i = 0;
	int flag = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			flag = 1;
			break;
		}
	}
	if(flag != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	int i = 1;
	if (argc > 3)
	{
		while (argv[i])
		{
			if (check_error(argv[i]))
			{
				ft_printf("Error");
			}
			i++;
		}
	}
	return (0);
}
