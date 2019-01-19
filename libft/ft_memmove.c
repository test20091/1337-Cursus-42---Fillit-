/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:37:47 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/07 22:16:42 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	tmp[len];

	if (len > 65535)
		return (NULL);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	return (dst);
}
