/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:59:24 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 11:59:38 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_mouse_move(int x, int y, t_st *s)
{
	s->op_x = x;
	s->op_y = y;
	s->kind(s);
	ft_info(s);
	return (0);
}

int		ft_mouse_zoom(int key, int x, int y, t_st *s)
{
	if (key == 4)
	{
		s->x += x / 5;
		s->y += y / 5;
		s->z = s->z * 1.2;
		s->y = s->y * 1.2;
		s->x = s->x * 1.2;
	}
	if (key == 5)
	{
		s->x -= x / 5;
		s->y -= y / 5;
		s->z = s->z / 1.2;
		s->y = s->y / 1.2;
		s->x = s->x / 1.2;
	}
	s->kind(s);
	return (0);
}
