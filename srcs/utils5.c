/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:05:12 by ddufour           #+#    #+#             */
/*   Updated: 2016/12/01 13:44:37 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int		key_fonc(int key_code, t_container *fractol)
{
	fractol->ptrfonct_eventkey[key_code](fractol, key_code);
	return (0);
}

int		button_fonc(int button, int x, int y, t_container *fractol)
{
	fractol->ptrfonct_eventmouse[button](fractol, button, x, y);
	return (0);
}

void	init_event(void *structure, int key_code)
{
	t_container *fractol;

	(void)key_code;
	fractol = structure;
	ITERMAX = 51;
	MODX = 0;
	MODY = 0;
	ANGLES = 0;
	ZOOM = 100;
	VX = 0;
	N = 2;
	VY = 0;
	AV = 0;
	VC = 0;
	XTMP = 0;
	YTMP = 0;
	R = 255;
	G = 255;
	B = 255;
}

void	change_fractal(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	FRACTAL = key_code == 18 ? 2 : FRACTAL;
	FRACTAL = key_code == 19 ? 0 : FRACTAL;
	FRACTAL = key_code == 20 ? 1 : FRACTAL;
	FRACTAL = key_code == 21 ? 16 : FRACTAL;
	FRACTAL = key_code == 23 ? 15 : FRACTAL;
	FRACTAL = key_code == 22 ? 11 : FRACTAL;
	FRACTAL = key_code == 26 ? 14 : FRACTAL;
	FRACTAL = key_code == 28 ? 12 : FRACTAL;
	FRACTAL = key_code == 25 ? 13 : FRACTAL;
	FRACTAL = key_code == 29 ? 10 : FRACTAL;
	FRACTAL = key_code == 27 ? 5 : FRACTAL;
	FRACTAL = key_code == 24 ? 6 : FRACTAL;
	FRACTAL = key_code == 32 ? 7 : FRACTAL;
	FRACTAL = key_code == 34 ? 8 : FRACTAL;
	FRACTAL = key_code == 31 ? 9 : FRACTAL;
	FRACTAL = key_code == 35 ? 4 : FRACTAL;
	FRACTAL = key_code == 33 ? 3 : FRACTAL;
}
