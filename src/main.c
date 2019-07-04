/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:58:00 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:13:55 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		main(int ac, char **av)
{
	t_st	*s;

	s = ft_init_struct();
	s->win = mlx_new_window(s->mlx, WIDTH, HEIGHT, "Fract'ol");
	if (ac != 2)
		ft_error_argv(s);
	if (!(ft_strcmp(av[1], "julia")))
		s->kind = ft_julia;
	if (!(ft_strcmp(av[1], "mandelbrot")))
		s->kind = ft_mandelbrot;
	if (!(ft_strcmp(av[1], "burningship")))
		s->kind = ft_burningship;
	if (s->kind == NULL)
		ft_error_argv(s);
	mlx_hook(s->win, 6, 1L << 6, ft_mouse_move, s);
	mlx_mouse_hook(s->win, ft_mouse_zoom, s);
	mlx_loop_hook(s->mlx, ft_loop, s);
	s->kind(s);
	ft_key_control(s);
	mlx_loop(s->mlx);
	return (0);
}
