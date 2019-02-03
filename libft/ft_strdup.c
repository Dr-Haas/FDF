/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:07:48 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:07:50 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (ret)
	{
		i = 0;
		while (*s1)
			ret[i++] = *s1++;
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
