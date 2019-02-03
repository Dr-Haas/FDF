/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:57:55 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:57:58 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list)))
			|| (content && !(list->content = malloc(content_size))))
		return (NULL);
	list->content = content ?
			ft_memcpy(list->content, content, content_size) : NULL;
	list->content_size = content ? content_size : 0;
	list->next = NULL;
	return (list);
}
