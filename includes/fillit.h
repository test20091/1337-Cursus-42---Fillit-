/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 00:23:50 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/19 00:23:54 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 4
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "./libft.h"

typedef struct	s_tetris
{
	int			used;
	char		**tetris;
}				t_tetris;

typedef struct	s_params
{
	char		board[20][20];
	t_tetris	*grid;
	int			p;
	int			n;
	int			indice;
}				t_params;

int				backtrack(char board[20][20], char c,\
int indice, t_params params);
void			decalehelper(int prms[4], char p[4][4]);
void			decaleshelper(int prms[4], char p[4][4]);
int				decale(t_tetris *grid, char *tetris, char **line);
void			fillboard(char board[20][20]);
void			printboard(char board[20][20], int n);
void			removechar(char board[20][20], char c, int n);
int				virtualaxe(int ps[8], t_tetris *grid, int indice, int k);
void			drawtetris(int ps[8], char board[20][20],\
char c, t_params params);
int				ft_sqrt(int nb);
int				checkfile(char *tetris);
int				squarecmp(char t[16], t_tetris *grid, int indice);
int				checkbox(char *f);
int				checkdiez(char t[4]);

#endif
