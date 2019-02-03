/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 06:10:12 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 06:10:15 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*nv;
	char	*sv;

	sv = NULL;
	if (s && f)
	{
		nv = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!nv)
			return (sv);
		ft_bzero(nv, ft_strlen(s) + 1);
		sv = nv;
		while (*s)
			*nv++ = f(*s++);
		*nv = '\0';
	}
	return (sv);
}
