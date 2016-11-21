/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:32:09 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:49:19 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_draw(t_env *v)
{
	int		i;
	double	t;

	i = -1;
	while (++i < v->it && v->zr * v->zr + v->zi * v->zi < 4.0)
	{
		t = v->zr;
		v->zr = v->zr * v->zr - v->zi * v->zi + v->cr;
		v->zi = 2 * v->zi * t + v->ci;
	}
	if (i == v->it)
		ft_pixel_put(v->data, v, 0);
	else
		ft_pixel_put(v->data, v, v->color[i % 6]);
}

void		julia_init(t_env *v)
{
	v->x = -1;
	while (++(v->x) < WIN_X - 1)
	{
		v->y = -1;
		while (++(v->y) < WIN_Y - 1)
		{
			v->cr = 0.285 + v->f;
			v->ci = 0.01 + v->f;
			v->zr = v->x / v->zoom + v->x1;
			v->zi = v->y / v->zoom + v->y1;
			v->t = v->zr;
			v->zr = v->zr * v->zr - v->zi * v->zi + v->cr;
			v->zi = 2 * v->zi * v->t + v->ci;
			julia_draw(v);
		}
	}
}
