/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 03:48:21 by ghaas             #+#    #+#             */
/*   Updated: 2018/03/13 17:01:50 by ghaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "keycode.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define WIN_X 1700
# define WIN_Y 1200
# define IMG_X 1220
# define IMG_Y 1200

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_draw;

typedef struct		s_pos
{
	int				x;
	int				y;
	int				z;
	struct s_pos	*next;
}					t_pos;

typedef struct		s_env
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*i_img;
	int				bpp;
	int				size_l;
	int				endian;

	t_pos			*pos;

	int				nb;
	int				nb_line;

	int				maxy;
	int				maxh;

	int				ampli;
	int				color;
	int				zoom;
	double			rotat;
	int				start_x;
	int				start_y;
	int				move;
}					t_env;

void				read_file(int fd, t_env *env);
int					open_file(char *file);
int					mouse_motion(int x, int y, t_env *env);
int					mouse_hook(int button, int x, int y, t_env *env);
int					ft_key_press(int key, t_env *env);
int					ft_key_free(int key, t_env *env);
void				info(void *mlx, void *win);
int					change_color(int z1, int z2, int color);
void				refresh(t_env *env);
void				draw(t_env *env, t_pos *pos);
void				draw_line(t_env *env, t_pos *one, t_pos *other, int k);
void				ft_put_pixel(t_env *env, int x, int y, int color);
void				ft_list_return(t_pos **begin_list, int x, int y, int z);
t_pos				*ft_create_elem(int x, int y, int z);
void				ft_list_clear(t_pos **begin_list);
void				ft_list_foreach(t_env *begin_list, void (*f)(t_env *,
			t_pos *, t_pos *, int k), t_pos *pos_list);

#endif
