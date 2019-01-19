/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifyfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:54:45 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/29 23:54:57 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb < 1)
		return (0);
	if (nb == 1)
		return (1);
	while (i <= nb / 2)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (ft_sqrt(nb + 1));
}

int		checkfile(char *tetris)
{
	int			fd;
	char		**line;
	int			i;
	static int	l = 0;
	char		t[4];

	line = malloc(sizeof(char*));
	fd = open(tetris, O_RDONLY);
	while (get_next_line(fd, line) > 0)
	{
		if (++l % 5 == 0)
		{
			if (ft_strlen(*line) == 0)
				continue;
			else
				return (0);
		}
		i = 0;
		if (ft_strlen(*line) != 4)
			return (0);
		ft_strcpy(t, *line);
		if (checkdiez(t) == 0)
			return (0);
	}
	return (1);
}

void	fill1(char tbl[19][16])
{
	ft_strcpy(tbl[0], "#...#...#...#...");
	ft_strcpy(tbl[1], "####............");
	ft_strcpy(tbl[2], "..#.###.........");
	ft_strcpy(tbl[3], "#...#...##......");
	ft_strcpy(tbl[4], "###.#...........");
	ft_strcpy(tbl[5], "##...#...#......");
	ft_strcpy(tbl[6], "#...###.........");
	ft_strcpy(tbl[7], "##..#...#.......");
	ft_strcpy(tbl[8], "###...#.........");
	ft_strcpy(tbl[9], ".#...#..##......");
	ft_strcpy(tbl[10], "##..##..........");
	ft_strcpy(tbl[11], ".##.##..........");
	ft_strcpy(tbl[12], "#...##...#......");
	ft_strcpy(tbl[13], ".#..###.........");
	ft_strcpy(tbl[14], "#...##..#.......");
	ft_strcpy(tbl[15], "###..#..........");
	ft_strcpy(tbl[16], ".#..##...#......");
	ft_strcpy(tbl[17], "##...##.........");
	ft_strcpy(tbl[18], ".#..##..#.......");
}

int		addft(char tbl[19][16], t_tetris *grid, int indice, char t[16])
{
	int		pp;
	int		j;

	j = -1;
	pp = 0;
	while (pp < 19)
	{
		if (ft_strncmp(tbl[pp], t, 16) == 0)
		{
			while (++j < 16)
				grid[indice].tetris[j / 4][j % 4] = tbl[pp][j];
			return (1);
		}
		pp++;
	}
	return (0);
}

int		squarecmp(char t[16], t_tetris *grid, int indice)
{
	int		i;
	int		j;
	int		pp;
	char	tbl[19][16];

	fill1(tbl);
	pp = 0;
	j = -1;
	i = 0;
	grid[indice].tetris = malloc(sizeof(char*) * 4);
	while (i < 4)
		grid[indice].tetris[i++] = malloc(sizeof(char) * 4);
	if (ft_strchr(t, '#') == NULL)
		return (0);
	if (addft(tbl, grid, indice, t))
		return (1);
	return (0);
}
