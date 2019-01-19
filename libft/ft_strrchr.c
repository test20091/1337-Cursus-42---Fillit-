/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 04:07:18 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/08 03:21:49 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *t;

	t = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			t = (char*)s;
		s++;
	}
	if (t != NULL)
		return (t);
	else if (c == '\0')
		return ((char*)s);
	else
		return (NULL);
}
