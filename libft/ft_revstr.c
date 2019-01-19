/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 07:09:32 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/11 07:17:48 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *s)
{
	char	*ret;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * (l + 1));
	while (i < l)
	{
		ret[i] = s[l - 1 - i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
