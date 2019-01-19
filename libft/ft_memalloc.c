/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 20:46:42 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/07 20:53:11 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*r;

	if (!(r = (char*)malloc(sizeof(char) * (int)size)))
		return (NULL);
	ft_bzero(r, size);
	return (r);
}
