/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:44:39 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:47:07 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	t_fractol	*ft_init_burningship(void)
{
	t_fractol	*bns;

	bns = (t_fractol*)malloc(sizeof(t_fractol));
	if (!(bns))
	{
		ft_error_malloc();
	}
	bns->zr = 0;
	bns->zi = 0;
	bns->pr = 0;
	bns->pi = 0;
	bns->temp = 0;
	bns->x1 = -2.1;
	bns->y1 = -1.2;
	bns->x2 = 0.6;
	bns->y2 = 1.2;
	return (bns);
}

static	int			ft_burningship_it(t_st *s)
{
	int		iter;

	iter = 0;
	while (iter < s->i)
	{
		s->bns->temp = s->bns->zr;
		s->bns->zr = s->bns->zr * s->bns->zr - s->bns->zi * s->bns->zi +
			s->bns->pr;
		s->bns->zi = 2 * fabsl(s->bns->zi * s->bns->temp) + s->bns->pi;
		if (s->bns->zr * s->bns->zr + s->bns->zi * s->bns->zi >= 4)
			return (iter);
		iter++;
	}
	return (iter);
}

void				ft_burningship(t_st *s)
{
	double		x;
	double		y;

	x = s->x;
	if (s->bns == NULL)
		s->bns = ft_init_burningship();
	while (WIDTH + s->x > x)
	{
		y = s->y;
		while (y < HEIGHT + s->y)
		{
			s->bns->zi = 0;
			s->bns->zr = 0;
			s->bns->pi = (long double)y / s->z + s->bns->y1;
			s->bns->pr = (long double)x / s->z + s->bns->x1;
			ft_put_pixel(s, x - s->x, y - s->y,
					ft_color(s, ft_burningship_it(s)));
			y++;
		}
		x++;
	}
	ft_bar(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_info(s);
	ft_put_left_info(s);
}
