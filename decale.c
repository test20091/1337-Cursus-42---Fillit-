/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decale.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:25:00 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/29 23:25:06 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	decalehelper(int prms[4], char p[4][4])
{
	char	tmp;
	int		k;

	k = 0;
	while (p[0][0] == '.' && p[0][1] == '.'
	&& p[0][2] == '.' && p[0][3] == '.' && k < 4)
	{
		prms[0] = 1;
		while (prms[0] < 4)
		{
			prms[1] = 0;
			while (prms[1] < 4)
			{
				tmp = p[prms[0] - 1][prms[1]];
				p[prms[0] - 1][prms[1]] = p[prms[0]][prms[1]];
				p[prms[0]][prms[1]] = tmp;
				prms[1]++;
			}
			prms[0]++;
		}
		k++;
	}
}

void	decaleshelper(int prms[4], char p[4][4])
{
	char	tmp;
	int		k;

	k = 0;
	while (p[0][0] == '.' && p[1][0] == '.'
	&& p[2][0] == '.' && p[3][0] == '.' && k < 4)
	{
		prms[0] = 0;
		while (prms[0] < 4)
		{
			prms[1] = 1;
			while (prms[1] < 4)
			{
				tmp = p[prms[0]][prms[1] - 1];
				p[prms[0]][prms[1] - 1] = p[prms[0]][prms[1]];
				p[prms[0]][prms[1]] = tmp;
				prms[1]++;
			}
			prms[0]++;
		}
		k++;
	}
}

int		decale(t_tetris *grid, char *tetris, char **line)
{
	static int	l = 0;
	char		p[4][4];
	static int	indice = 0;
	int			prms[4];

	line = malloc(sizeof(char*));
	prms[3] = open(tetris, O_RDONLY);
	prms[1] = 0;
	prms[2] = 1;
	while (get_next_line(prms[3], line) > 0 && ++l)
	{
		if (l % 5 == 0 && ft_strlen(*line) == 0)
			continue;
		ft_strcpy(p[prms[0]], *line);
		prms[0]++;
		if (prms[0] == 4)
		{
			decalehelper(prms, p);
			decaleshelper(prms, p);
			prms[2] = prms[2] * squarecmp(p[0], grid, indice);
			indice++;
			prms[0] = 0;
		}
	}
	return (prms[2]);
}

int		checkbox(char *f)
{
	int		fd;
	int		r;
	int		total;
	char	buffer[20];

	total = 0;
	fd = open(f, O_RDONLY);
	while ((r = read(fd, buffer, 21)) > 0)
		total += r;
	return (total % 21);
}

int		checkdiez(char t[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (t[i] != '#' && t[i] != '.')
			return (0);
		i++;
	}
	return (1);
}
