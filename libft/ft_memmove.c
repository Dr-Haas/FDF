/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:00:19 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:00:22 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*aside;
	size_t	i;

	i = 0;
	aside = NULL;
	if (dest < src)
	{
		aside = dest;
		while (i < len)
		{
			*(char *)dest++ = *(char *)src++;
			i++;
		}
		return (aside);
	}
	else
	{
		aside = dest;
		ft_memcpy(dest, src, len);
	}
	return (aside);
}
