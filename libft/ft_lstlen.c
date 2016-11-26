/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <moongamingpp@hotmail.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 20:18:29 by rhabib            #+#    #+#             */
/*   Updated: 2016/11/04 20:18:44 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *blist)
{
	int		i;
	t_list	*list;

	i = 0;
	if (blist)
	{
		list = blist;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}
