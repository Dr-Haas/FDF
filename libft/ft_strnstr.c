/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:08:56 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:09:00 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*to_find;

	to_find = needle;
	if (*to_find == '\0')
		return ((char *)haystack);
	while (len--)
	{
		if (*to_find == *haystack)
			to_find++;
		else
		{
			haystack -= (to_find - needle);
			len += (to_find - needle);
			to_find = needle;
		}
		haystack++;
		if (*to_find == '\0')
			return ((char *)(haystack - (to_find - needle)));
		if (*haystack == '\0')
			break ;
	}
	return (NULL);
}
