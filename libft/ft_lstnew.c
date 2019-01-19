/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 08:47:01 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 21:43:50 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;
	t_list	*buff;

	if (!(ret = (t_list*)malloc(sizeof(*ret))))
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
		ret->next = NULL;
		return (ret);
	}
	if (!(buff = (t_list*)malloc(sizeof(*buff))))
		return (NULL);
	buff = ret;
	buff->content = ft_memalloc(content_size);
	buff->content_size = content_size;
	ft_memcpy((void*)buff->content, (void*)content, content_size);
	buff->next = NULL;
	return (ret);
}
