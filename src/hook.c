/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:53:43 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:54:27 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				ft_loop(t_st *s)
{
	if (s->button == 1)
	{
		ft_psychedelic(s);
		s->kind(s);
	}
	return (0);
}

static	void	ft_key_reset(int key, t_st *s)
{
	if (key == 15)
	{
		s->x = 0;
		s->y = -180;
		s->z = 250;
		s->op_x = WIDTH / 2;
		s->op_y = HEIGHT / 2;
		s->color_m = 0x2d0a3f;
		s->i = 40;
		s->color_v = 1;
	}
}

static	void	ft_key_move_deep_psy(int key, t_st *s)
{
	if (key == 124)
		s->x += 60;
	if (key == 123)
		s->x -= 60;
	if (key == 91)
		s->i += 10;
	if (key == 125)
		s->y += 60;
	if (key == 126)
		s->y -= 60;
	if (key == 87)
		s->i -= 10;
	if (key == 35)
		s->button = !s->button;
}

static	void	ft_key_zoom(int key, t_st *s)
{
	if (key == 69)
	{
		s->x += WIDTH / 12;
		s->y += HEIGHT / 12;
		s->z = s->z * 1.2;
		s->x = s->x * 1.2;
		s->y = s->y * 1.2;
	}
	if (key == 78)
	{
		if (s->z / 1.2 < 10)
			return ;
		s->x -= WIDTH / 12;
		s->y -= HEIGHT / 12;
		s->z = s->z / 1.2;
		s->x = s->x / 1.2;
		s->y = s->y / 1.2;
	}
}

int				ft_key_hook(int key, t_st *s)
{
	if (key == 53)
		ft_exit(s);
	ft_key_move_deep_psy(key, s);
	ft_key_zoom(key, s);
	ft_key_reset(key, s);
	s->kind(s);
	return (0);
}
