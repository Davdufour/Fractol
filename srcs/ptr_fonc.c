/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_fonc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:06:40 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:20:18 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static void	get_addr_fonc_key2(t_container *fractol)
{
	fractol->ptrfonct_eventkey[18] = &change_fractal;
	fractol->ptrfonct_eventkey[19] = &change_fractal;
	fractol->ptrfonct_eventkey[20] = &change_fractal;
	fractol->ptrfonct_eventkey[21] = &change_fractal;
	fractol->ptrfonct_eventkey[23] = &change_fractal;
	fractol->ptrfonct_eventkey[22] = &change_fractal;
	fractol->ptrfonct_eventkey[26] = &change_fractal;
	fractol->ptrfonct_eventkey[28] = &change_fractal;
	fractol->ptrfonct_eventkey[25] = &change_fractal;
	fractol->ptrfonct_eventkey[29] = &change_fractal;
	fractol->ptrfonct_eventkey[27] = &change_fractal;
	fractol->ptrfonct_eventkey[24] = &change_fractal;
	fractol->ptrfonct_eventkey[32] = &change_fractal;
	fractol->ptrfonct_eventkey[34] = &change_fractal;
	fractol->ptrfonct_eventkey[31] = &change_fractal;
	fractol->ptrfonct_eventkey[35] = &change_fractal;
	fractol->ptrfonct_eventkey[33] = &change_fractal;
}

static void	get_addr_fonc_fractal(t_container *fractol)
{
	fractol->ptrfonct_fractal[2] = &sierpinski;
	fractol->ptrfonct_fractal[0] = &mandelbrot;
	fractol->ptrfonct_fractal[3] = &multibrot;
	fractol->ptrfonct_fractal[1] = &julia;
	fractol->ptrfonct_fractal[4] = &multijulia;
	fractol->ptrfonct_fractal[5] = &tricorn;
	fractol->ptrfonct_fractal[6] = &perpendicular_mandelbrot;
	fractol->ptrfonct_fractal[7] = &celtic_mandelbar;
	fractol->ptrfonct_fractal[8] = &celtic_perpendicular;
	fractol->ptrfonct_fractal[9] = &perpendicular_burningship;
	fractol->ptrfonct_fractal[10] = &perpendicular_buffalo;
	fractol->ptrfonct_fractal[11] = &custom1;
	fractol->ptrfonct_fractal[12] = &custom2;
	fractol->ptrfonct_fractal[13] = &custom3;
	fractol->ptrfonct_fractal[14] = &custom4;
	fractol->ptrfonct_fractal[15] = &custom5;
	fractol->ptrfonct_fractal[16] = &custom6;
}

static void	get_addr_fonc_mouse(t_container *fractol)
{
	fractol->ptrfonct_eventmouse[1] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[2] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[4] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[5] = &zoom_in_out;
	fractol->ptrfonct_eventmouse[3] = &active_variation_m;
}

static void	get_addr_fonc_key1(t_container *fractol)
{
	fractol->ptrfonct_eventkey[53] = &exit_fonct;
	fractol->ptrfonct_eventkey[48] = &init_event;
	fractol->ptrfonct_eventkey[0] = &move_leftright;
	fractol->ptrfonct_eventkey[2] = &move_leftright;
	fractol->ptrfonct_eventkey[13] = &move_updown;
	fractol->ptrfonct_eventkey[1] = &move_updown;
	fractol->ptrfonct_eventkey[14] = &itermax;
	fractol->ptrfonct_eventkey[12] = &itermax;
	fractol->ptrfonct_eventkey[50] = &modif_angles;
	fractol->ptrfonct_eventkey[15] = &zoom_keyboard;
	fractol->ptrfonct_eventkey[3] = &zoom_keyboard;
	fractol->ptrfonct_eventkey[6] = &fonction_n;
	fractol->ptrfonct_eventkey[7] = &fonction_n;
	fractol->ptrfonct_eventkey[17] = &change_r;
	fractol->ptrfonct_eventkey[16] = &change_r;
	fractol->ptrfonct_eventkey[5] = &change_g;
	fractol->ptrfonct_eventkey[4] = &change_g;
	fractol->ptrfonct_eventkey[11] = &change_b;
	fractol->ptrfonct_eventkey[45] = &change_b;
	fractol->ptrfonct_eventkey[49] = &active_variation;
	fractol->ptrfonct_eventkey[8] = &variation_color;
}

void		init_ptrfonct(t_container *fractol)
{
	int i;

	i = -1;
	while (++i <= 280)
		fractol->ptrfonct_eventkey[i] = fonctnullkey;
	i = -1;
	while (++i <= 10)
		fractol->ptrfonct_eventmouse[i] = fonctnullmouse;
	get_addr_fonc_key1(fractol);
	get_addr_fonc_key2(fractol);
	get_addr_fonc_mouse(fractol);
	get_addr_fonc_fractal(fractol);
}
