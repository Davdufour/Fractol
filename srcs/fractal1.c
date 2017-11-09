/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:15:39 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:16:56 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	julia(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	ZR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CR = 0.285 + VX;
	CI = 0.01 + VY;
	ITER = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++ITER < ITERMAX))
	{
		TMP = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	multijulia(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	ZR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CR = 0.285 + VX;
	CI = 0.01 + VY;
	ITER = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++ITER < ITERMAX))
	{
		TMP = ZR;
		ZR = ((ZR * ZR + ZI * ZI) * ((long double)N / 2)) *
			(long double)cos((long double)N * (long double)atan2l(ZI, ZR)) + CR;
		ZI = ((TMP * TMP + ZI * ZI) * ((long double)N / 2)) * (long double)sin(
			(long double)N * (long double)atan2l(ZI, TMP)) + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	mandelbrot(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	CR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZR = 0;
	ZI = 0;
	ITER = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++ITER < ITERMAX))
	{
		TMP = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = 2 * ZI * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	sierpinski(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	CI = (ANGLES == 0) ? fabsl((long double)X - CENTRE_W + MODX) :
		fabsl((long double)Y - CENTRE_H + MODY);
	CR = (ANGLES == 1) ? fabsl((long double)X - CENTRE_W + MODX) :
		fabsl((long double)Y - CENTRE_H + MODY);
	ITER = -1;
	while (((int)CR % 3 != 1 || ((int)CI % 3) != 1) && ++ITER < ITERMAX)
	{
		CR /= 3;
		CI /= 3;
	}
	if (VC == 1)
		ITER = ITER == ITERMAX ? 0 : ITER;
	else
		ITER = ITER != ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	multibrot(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	CR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZR = 0;
	ZI = 0;
	ITER = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++ITER < ITERMAX))
	{
		TMP = ZR;
		ZR = ((ZR * ZR + ZI * ZI) * ((long double)N / 2)) * (long double)cos(
			(long double)N * (long double)atan2l(ZI, ZR)) + CR;
		ZI = ((TMP * TMP + ZI * ZI) * ((long double)N / 2)) * (long double)sin(
			(long double)N * (long double)atan2l(ZI, TMP)) + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}
