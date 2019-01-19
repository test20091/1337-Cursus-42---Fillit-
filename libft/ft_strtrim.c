/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 01:18:26 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 23:18:41 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*r;
	int		l;
	int		start;

	if (s == NULL)
		return (NULL);
	start = 0;
	if ((char)*s == '\0')
		return ((char*)s);
	while (*s != '\0' && (s[start] == '\t'
				|| s[start] == ' ' || s[start] == '\n'))
		start++;
	l = (int)ft_strlen((char*)s);
	while (start < l && (s[l - 1] == '\t'
				|| s[l - 1] == ' ' || s[l - 1] == '\n'))
		l--;
	if (start == l)
		return (ft_strnew(1));
	if (!(r = (char*)malloc(l - start + 1)))
		return (NULL);
	r = ft_strsub(s, start, l - start);
	return (r);
}
