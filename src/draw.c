/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:50:07 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:48:29 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_pixel_put(unsigned char *data, t_env *v, unsigned int color)
{
	if (v->x > 0 && v->x < WIN_X && v->y > 0 && v->y < WIN_Y)
	{
		data[v->y * v->s_line + v->x * v->bpp / 8] =
			(unsigned int)color % 256;
		data[(v->y * v->s_line + v->x * v->bpp / 8) + 1] =
			(unsigned int)(color >> 8) % 256;
		data[(v->y * v->s_line + v->x * v->bpp / 8) + 2] =
			(unsigned int)(color >> 16) % 256;
	}
}

void		draw_which(t_env *v)
{
	if (!ft_strcmp(v->name, "mandelbrot"))
		mandel_init(v);
	if (!ft_strcmp(v->name, "julia"))
		julia_init(v);
	if (!ft_strcmp(v->name, "bship"))
		bship_init(v);
}

void		draw(t_env *v)
{
	v->img = mlx_new_image(v->mlx, WIN_X, WIN_Y);
	v->data = (unsigned char *)mlx_get_data_addr(v->img, &(v->bpp),
		&(v->s_line), &(v->end));
	v->x1 = -(WIN_X / v->zoom / 2) + v->offx / v->zoom;
	v->y1 = -(WIN_Y / v->zoom / 2) + v->offy / v->zoom;
	draw_which(v);
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
}
