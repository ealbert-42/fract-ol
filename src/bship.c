/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bship.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:54:20 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:48:17 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	absolute(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static void		bship_draw(t_env *v)
{
	int				i;
	double			t;

	i = 0;
	while (v->zr * v->zr + v->zi * v->zi < 4.0 && i < v->it)
	{
		t = v->zr;
		v->zr = v->zr * v->zr - v->zi * v->zi + v->cr;
		v->zi = 2.0 * absolute(t * v->zi) + v->ci;
		i++;
	}
	if (i == v->it)
		ft_pixel_put(v->data, v, 0);
	else
		ft_pixel_put(v->data, v, v->color[i % 6]);
}

void			bship_init(t_env *v)
{
	v->y = -1;
	while (++(v->y) < WIN_Y - 1)
	{
		v->x = -1;
		while (++(v->x) < WIN_X - 1)
		{
			v->cr = (v->x / v->zoom) + v->x1;
			v->ci = (v->y / v->zoom) + v->y1;
			v->zr = 0.0 + v->f;
			v->zi = 0.0 + v->f;
			bship_draw(v);
		}
	}
}
