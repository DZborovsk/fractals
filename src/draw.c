/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:47:35 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:51:33 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			ft_psychedelic(t_st *s)
{
	s->color_m += 10000;
	if (s->color_m >= 0xffffff)
	{
		s->color_m = 0x000000;
	}
	s->color_v += 1;
}

void			ft_put_pixel(t_st *s, int x, int y, unsigned int color)
{
	int		index;

	index = (x * 4) + (y * s->sl);
	s->matrix[index] = color;
	index++;
	s->matrix[index] = color >> 8;
	index++;
	s->matrix[index] = color >> 16;
}

unsigned int	ft_color(t_st *s, int current)
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;
	unsigned int	color;

	if (current == s->i)
	{
		return (s->color_m);
	}
	red = (current * 5) * s->color_v;
	green = (255 - (current * 10)) * s->color_v;
	blue = (255 - (current * 2)) * s->color_v;
	color = (red << 16) + (green << 8) + blue;
	return (color);
}
