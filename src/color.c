/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 18:53:39 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:45:03 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		color_1(t_env *v)
{
	if (v->color)
		free(v->color);
	v->color = (unsigned int *)malloc(sizeof(unsigned int) * 6);
	v->color[0] = PURPLE;
	v->color[1] = BLUE;
	v->color[2] = GREEN;
	v->color[3] = YELLOW;
	v->color[4] = ORANGE;
	v->color[5] = RED;
}

static void		color_2(t_env *v)
{
	if (v->color)
		free(v->color);
	v->color = (unsigned int *)malloc(sizeof(unsigned int) * 6);
	v->color[0] = PINK;
	v->color[1] = ORANGE;
	v->color[2] = PURPLE;
	v->color[3] = RED;
	v->color[4] = GREEN;
	v->color[5] = CYAN;
}

static void		color_3(t_env *v)
{
	if (v->color)
		free(v->color);
	v->color = (unsigned int *)malloc(sizeof(unsigned int) * 6);
	v->color[0] = BLUE;
	v->color[1] = GREEN;
	v->color[2] = PINK;
	v->color[3] = ORANGE;
	v->color[4] = VIOLET;
	v->color[5] = RED;
}

void			color_calc(t_env *v, int i)
{
	if (i == 1)
	{
		v->clr = 1;
		color_1(v);
	}
	else if (i == 2)
	{
		v->clr = 2;
		color_2(v);
	}
	else if (i == 3)
	{
		v->clr = 3;
		color_3(v);
	}
}
