/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:51:04 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/07 22:15:39 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*src1;
	unsigned char			*dst1;

	i = 0;
	src1 = (unsigned char*)src;
	dst1 = (unsigned char*)dst;
	while (i < n)
	{
		dst1[i] = src1[i];
		i++;
	}
	return ((void*)dst1);
}
