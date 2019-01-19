/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 07:59:51 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 22:58:38 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getln(int nb)
{
	int ret;

	ret = 0;
	if (nb < 0)
	{
		nb *= -1;
		ret++;
	}
	while ((nb /= 10) > 0)
	{
		ret++;
	}
	return (ret + 1);
}

static void	ismin(int nb, char *str)
{
	int		nbtmp;
	int		longueur;

	longueur = 1;
	nb += 1;
	if (nb < 0)
	{
		nb *= -1;
		*str++ = '-';
	}
	nbtmp = nb;
	while ((nbtmp /= 10) > 0)
	{
		longueur *= 10;
	}
	while (longueur)
	{
		if (longueur == 1)
			nb += 1;
		*str++ = nb / longueur + '0';
		nb = nb % longueur;
		longueur /= 10;
	}
}

static void	isnotmin(int nb, char *str)
{
	int		nbtmp;
	int		longueur;

	longueur = 1;
	if (nb < 0)
	{
		nb *= -1;
		*str++ = '-';
	}
	nbtmp = nb;
	while ((nbtmp /= 10) > 0)
	{
		longueur *= 10;
	}
	while (longueur)
	{
		*str++ = nb / longueur + '0';
		nb = nb % longueur;
		longueur /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		if (!(str = (char*)malloc(12)))
			return (NULL);
		ft_bzero(str, 12);
		ismin(n, str);
	}
	else
	{
		if (!(str = (char*)malloc(getln(n) + 1)))
			return (NULL);
		ft_bzero(str, getln(n) + 1);
		isnotmin(n, str);
	}
	return (str);
}
