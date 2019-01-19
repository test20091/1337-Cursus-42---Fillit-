/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasfi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 07:30:54 by arasfi            #+#    #+#             */
/*   Updated: 2018/10/10 01:52:08 by arasfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst != NULL && new != NULL)
	{
		new->next = (*alst);
		*alst = new;
	}
	else
	{
		new->next = NULL;
		*alst = new;
	}
}
