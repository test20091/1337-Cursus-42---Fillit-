/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:21:44 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/07 21:32:20 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	while (i < n)
	{
		*s1 = *s2;
		if (*s1 == (unsigned char)c)
			return (++s1);
		s1++;
		s2++;
		i++;
	}
	return (NULL);
}
