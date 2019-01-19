/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:03:42 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 00:47:21 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		l;
	int		i;
	char	*r;

	r = NULL;
	if (s != NULL)
	{
		l = (int)ft_strlen((char*)s);
		i = 0;
		if (!(r = (char*)malloc(l + 1)))
			return (NULL);
		while (i < l)
		{
			r[i] = f((unsigned int)i, (char)s[i]);
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
