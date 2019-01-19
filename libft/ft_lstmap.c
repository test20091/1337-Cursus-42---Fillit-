/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 01:13:11 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 04:14:34 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *begin;
	t_list *ret;
	t_list *tmp;

	ret = (t_list*)malloc(sizeof(t_list));
	begin = ret;
	while (lst != NULL)
	{
		tmp = f(lst);
		ret->content_size = tmp->content_size;
		ret->content = malloc(tmp->content_size);
		ft_memcpy((void*)ret->content, tmp->content, tmp->content_size);
		if (lst->next != NULL)
			ret->next = malloc(sizeof(t_list));
		else
			ret->next = NULL;
		ret = ret->next;
		lst = lst->next;
	}
	return (begin);
}
