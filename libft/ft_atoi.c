/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:11:04 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 22:23:11 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	checkvalue(long long int nb)
{
	if (nb >= 9223372036854775807)
		return (-1);
	else if (nb <= -9223372036854775807)
		return (0);
	else if (nb > 2147483647)
		return (0);
	else if (nb < -2147483648)
		return (-1);
	else
		return (nb);
}

int						ft_atoi(const char *str)
{
	int				sign;
	long long int	total;

	total = 0;
	sign = 1;
	while (*str == 32 || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' && ft_isdigit(*(str + 1)))
		str++;
	if (*str == '-')
	{
		sign = 0;
		str++;
	}
	while (ft_isdigit(*str))
	{
		total = (total * 10) + (*str - 48);
		str++;
	}
	if (sign == 0)
		return ((int)checkvalue(-total));
	return ((int)checkvalue(total));
}
