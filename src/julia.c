/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:56:51 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:57:40 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	t_fractol	*ft_init_julia(void)
{
	t_fractol		*jul;

	jul = (t_fractol*)malloc(sizeof(t_fractol));
	if (jul == NULL)
		ft_error_malloc();
	jul->x1 = -2.1;
	jul->y1 = -1.2;
	jul->x2 = 0.6;
	jul->y2 = 1.2;
	jul->zr = 0;
	jul->zi = 0;
	jul->pr = 0;
	jul->pi = 0;
	jul->temp = 0;
	return (jul);
}

static	int			ft_julia_it(t_st *s)
{
	int		iter;

	iter = 0;
	while (iter < s->i)
	{
		s->jul->temp = s->jul->zr;
		s->jul->zr = s->jul->zr * s->jul->zr - s->jul->zi * s->jul->zi - 0.8 +
			(0.6 / ((double)(s->op_x) / (double)WIDTH));
		s->jul->zi = 2 * s->jul->zi * s->jul->temp + 0.27015 /
			((double)s->op_y / (double)HEIGHT);
		if (s->jul->zi * s->jul->zi + s->jul->zr * s->jul->zr >= 4)
			return (iter);
		iter++;
	}
	return (iter);
}

void				ft_julia(t_st *s)
{
	double		x;
	double		y;

	x = s->x;
	if (s->jul == NULL)
		s->jul = ft_init_julia();
	while (WIDTH + s->x > x)
	{
		y = s->y;
		while (HEIGHT + s->y > y)
		{
			s->jul->zi = (long double)y / s->z + s->jul->y1;
			s->jul->zr = (long double)x / s->z + s->jul->x1;
			ft_put_pixel(s, x - s->x, y - s->y, ft_color(s, ft_julia_it(s)));
			y++;
		}
		x++;
	}
	ft_bar(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_info(s);
	ft_put_left_info(s);
}
