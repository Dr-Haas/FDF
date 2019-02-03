/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 06:10:47 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 06:10:49 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	void	*r;

	r = dest;
	if (n)
	{
		while (*dest)
			dest++;
		while (n--)
		{
			if ((*dest = *src++) == 0)
				break ;
			dest++;
		}
		*dest = '\0';
	}
	return (r);
}
