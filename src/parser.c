/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:52:28 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 19:51:02 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*parse_name(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		ft_tolower(s[i]);
	if (ft_strcmp(s, "julia") == 0)
		;
	else if (ft_strcmp(s, "mandelbrot") == 0)
		;
	else if (ft_strcmp(s, "bship") == 0)
		;
	else
		error_handle("Error 404 :\nFractale not found.");
	return (ft_strdup(s));
}
