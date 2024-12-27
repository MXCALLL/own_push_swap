/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:32:28 by muidbell          #+#    #+#             */
/*   Updated: 2024/12/27 15:49:17 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *error(char *str)
{
	while (*str)
	{
		if ((*str >= '0') && (*str <= '9'))
			break;
		else
			return("Error");
		str++;
	}
	return("\n");
}

int main()
{
	printf("%s",error("3232"));
}