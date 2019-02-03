/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:47:27 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/07 03:47:34 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		init_env(t_env *e, char **argv, int fd)
{
	ft_memset(e, 0, sizeof(t_env));
	if ((e->mlx = mlx_init()) == NULL)
		exit(1);
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, argv[0])) == NULL)
		exit(1);
	if ((e->img = mlx_new_image(e->mlx, IMG_X, IMG_Y)) == NULL)
		exit(1);
	e->i_img = mlx_get_data_addr(e->img, &e->bpp, &e->size_l, &e->endian);
	e->nb = 0;
	read_file(fd, e);
	if (e->nb == 0)
	{
		ft_putstr("Invalid map or wrong argument, usage : fdf [valid_map]\n");
		exit(1);
	}
	e->zoom = WIN_Y / e->nb;
	e->start_x = WIN_X / 4;
	e->start_y = WIN_Y / 4;
	e->color = 189;
	e->ampli = 1;
	e->rotat = 1.7;
	e->maxy = WIN_Y;
	e->maxh = WIN_X;
}

int			main(int argc, char **argv)
{
	t_env	env;
	int		fd;
	t_pos	*pos;

	if (argc < 2 || argc > 2 || (fd = open_file(argv[1])) == -1)
	{
		ft_putendl("error");
		fd = 0;
		ft_putstr("Invalid map or wrong argument, usage : fdf [valid_map]\n");
		exit(1);
	}
	init_env(&env, argv, fd);
	pos = env.pos;
	info(env.mlx, env.win);
	draw(&env, pos);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
	mlx_hook(env.win, KEYRELEASE, KEYRELEASEMASK, ft_key_free, &env);
	mlx_mouse_hook(env.win, mouse_hook, &env);
	mlx_hook(env.win, KEYPRESS, KEYPRESSMASK, ft_key_press, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_motion, &env);
	mlx_loop(env.mlx);
	sleep(500000);
	return (0);
}
