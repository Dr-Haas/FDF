/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:04:12 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:04:14 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (!ptr)
		return (ft_memalloc(size));
	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	new = (void *)ft_memalloc(size);
	if (!new)
		return (NULL);
	new = ft_memcpy(new, ptr, size);
	free(ptr);
	return (new);
}
