/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:47:51 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/19 10:03:49 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define RED 0x0FF0000
#define WHT 0x0FFFFFF

void	info(void *mlx, void *win)
{
	mlx_string_put(mlx, win, IMG_X + 150, 30, RED, "FDF");
	mlx_string_put(mlx, win, IMG_X + 5, 270, WHT,
		"- Utilise les flêches pour bouger");
	mlx_string_put(mlx, win, IMG_X + 5, 290, WHT,
		"- 7 et 8 pour changer les couleur");
	mlx_string_put(mlx, win, IMG_X + 5, 310, WHT,
		"- Utilise * pour augmenter la hauteur");
	mlx_string_put(mlx, win, IMG_X + 5, 330, WHT,
		"- Utilise / pour baisser la hauteur");
	mlx_string_put(mlx, win, IMG_X + 5, 350, WHT,
		"- Utilise 1 pour élargir la vue");
	mlx_string_put(mlx, win, IMG_X + 5, 370, WHT,
		"- Utilise 4 pour reduire la vue");
	mlx_string_put(mlx, win, IMG_X + 5, 390, WHT, "- Click pour bouger");
	mlx_string_put(mlx, win, IMG_X + 5, 410, WHT, "- Utilise +/- ou scroll");
	mlx_string_put(mlx, win, IMG_X + 5, 430, WHT, "pour zoomer ou dé-szoomer");
}

int		ft_key_free(int key, t_env *env)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_image(env->mlx, env->img);
		mlx_destroy_window(env->mlx, env->win);
		exit(1);
	}
	return (0);
}

int		ft_key_press(int key, t_env *env)
{
	if (key == KEY_PLUS || key == KEY_MINUS)
		env->zoom += key == KEY_PLUS || env->zoom <= 2 ? 2 : -2;
	else if (key == KEY_UP)
		env->start_y -= 0.3 * env->nb;
	else if (key == KEY_DOWN)
		env->start_y += 0.3 * env->nb;
	else if (key == KEY_RIGHT)
		env->start_x += 0.3 * env->nb;
	else if (key == KEY_LEFT)
		env->start_x -= 0.3 * env->nb;
	else if (key == KEY_R)
		env->zoom = WIN_Y / env->nb;
	else if (key == KEY_8 || key == KEY_7)
		env->color += key == KEY_8 ? 5000 : -5000;
	else if (key == KEY_STAR || key == KEY_BACKSLACH)
		env->ampli += key == KEY_STAR ? 1 : -1;
	else if (key == KEY_4 || key == KEY_1)
		env->rotat += key == KEY_4 ? 0.1 : -0.1;
	refresh(env);
	return (0);
}

int		mouse_motion(int x, int y, t_env *env)
{
	if (env->move)
	{
		env->start_y = y - (env->nb * env->zoom) / 2;
		env->start_x = x - (env->nb_line * env->zoom) / 2;
	}
	refresh(env);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (button == 5 || button == 4)
		env->zoom += button == 5 || env->zoom <= 2 ? 2 : -2;
	if (button == 1)
		env->move = env->move == 1 ? 0 : 1;
	refresh(env);
	return (0);
}
