/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:42:44 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 21:51:40 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char*)s1;
	s21 = (unsigned char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (s11[i] == s21[i] && s11[i] && s21[i] && i < n - 1)
	{
		i++;
	}
	return (s11[i] - s21[i]);
}
