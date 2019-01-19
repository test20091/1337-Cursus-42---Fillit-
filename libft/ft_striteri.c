/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:29:08 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 00:55:21 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int l;
	int i;

	if (s != NULL)
	{
		i = 0;
		l = (int)ft_strlen(s);
		while (i < l)
		{
			f((unsigned char)i, s + i);
			i++;
		}
	}
}
