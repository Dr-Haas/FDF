/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:10:51 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:10:54 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*nv;
	size_t	i;

	nv = NULL;
	i = 0;
	if (s)
	{
		nv = (char *)malloc((len + 1) * sizeof(char));
		if (!nv)
			return (NULL);
		while (s[start + i] && i < len)
		{
			nv[i] = s[start + i];
			i++;
		}
		nv[i] = '\0';
	}
	return (nv);
}
