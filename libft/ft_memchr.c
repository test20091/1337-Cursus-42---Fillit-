/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:46:47 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/06 23:31:46 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	ch;
	size_t			i;

	i = 0;
	src = (unsigned char*)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (*src == ch)
			return ((void*)src);
		src++;
		i++;
	}
	return (NULL);
}
