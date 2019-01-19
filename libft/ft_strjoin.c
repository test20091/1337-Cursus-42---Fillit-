/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:55:44 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 00:55:43 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l = ft_strlen((char*)s1);
	l += ft_strlen((char*)s2);
	if (!(r = (char*)malloc((int)(l + 10))))
		return (NULL);
	ft_bzero(r, l + 10);
	r = ft_strcat(r, (char*)s1);
	r = ft_strcat(r, (char*)s2);
	return (r);
}
