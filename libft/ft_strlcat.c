/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 02:37:22 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 00:32:52 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dstlen;
	size_t srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (srclen + size);
	while (*dst)
		dst++;
	size -= dstlen;
	while (*src && size > 1)
	{
		size--;
		*dst++ = *src++;
	}
	*dst = 0;
	return (srclen + dstlen);
}
