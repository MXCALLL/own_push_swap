/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muidbell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:48:11 by muidbell          #+#    #+#             */
/*   Updated: 2025/01/03 12:29:13 by muidbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_input(const char *str)
{
    if (!str || !*str)
        return (0);
    while ((*str == ' ') || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
        str++;
    if (!(*str >= '0' && *str <= '9'))
        return (0);
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return (0);
        str++;
    }
    return (1);
}

static int	check_overflow(long result, int sign, int next_digit)
{
    if ((result > INT_MAX / 10) || (result == INT_MAX / 10))
    {
        if (sign == 1 && (result > INT_MAX / 10 || next_digit > 7))
            return (-1);
        if (sign == -1 && (result > INT_MAX / 10 || next_digit > 8))
            return (0);
    }
    return (1);
}

int	ft_atoi(const char *str)
{
    int			sign;
    int			overflow_check;
    int			next_digit;
    long		result;

    if (!is_valid_input(str))
        display_error();
    sign = 1;
    result = 0;
    while ((*str == ' ') || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        next_digit = *str - '0';
        overflow_check = check_overflow(result, sign, next_digit);
        if (overflow_check != 1)
            display_error();
        result = result * 10 + next_digit;
        str++;
    }
    return ((int)(result * sign));
}
