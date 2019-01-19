/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrishelper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:30:52 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/29 23:31:03 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	removechar(char board[20][20], char c, int n)
{
	int j;
	int k;

	j = 0;
	while (j < n)
	{
		k = 0;
		while (k < n)
		{
			if (board[j][k] == c)
				board[j][k] = '.';
			k++;
		}
		j++;
	}
}

int		virtualaxe(int ps[8], t_tetris *grid, int indice, int k)
{
	int vy;

	ps[2] = 0;
	ps[5] = 0;
	vy = 0;
	while (grid[indice].tetris[0][vy] != '#')
		vy++;
	if (vy > 0 && (k - vy) >= 0)
		return (k - vy);
	return (k);
}

void	drawtetris(int ps[8], char board[20][20], char c, t_params params)
{
	while (ps[2] < 4)
	{
		ps[3] = 0;
		while (ps[3] < 4)
		{
			if (params.grid[params.indice].tetris[ps[2]][ps[3]] == '#'
					&& board[ps[0] + ps[2]][ps[4] + ps[3]] == '.'
					&& (ps[0] + ps[2]) < params.n
					&& (ps[4] + ps[3]) < params.n)
			{
				board[ps[0] + ps[2]][ps[4] + ps[3]] = c;
				ps[5]++;
			}
			ps[3]++;
		}
		ps[2]++;
	}
}
