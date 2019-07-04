/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:54:49 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:17:08 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		ft_put_left_info(t_st *s)
{
	mlx_string_put(s->mlx, s->win, 10, 5, 0xc11f21, "Press ESC to exit");
	mlx_string_put(s->mlx, s->win, 10, 25, 0xc11f21, "Move = < ^ v >");
	mlx_string_put(s->mlx, s->win, 10, 45, 0xc11f21, "Zoom = + -");
	mlx_string_put(s->mlx, s->win, 10, 65, 0xc11f21, "Change deep = 8 5");
	mlx_string_put(s->mlx, s->win, 10, 85, 0xc11f21, "Mouse zoom = scroll");
	mlx_string_put(s->mlx, s->win, 10, 105, 0x280cb2, "by Dzborovk");
	mlx_string_put(s->mlx, s->win, 840, 5, 0xc11f21, "Deep :");
	mlx_string_put(s->mlx, s->win, 840, 25, 0xc11f21, "X    :");
	mlx_string_put(s->mlx, s->win, 840, 45, 0xc11f21, "Y    :");
	mlx_string_put(s->mlx, s->win, 840, 65, 0xc11f21, "Option X:");
	mlx_string_put(s->mlx, s->win, 840, 85, 0xc11f21, "Option Y:");
}

void		ft_bar(t_st *s)
{
	int		bar;
	int		line;

	bar = 0;
	while (bar < 135)
	{
		line = 0;
		while (line < 1000)
		{
			if (line < 210 || line > 820)
				ft_put_pixel(s, line, bar, ft_color(s, 54));
			line++;
		}
		bar++;
	}
}

t_st		*ft_init_struct(void)
{
	t_st	*s;
	int		bpp;
	int		e;

	s = (t_st*)malloc(sizeof(t_st));
	if (!(s))
		ft_error_malloc();
	s->mlx = mlx_init();
	s->img = mlx_new_image(s->mlx, WIDTH, HEIGHT);
	s->matrix = mlx_get_data_addr(s->img, &bpp, &(s->sl), &e);
	s->kind = NULL;
	s->jul = NULL;
	s->mdb = NULL;
	s->bns = NULL;
	s->x = 0;
	s->y = -180;
	s->z = 250;
	s->i = 40;
	s->op_x = WIDTH / 2;
	s->op_y = HEIGHT / 2;
	s->color_m = 0x2d0a3f;
	s->color_v = 1;
	s->button = 0;
	return (s);
}
