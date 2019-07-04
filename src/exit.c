/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:52:07 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:14:23 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			ft_info(t_st *s)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s5;
	char	*s6;

	s1 = ft_itoa(s->i);
	s2 = ft_itoa(s->x);
	s3 = ft_itoa(s->y + 180);
	s5 = ft_itoa(s->op_x);
	s6 = ft_itoa(s->op_y);
	mlx_string_put(s->mlx, s->win, 945, 5, 0xc11f21, s1);
	mlx_string_put(s->mlx, s->win, 945, 25, 0xc11f21, s2);
	mlx_string_put(s->mlx, s->win, 945, 45, 0xc11f21, s3);
	mlx_string_put(s->mlx, s->win, 945, 65, 0xc11f21, s5);
	mlx_string_put(s->mlx, s->win, 945, 85, 0xc11f21, s6);
	free(s1);
	free(s2);
	free(s3);
	free(s5);
	free(s6);
}

int				ft_exit(t_st *s)
{
	mlx_destroy_window(s->mlx, s->win);
	if (s->jul)
		free(s->jul);
	else if (s->mdb)
		free(s->mdb);
	else if (s->bns)
		free(s->bns);
	free(s);
	exit(1);
}

void			ft_key_control(t_st *s)
{
	mlx_hook(s->win, 17, 1L << 17, ft_exit, s);
	mlx_key_hook(s->win, ft_key_hook, s);
}

void			ft_error_argv(t_st *s)
{
	ft_putendl("Usage: ./fractol <file_name> [mandelbrot/julia/burningship]");
	mlx_destroy_window(s->mlx, s->win);
	exit(1);
}

void			ft_error_malloc(void)
{
	ft_putendl("Malloc error [-1]");
	exit(1);
}
