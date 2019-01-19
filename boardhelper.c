/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boardhelper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:17:57 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/29 23:18:43 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill(int ps[9])
{
	ps[8] = -1;
	while (++ps[8] < 8)
		ps[ps[8]] = 0;
}

int		backtrack(char board[20][20], char c, int indice, t_params params)
{
	int ps[9];

	fill(ps);
	if (indice == params.p)
		return (1);
	while (ps[0] < params.n)
	{
		ps[1] = 0;
		while (ps[1] < params.n)
		{
			if (params.board[ps[0]][ps[1]] == '.')
			{
				ps[4] = virtualaxe(ps, params.grid, indice, ps[1]);
				params.indice = indice;
				drawtetris(ps, board, c, params);
				if (ps[5] == 4 && backtrack(board, c + 1, indice + 1, params))
					return (1);
				removechar(board, c, params.n);
			}
			ps[1]++;
		}
		ps[0]++;
	}
	return (0);
}

void	fillboard(char board[20][20])
{
	int i;
	int j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			board[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	printboard(char board[20][20], int n)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
