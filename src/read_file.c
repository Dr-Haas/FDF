/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:47:39 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/19 18:35:15 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_usage(void)
{
	ft_putendl("Usage : ./fdf <map>");
	exit(0);
}

int				open_file(char *file)
{
	int fd;

	fd = open(file, O_DIRECTORY | O_RDONLY);
	if (fd > 0)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_usage();
	return (fd);
}

void			del_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

t_pos			*file_list(t_pos *pos, char *line, int y, t_env *env)
{
	char	**tab;
	int		x;
	int		z;

	x = -1;
	if (ft_str_twodigits(line) == 0)
		return (NULL);
	tab = ft_strsplit(line, ' ');
	while (tab[++x])
	{
		z = ft_atoi(tab[x]);
		ft_list_return(&pos, x, y, z);
	}
	del_tab(tab);
	if (y != 0 && x != env->nb)
		return (NULL);
	env->nb = x;
	return (pos);
}

void			read_file(int fd, t_env *env)
{
	int			y;
	char		*line;
	t_pos		*pos;
	int			a;

	line = NULL;
	pos = NULL;
	y = -1;
	while ((a = get_next_line(fd, &line)) > 0)
	{
		if (a < 0)
			exit(1);
		pos = file_list(pos, line, ++y, env);
		ft_strdel(&line);
		env->nb_line = y;
		if (pos == NULL)
		{
			ft_putstr("Invalid map or wrong argument\
					, usage : fdf [valid_map]\n");
			exit(1);
		}
	}
	ft_strdel(&line);
	close(fd);
	env->pos = pos;
}
