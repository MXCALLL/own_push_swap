/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 09:53:17 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/30 12:43:20 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int valid_input(char *str)
{
	int i = 0;
	int flag = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if ( str[i] == '-' && str[i + 1] != '-')
			i++;
		else if(str[i] == '+' && str[i + 1] != '+')
			i++;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag != 0)
		return (1);
	return (0);
}
