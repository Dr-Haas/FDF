/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 04:08:36 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 04:08:39 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	void	*frais;
	int		i;

	i = 0;
	frais = (void *)malloc(size + 1);
	if (frais == 0)
		return ((char *)frais);
	else
		ft_bzero(frais, size + 1);
	return ((char *)frais);
}
