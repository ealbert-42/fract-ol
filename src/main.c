/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:42:29 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/20 15:12:11 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		error_handle(char *s)
{
	ft_putendl(s);
	exit(1);
}

int			main(int ac, char **av)
{
	t_env *v;

	if (ac != 2)
		error_handle("Usage: ./fractol \"MAPFILE\"");
	v = (t_env *)malloc(sizeof(t_env));
	v->name = parse_name(av[1]);
	error_handle(v->name);
	return (0);
}
