/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 00:23:31 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/30 00:35:43 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int a, char **v)
{
	t_params	params;
	char		**line;

	line = malloc(sizeof(char*));
	params.p = 0;
	params.n = 2;
	fillboard(params.board);
	params.grid = malloc(sizeof(t_tetris) * 52);
	if ((checkbox(v[1]) == 20 || checkbox(v[1]) == 19) && checkfile(v[a - 1])
	&& decale(params.grid, v[1], line) && a == 2)
	{
		while (params.grid[params.p].tetris)
			params.p++;
		if (params.p < 1 || params.p > 26)
			ft_putstr("error\n");
		if (params.p < 1 || params.p > 26)
			return (0);
		params.n = ft_sqrt(params.p * 4);
		while (!backtrack(params.board, 'A', 0, params))
			params.n++;
		printboard(params.board, params.n);
	}
	else
		ft_putstr("error\n");
	return (0);
}
