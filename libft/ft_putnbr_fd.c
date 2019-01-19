/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 07:49:30 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/08 07:56:51 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	isminn(int nb, int fd)
{
	int nbtmp;
	int longueur;

	longueur = 1;
	nb += 1;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(nb / longueur + '0', fd);
		nb = nb % longueur;
		longueur /= 10;
	}
}

static void	isnotminn(int nb, int fd)
{
	int nbtmp;
	int longueur;

	longueur = 1;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	nbtmp = nb;
	while ((nbtmp /= 10) > 0)
	{
		longueur *= 10;
	}
	while (longueur)
	{
		ft_putchar_fd(nb / longueur + '0', fd);
		nb = nb % longueur;
		longueur /= 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		isminn(n, fd);
	else
		isnotminn(n, fd);
}
