/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:43:16 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/11 05:00:32 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		getlastindex(char *str, char c)
{
	int		i;
	int		l;

	l = 0;
	while (*str)
	{
		l++;
		str++;
	}
	str = str - l;
	i = l - 1;
	while (i > 0)
	{
		if (str[i] == c)
		{
			i--;
			continue;
		}
		break ;
	}
	if (i < 0)
		return (0);
	return (i);
}

static int		count_words(char *str, char c)
{
	int i;
	int j;
	int k;

	k = 0;
	j = getlastindex(str, c);
	i = 0;
	if (i == j)
		return (0);
	while (i <= j)
	{
		if (str[i] == c)
		{
			while (str[i + 1] == c)
			{
				i++;
			}
			k++;
		}
		i++;
	}
	return (k + 1);
}

static void		allocptr(char **cu, char *p, t_split x)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (p[x.f] != '\0')
	{
		if (p[x.f] == x.ch || p[x.f + 1] == '\0')
		{
			while (p[x.f + 1] == x.ch)
				x.f++;
			if (p[x.f] == p[x.l])
				k++;
			if (!(cu[j] = malloc(sizeof(char) * (k + 1))))
				return ((void)0);
			k = 0;
			j++;
			x.f++;
			continue;
		}
		k++;
		x.f++;
	}
	if (p[x.f] == '\0')
		cu[j] = malloc(sizeof(char));
}

static void		fillptr(char **cu, char *str, t_split x)
{
	int i;
	int j;
	int k;

	i = x.f;
	j = 0;
	k = 0;
	while (str[i] != '\0' && i <= x.l)
	{
		if (str[i] == x.ch)
		{
			while (str[i] == x.ch)
				i++;
			cu[k][j] = '\0';
			j = 0;
			k++;
		}
		cu[k][j] = str[i];
		if (str[i + 1] == '\0')
			cu[k][j + 1] = '\0';
		j++;
		i++;
	}
	cu[k][j] = '\0';
	cu[k + 1] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		first;
	int		last;
	char	*str;
	t_split	x;

	str = (char*)s;
	x.f = 0;
	first = 0;
	x.ch = c;
	while (str[first] == c)
		str++;
	last = getlastindex(str, c);
	x.l = last;
	if (!last)
	{
		tab = malloc(sizeof(char*));
		tab[0] = 0;
		return (tab);
	}
	if (!(tab = malloc(sizeof(char *) * (count_words(str, c) + 1))))
		return (NULL);
	allocptr(tab, str, x);
	fillptr(tab, str, x);
	return (tab);
}
