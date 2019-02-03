/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:58:44 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:58:46 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	if (n)
	{
		while (n--)
		{
			while ((*(unsigned char *)dest++ = *(unsigned char *)src++)
					== (unsigned char)c)
				return (dest);
		}
	}
	return (0);
}
