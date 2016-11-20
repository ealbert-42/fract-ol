/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:52:28 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/20 15:13:23 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIN_X 1600
# define WIN_Y 900
# define JULIA "julia"
# define MANDEL "mandelbrot"
# define CARPET "carpet"
# define TRIFRC "triforce"
# define SNWFLK "snowflake"

# include "libft.h"
# include "mlx.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned char	*data;
	char			*name;
}					t_env;

/*
** main.c :
*/

void				error_handle(char *s);

/*
** parser.c :
*/

char	*parse_name(char *s);

#endif
