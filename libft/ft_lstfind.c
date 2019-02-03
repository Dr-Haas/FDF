/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:56:54 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:56:58 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstfind(t_list **alst, int data)
{
	t_list	*itr;

	itr = *alst;
	while (itr)
	{
		if (itr->content_size == (size_t)data)
			return (itr);
		itr = itr->next;
	}
	return ((t_list *)0);
}
