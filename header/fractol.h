/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:53:31 by ddufour           #+#    #+#             */
/*   Updated: 2016/12/12 18:27:43 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx_macos2/mlx.h"
# include <math.h>
# include "X.h"
# include <pthread.h>

#include <stdio.h>

# define NB_TH 5
# define WIDTH 700
# define HEIGHT 700
# define CENTRE_H ((WIDTH / 100) / 1.98)
# define CENTRE_W ((HEIGHT / 100) / 1.98)

# define ITERMAX fractol->event->iteration_max
# define ZOOM fractol->event->zoom
# define MODX fractol->event->modif_x
# define MODY fractol->event->modif_y
# define ANGLES fractol->event->angles
# define VX fractol->event->variation_x
# define VY fractol->event->variation_y
# define N fractol->event->n
# define AV fractol->event->active_varation
# define XTMP fractol->event->xtmp
# define YTMP fractol->event->ytmp
# define R fractol->event->r
# define G fractol->event->g
# define B fractol->event->b
# define FRACTAL fractol->event->fractal
# define VC fractol->event->variation_color

# define MLX fractol->window->mlx
# define WIN fractol->window->win
# define IMG fractol->window->image
# define DATA fractol->window->data
# define BPP fractol->window->bpp
# define ENDIAN fractol->window->endian
# define SIZELINE fractol->window->size_line

# define CR thrd->cr
# define CI thrd->ci
# define ZI thrd->zi
# define ZR thrd->zr
# define TMP thrd->tmp
# define ITER thrd->iter
# define Y thrd->y
# define X thrd->x
# define I thrd->i

typedef struct	s_ev_param
{
	int			fractal;
	int			iteration_max;
	long double	zoom;
	long double	modif_x;
	long double	modif_y;
	long double	n;
	int			active_varation;
	long double	xtmp;
	long double	ytmp;
	int			angles;
	long double	variation_x;
	long double	variation_y;
	long		r;
	long		g;
	long		b;
	int			variation_color;
}				t_ev_param;

typedef struct	s_win_param
{
	void		*mlx;
	void		*win;
	void		*image;
	char		*data;
	int			width;
	int			height;
	int			bpp;
	int			endian;
	int			size_line;
}				t_win_param;

typedef struct	s_thrd
{
	long double cr;
	long double ci;
	long double zi;
	long double zr;
	long double tmp;
	long		iter;
	int			y;
	int			x;
	int			i;
	void		*fractol;
}				t_thrd;

typedef struct	s_container
{
	t_ev_param	*event;
	t_win_param	*window;
	void		(*ptrfonct_eventkey[281])(void *, int);
	void		(*ptrfonct_eventmouse[10])(void *, int, int, int);
	void		(*ptrfonct_fractal[17])(void *, void*);

}				t_container;

int				ft_fractol(t_container *fractol);
void			init_ptrfonct(t_container *fractol);
void			write_data_pixel(t_container *fractol, t_thrd *thrd);

int				motion_mouse(int x, int y, t_container *fractol);
int				key_fonc(int key_code, t_container *fractol);
int				button_fonc(int button, int x, int y, t_container *fractol);
int				exit_prog(t_container *fractol);

void			exit_fonct(void *structure, int key_code);
void			fonctnullkey(void *structure, int key_code);
void			fonctnullmouse(void *structure, int button, int x, int y);
void			move_leftright(void *structure, int key_code);
void			move_updown(void *structure, int key_code);
void			itermax(void *structure, int key_code);
void			modif_angles(void *structure, int key_code);
void			zoom_keyboard(void *structure, int key_code);
void			fonction_n(void *structure, int key_code);
void			zoom_in_out(void *structure, int button, int x, int y);
void			change_fractal(void *structure, int key_code);
void			change_r(void *structure, int key_code);
void			change_g(void *structure, int key_code);
void			change_b(void *structure, int key_code);
void			active_variation(void *structure, int key_code);
void			active_variation_m(void *structure, int button, int x, int y);
void			variation_color(void *structure, int key_code);
void			init_event(void *structure, int key_code);
int				msg_error(int error);

void			multibrot(void *arg, void *arg2);
void			sierpinski(void *arg, void *arg2);
void			mandelbrot(void *arg, void *arg2);
void			julia(void *arg, void *arg2);
void			multijulia(void *arg, void *arg2);
void			tricorn(void *arg, void *arg2);
void			perpendicular_mandelbrot(void *arg, void *arg2);
void			celtic_mandelbar(void *arg, void *arg2);
void			celtic_perpendicular(void *arg, void *arg2);
void			perpendicular_burningship(void *arg, void *arg2);
void			perpendicular_buffalo(void *arg, void *arg2);
void			custom1(void *arg, void *arg2);
void			custom2(void *arg, void *arg2);
void			custom3(void *arg, void *arg2);
void			custom4(void *arg, void *arg2);
void			custom5(void *arg, void *arg2);
void			custom6(void *arg, void *arg2);

#endif
