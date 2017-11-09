/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:37:22 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:28:07 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	exit_fonct(void *structure, int key_code)
{
	(void)structure;
	(void)key_code;
	exit(0);
}

void	fonctnullkey(void *structure, int key_code)
{
	(void)structure;
	(void)key_code;
}

void	fonctnullmouse(void *structure, int button, int x, int y)
{
	(void)structure;
	(void)button;
	(void)x;
	(void)y;
}

void	move_leftright(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	if (FRACTAL == 2)
		MODX += (key_code == 2) ? 5 : -5;
	else
		MODX += (key_code == 2) ? -10 / ZOOM : 10 / ZOOM;
}

void	move_updown(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	if (FRACTAL == 2)
		MODY += (key_code == 1) ? 5 : -5;
	else
		MODY += (key_code == 1) ? -10 / ZOOM : 10 / ZOOM;
}
