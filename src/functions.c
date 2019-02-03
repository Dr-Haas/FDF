/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:47:18 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/13 17:02:08 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_list_return(t_pos **begin_list, int x, int y, int z)
{
	t_pos	*elem;

	elem = *begin_list;
	if (begin_list && *begin_list)
	{
		elem = *begin_list;
		while (elem->next)
		{
			elem = elem->next;
		}
		elem->next = ft_create_elem(x, y, z);
	}
	else
		*begin_list = ft_create_elem(x, y, z);
}

t_pos	*ft_create_elem(int x, int y, int z)
{
	t_pos	*element;

	element = (t_pos*)malloc(sizeof(t_pos));
	element->x = x;
	element->y = y;
	element->z = z;
	element->next = NULL;
	return (element);
}

int		change_color(int z1, int z2, int color)
{
	if (z1 - z2 == 0)
	{
		if (z1 != 0)
			return (z1 * color);
		else
			return (color);
	}
	return (ft_abs(z1 - z2) * color);
}

void	ft_list_clear(t_pos **begin_list)
{
	t_pos	*temp;

	if (!begin_list || !*begin_list)
		return ;
	while (*begin_list)
	{
		temp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(temp);
	}
	*begin_list = NULL;
}

void	ft_list_foreach(t_env *begin_list, void (*f)(t_env *, t_pos *,
			t_pos *, int k), t_pos *pos_list)
{
	t_pos	*pos;

	pos = pos_list;
	while (pos && pos->next)
	{
		(*f)(begin_list, pos, pos->next, 0);
		pos = pos->next;
	}
}
