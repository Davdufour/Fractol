/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:26:59 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:33:55 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	custom5(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	ZR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CR = 0.285 + VX;
	CI = 0.01 + VY;
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

void	custom6(void *arg, void *arg2)
{
	t_container	*fractol;
	t_thrd		*thrd;

	fractol = arg;
	thrd = arg2;
	ZR = (ANGLES == 0) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	ZI = (ANGLES == 1) ? (((long double)X + XTMP) / ZOOM) - CENTRE_W + MODX :
		(((long double)Y + YTMP) / ZOOM) - CENTRE_H + MODY;
	CR = 0.285 + VX;
	CI = 0.01 + VY;
	ITER = -1;
	while ((ZR * ZR + ZI * ZI < 4) && (++ITER < ITERMAX))
	{
		TMP = ZR;
		ZR = ZR * ZR - ZI * ZI + CR;
		ZI = -2 * ZI * TMP + CI;
	}
	if (VC == 1)
		ITER = ITER != ITERMAX ? 0 : ITER;
	else
		ITER = ITER == ITERMAX ? 0 : ITER;
	write_data_pixel(fractol, thrd);
}
