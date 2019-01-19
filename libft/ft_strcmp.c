/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 05:31:27 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/07 06:12:37 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s11;
	unsigned char	*s21;

	s11 = (unsigned char*)s1;
	s21 = (unsigned char*)s2;
	while (*s11 == *s21 && *s11 != '\0' && *s21 != '\0')
	{
		s11++;
		s21++;
	}
	return (*s11 - *s21);
}
