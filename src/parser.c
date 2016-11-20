/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:52:28 by ealbert           #+#    #+#             */
/*   Updated: 2016/11/20 15:13:45 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char	*parse_name(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		ft_tolower(s[i]);
	if (ft_strcmp(s, JULIA) == 0)
		return (ft_strdup(s));
	if (ft_strcmp(s, MANDEL) == 0)
		return (ft_strdup(s));
	if (ft_strcmp(s, CARPET) == 0)
		return (ft_strdup(s));
	if (ft_strcmp(s, TRIFRC) == 0)
		return (ft_strdup(s));
	if (ft_strcmp(s, SNWFLK) == 0)
		return (ft_strdup(s));
	error_handle("Error 404 :\nFractale not found.");
	return (NULL);
}
