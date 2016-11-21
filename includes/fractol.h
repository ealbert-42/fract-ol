/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:52:28 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/21 22:49:46 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H
# define WIN_X 1000
# define WIN_Y 1000
# define X_CENTER (WIN_X / 2)
# define Y_CENTER (WIN_Y / 2)
# define ITER_P 69
# define ITER_M 78
# define BREXIT 53
# define COLOR1 18
# define COLOR2 19
# define COLOR3 20
# define LOCK 37
# define RESET 15

# define CYAN 0x002FFFFF
# define VIOLET 0x00FF2FFF
# define GREEN 0x002FFF2F
# define ORANGE 0x00FFA12F
# define RED 0x00FF2F2F
# define PINK 0x00FFA5FF
# define BROWN 0x00945800
# define BLUE 0x002F2FFF
# define PURPLE 0x00A12FA4
# define YELLOW 0x00FFFF2F

# include "libft.h"
# include "mlx.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				s_line;
	int				bpp;
	int				end;
	unsigned char	*data;
	char			*name;
	int				clr;
	int				it;
	int				it_max;
	double			zi;
	double			zr;
	double			cr;
	double			ci;
	double			t;
	double			offx;
	double			offy;
	int				x;
	int				y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			f;
	unsigned int	*color;
	int				lock;
	double			zoom;
}					t_env;

/*
** main.c :
*/

void				error_handle(char *s);
void				commands_disp(t_env *v);
void				reset(t_env *v);

/*
** parser.c :
*/

char				*parse_name(char *s);

/*
** hooks.c :
*/

void				mlx_calls(t_env *v);

/*
** color.c :
*/

void				color_calc(t_env *v, int i);

/*
** draw.c :
*/

void				draw(t_env *v);
void				ft_pixel_put(unsigned char *data,
						t_env *v, unsigned int color);

/*
** mandel.c :
*/

void				mandel_init(t_env *v);

/*
** julia.c :
*/

void				julia_init(t_env *v);

/*
** bship.c :
*/

void				bship_init(t_env *v);

#endif
