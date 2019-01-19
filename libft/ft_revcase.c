/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revcase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 07:30:12 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/11 07:38:09 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revcase(char *s)
{
	size_t		l;
	char		*ret;
	size_t		i;

	i = 0;
	l = ft_strlen(s);
	ret = (char*)malloc(sizeof(char) * (int)(l + 1));
	ft_strcpy(ret, s);
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			ret[i] -= 32;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			ret[i] += 32;
		i++;
	}
	return (ret);
}
