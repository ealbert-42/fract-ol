/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:42:29 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:48:04 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		commands_disp(t_env *v)
{
	char	*s;

	mlx_string_put(v->mlx, v->win, 0, 0, 0xD3D3D3, "Esc   = Quit");
	mlx_string_put(v->mlx, v->win, 0, 15, 0xD3D3D3, "L     = Lock Movement");
	mlx_string_put(v->mlx, v->win, 0, 30, 0xD3D3D3, "+ / - = Iterations");
	mlx_string_put(v->mlx, v->win, 0, 45, 0xD3D3D3, "C     = Reset");
	mlx_string_put(v->mlx, v->win, 0, 60, 0xD3D3D3, "1|2|3 = Colours");
	mlx_string_put(v->mlx, v->win, 0, 75, 0xD3D3D3, "Fractale : ");
	mlx_string_put(v->mlx, v->win, 102, 75, 0xD3D3D3, v->name);
	s = ft_itoa(v->zoom);
	mlx_string_put(v->mlx, v->win, 0, 90, 0xD3D3D3, "Current zoom : ");
	mlx_string_put(v->mlx, v->win, 143, 90, 0xD3D3D3, s);
	mlx_string_put(v->mlx, v->win, 0, 105, 0xD3D3D3, "Iterations : ");
	s = ft_itoa(v->it);
	mlx_string_put(v->mlx, v->win, 128, 105, 0xD3D3D3, s);
}

void		error_handle(char *s)
{
	ft_putendl(s);
	exit(1);
}

t_env		*var_init(t_env *v)
{
	v->lock = 0;
	v->zoom = 300.0;
	v->clr = 1;
	v->it = 50;
	v->offx = -100;
	v->offy = -100;
	v->it_max = 300;
	v->zi = 0;
	v->zr = 0;
	return (v);
}

void		reset(t_env *v)
{
	v = var_init(v);
}

int			main(int ac, char **av)
{
	t_env *v;

	if (ac != 2)
		error_handle("Usage: ./fractol fractale\njulia, mandelbrot or bship.");
	v = (t_env *)malloc(sizeof(t_env));
	v->name = parse_name(av[1]);
	v = var_init(v);
	mlx_calls(v);
	return (0);
}
