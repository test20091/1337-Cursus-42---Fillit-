/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 21:53:26 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/19 21:53:33 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	checkread(int *r, char *bf, int fd, char **rest)
{
	char	*tmp;

	while ((*r = read(fd, bf, BUFF_SIZE)) > 0)
	{
		bf[*r] = '\0';
		if (rest[fd] == NULL)
			rest[fd] = ft_strnew(1);
		tmp = ft_strjoin(rest[fd], bf);
		free(rest[fd]);
		rest[fd] = tmp;
		if (ft_strchr(bf, '\n'))
			break ;
	}
}

static int	checkrest(char **rest, char **line, int fd, int ret)
{
	char	*tmp;
	int		i;

	i = 0;
	ret = ret + 0;
	while (rest[fd][i] != '\n' && rest[fd][i])
		i++;
	if (rest[fd][i] == '\n')
	{
		*line = ft_strsub(rest[fd], 0, i);
		tmp = ft_strdup(rest[fd] + i + 1);
		free(rest[fd]);
		rest[fd] = tmp;
		if (!rest[fd][0])
			ft_strdel(&rest[fd]);
	}
	else if (!rest[fd][i])
	{
		*line = ft_strdup(rest[fd]);
		ft_strdel(&rest[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*rest[255];
	char		buffer[BUFF_SIZE + 1];
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	checkread(&ret, buffer, fd, rest);
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (rest[fd] == NULL || rest[fd][0] == '\0'))
		return (0);
	r = checkrest(rest, line, fd, ret);
	return (r);
}
