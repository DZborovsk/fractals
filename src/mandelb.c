/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:58:27 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:59:10 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	t_fractol	*ft_init_mandelbrot(void)
{
	t_fractol	*mdb;

	mdb = (t_fractol*)malloc(sizeof(t_fractol));
	if (!(mdb))
	{
		ft_error_malloc();
	}
	mdb->zr = 0;
	mdb->zi = 0;
	mdb->pr = 0;
	mdb->pi = 0;
	mdb->temp = 0;
	mdb->x1 = -2.1;
	mdb->y1 = -1.2;
	mdb->x2 = 0.6;
	mdb->y2 = 1.2;
	return (mdb);
}

static	int			ft_mandelb_it(t_st *s)
{
	int		iter;

	iter = 0;
	while (iter < s->i)
	{
		s->mdb->temp = s->mdb->zr;
		s->mdb->zr = s->mdb->zr * s->mdb->zr - s->mdb->zi * s->mdb->zi +
			s->mdb->pr;
		s->mdb->zi = 2 * s->mdb->zi * s->mdb->temp + s->mdb->pi;
		if (s->mdb->zi * s->mdb->zi + s->mdb->zr * s->mdb->zr >= 4)
			return (iter);
		iter++;
	}
	return (iter);
}

void				ft_mandelbrot(t_st *s)
{
	double	x;
	double	y;

	x = s->x;
	if (s->mdb == NULL)
		s->mdb = ft_init_mandelbrot();
	while (WIDTH + s->x > x)
	{
		y = s->y;
		while (HEIGHT + s->y > y)
		{
			s->mdb->zi = 0;
			s->mdb->zr = 0;
			s->mdb->pi = (long double)y / s->z + s->mdb->y1;
			s->mdb->pr = (long double)x / s->z + s->mdb->x1;
			ft_put_pixel(s, x - s->x, y - s->y, ft_color(s, ft_mandelb_it(s)));
			y++;
		}
		x++;
	}
	ft_bar(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_info(s);
	ft_put_left_info(s);
}
