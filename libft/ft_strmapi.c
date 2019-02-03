/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 06:10:23 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 06:10:27 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*nv;

	i = 0;
	nv = NULL;
	if (s && f)
	{
		nv = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!nv)
			return (NULL);
		ft_bzero(nv, ft_strlen(s) + 1);
		while (s[i])
		{
			nv[i] = f(i, s[i]);
			i++;
		}
		nv[i] = '\0';
	}
	return (nv);
}
