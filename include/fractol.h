/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:43:04 by dzborovk          #+#    #+#             */
/*   Updated: 2018/09/11 12:10:13 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIDTH 1000
# define HEIGHT 800

typedef	struct			s_st
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*matrix;
	void				(*kind)();
	double				x;
	double				y;
	intmax_t			z;
	struct s_fractol	*jul;
	struct s_fractol	*mdb;
	struct s_fractol	*bns;
	int					i;
	int					op_x;
	int					op_y;
	int					sl;
	unsigned int		color_m;
	int					color_v;
	int					button;
}						t_st;

typedef struct			s_fractol
{
	long double			temp;
	long double			pi;
	long double			pr;
	long double			x1;
	long double			y1;
	long double			x2;
	long double			y2;
	long double			zi;
	long double			zr;
}						t_fractol;

void					ft_error_argv(t_st *s);
void					ft_put_left_info(t_st *s);
t_st					*ft_init_struct(void);
void					ft_error_malloc(void);
void					ft_put_pixel(t_st *s, int x, int y, unsigned int color);
unsigned int			ft_color(t_st *s, int current);
void					ft_julia(t_st *e);
void					ft_key_control(t_st *s);
void					ft_mandelbrot(t_st *s);
void					ft_burningship(t_st *s);
int						ft_key_hook(int key, t_st *s);
int						ft_exit(t_st *s);
void					ft_info(t_st *s);
void					ft_bar(t_st *fdf);
void					ft_psychedelic(t_st *s);
int						ft_loop(t_st *s);
int						ft_mouse_zoom(int key, int x, int y, t_st *s);
int						ft_mouse_move(int x, int y, t_st *s);

#endif
