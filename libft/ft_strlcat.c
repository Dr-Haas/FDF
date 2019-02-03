/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 06:09:54 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 06:09:56 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	i = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (dlen >= n)
		return (n + slen);
	i += dlen;
	dest = &dest[dlen];
	while (*src && i < (n - 1))
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (dlen + slen);
}
