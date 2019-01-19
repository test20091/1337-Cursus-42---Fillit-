/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:47:23 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 04:15:13 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	l;
	size_t	i;
	char	*r;

	r = NULL;
	if (s != NULL)
	{
		l = ft_strlen((char*)s);
		i = 0;
		if (!(r = (char*)malloc((int)l + 1)))
			return (NULL);
		while (i < l)
		{
			r[i] = f((char)s[i]);
			i++;
		}
		r[i] = '\0';
	}
	return (r);
}
