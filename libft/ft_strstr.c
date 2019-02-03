/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:10:22 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:10:34 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;
	int find_size;

	i = 0;
	j = 0;
	find_size = 0;
	while (to_find[find_size])
		find_size++;
	if (find_size == 0)
		return ((char *)str);
	while (str[i])
	{
		while (to_find[j] == str[i + j])
		{
			if (j == find_size - 1)
				return ((char *)str + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
