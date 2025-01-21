/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:48:11 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/21 17:53:21 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	if (!(*str >= '0' && *str <= '9'))
		display_error(NULL, NULL);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str++ - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result * sign < INT_MIN))
			display_error(NULL, NULL);
	}
	if (*str != '\0')
		display_error(NULL, NULL);
	return ((int)(result * sign));
}
