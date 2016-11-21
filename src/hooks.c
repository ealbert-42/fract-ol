/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:48:39 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:43:49 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	refresher(t_env *v)
{
	mlx_clear_window(v->mlx, v->win);
	draw(v);
	commands_disp(v);
	return (0);
}

int			on_mousemove(int x, int y, t_env *v)
{
	double	t;

	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		if (v->lock)
		{
			v->x2 = (double)x / v->zoom + v->x1;
			v->y2 = (double)y / v->zoom + v->y1;
			t = v->x2 * v->y2 / 4;
			if (t)
				v->f = t;
		}
		refresher(v);
	}
	return (0);
}

int			on_mouseclick(int keycode, int x, int y, t_env *v)
{
	if (keycode == 4 || keycode == 1)
	{
		v->zoom *= 1.05;
		v->offx += x - X_CENTER;
		v->offy += y - Y_CENTER;
		if (v->zoom < 1)
			v->zoom = 1;
	}
	else if (keycode == 5 || keycode == 2)
	{
		v->zoom /= 1.05;
		v->offx -= x - X_CENTER;
		v->offy -= y - Y_CENTER;
		if (v->zoom < 1)
			v->zoom = 1;
	}
	refresher(v);
	return (0);
}

int			on_keydown(int keycode, t_env *v)
{
	if (keycode == COLOR1)
		color_calc(v, 1);
	else if (keycode == COLOR2)
		color_calc(v, 2);
	else if (keycode == COLOR3)
		color_calc(v, 3);
	else if (keycode == ITER_P)
		v->it += (v->it < v->it_max) ? 1 : 0;
	else if (keycode == ITER_M)
		v->it -= (v->it > 1) ? 1 : 0;
	else if (keycode == BREXIT)
		exit(1);
	else if (keycode == LOCK)
		v->lock = (v->lock == 0) ? 1 : 0;
	else if (keycode == RESET)
		reset(v);
	refresher(v);
	return (0);
}

void		mlx_calls(t_env *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_X, WIN_Y, "Fract'ol");
	color_calc(v, 1);
	draw(v);
	mlx_mouse_hook(v->win, on_mouseclick, v);
	mlx_hook(v->win, 6, 2, on_mousemove, v);
	mlx_expose_hook(v->win, refresher, v);
	mlx_hook(v->win, 2, 2, on_keydown, v);
	mlx_loop(v->mlx);
}
