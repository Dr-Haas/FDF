/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:54:43 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:54:48 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		size;
	int		nega;
	int		tmp;
	char	*array;

	nega = 0;
	if (n < 0)
		nega = 1;
	tmp = n;
	size = 1;
	while (tmp /= 10)
		size++;
	array = ft_strnew(size + nega);
	if (array == NULL)
		return (NULL);
	if (nega)
		array[0] = '-';
	while (size--)
	{
		array[size + nega] = (nega ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (array);
}
