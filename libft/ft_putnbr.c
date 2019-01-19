/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 07:43:31 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/08 07:48:44 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ismin(int nb)
{
	int nbtmp;
	int longueur;

	longueur = 1;
	nb += 1;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
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
		ft_putchar(nb / longueur + '0');
		nb = nb % longueur;
		longueur /= 10;
	}
}

static void	isnotmin(int nb)
{
	int nbtmp;
	int longueur;

	longueur = 1;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	nbtmp = nb;
	while ((nbtmp /= 10) > 0)
	{
		longueur *= 10;
	}
	while (longueur)
	{
		ft_putchar(nb / longueur + '0');
		nb = nb % longueur;
		longueur /= 10;
	}
}

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ismin(nb);
	else
		isnotmin(nb);
}
