/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:29:41 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/09 00:50:25 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = (char*)s;
	if ((int)start > (int)ft_strlen((char*)s))
		return (NULL);
	while (start > 0)
	{
		str++;
		start--;
	}
	if (!(ret = (char*)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		ret[i] = *str;
		i++;
		str++;
	}
	ret[i] = '\0';
	return (ret);
}
