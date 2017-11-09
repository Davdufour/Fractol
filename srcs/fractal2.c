/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:23:19 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 11:58:28 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	perpendicular_buffalo(void *arg, void *arg2)
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
		ZR = fabsl(ZR * ZR - ZI * ZI) + CR;
		ZI = -2 * fabsl(ZI) * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	perpendicular_burningship(void *arg, void *arg2)
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
		ZI = -2 * fabsl(ZI) * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	celtic_perpendicular(void *arg, void *arg2)
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
		ZR = fabsl(ZR * ZR - ZI * ZI) + CR;
		ZI = -2 * ZI * fabsl(TMP) + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	celtic_mandelbar(void *arg, void *arg2)
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
		ZR = fabsl(ZR * ZR - ZI * ZI) + CR;
		ZI = -2 * ZI * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}

void	perpendicular_mandelbrot(void *arg, void *arg2)
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
		ZI = -2 * ZI * fabsl(TMP) + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}
