/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 04:26:25 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/11 01:47:45 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while ((*alst) != NULL)
	{
		tmp = *alst;
		(*del)((void*)tmp->content, tmp->content_size);
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
}
