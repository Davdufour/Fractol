/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:57:26 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:32:36 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	itermax(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ITERMAX += key_code == 14 ? 10 : 0;
	ITERMAX -= (key_code == 12) && (ITERMAX >= 10) ? 10 : 0;
}

void	modif_angles(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	(void)key_code;
	ANGLES = (ANGLES == 1) ? 0 : 1;
}

void	zoom_keyboard(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	ZOOM /= (key_code == 3 && ZOOM > 10) ? 1.1 : 1;
	ZOOM *= (key_code == 15) ? 1.1 : 1;
}

void	fonction_n(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	N += (key_code == 6) ? -1 : 1;
}

void	zoom_in_out(void *structure, int button, int x, int y)
{
	t_container *fractol;

	fractol = structure;
	ZOOM /= ((button == 2 || button == 5) && ZOOM > 10) ? 1.1 : 1;
	ZOOM *= (button == 1 || button == 4) ? 1.1 : 1;
	XTMP = (button == 2 || button == 5) ? (XTMP - (x / 11)) / 1.1 :
		(XTMP + (x / 11)) * 1.1;
	YTMP = (button == 2 || button == 5) ? (YTMP - (y / 11)) / 1.1 :
		(YTMP + (y / 11)) * 1.1;
}
