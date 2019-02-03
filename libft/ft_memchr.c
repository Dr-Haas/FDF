/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:59:09 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:59:11 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	if (n)
	{
		while (n--)
		{
			if (*(unsigned char *)src++ == (unsigned char)c)
				return ((void *)src - 1);
		}
	}
	return (NULL);
}
