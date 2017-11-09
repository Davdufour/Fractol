/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:59:43 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 12:27:04 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	change_r(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	R += (key_code == 17) ? -100 : 100;
}

void	change_g(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	G += (key_code == 5) ? -100 : 100;
}

void	change_b(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	B += (key_code == 11) ? -100 : 100;
}

void	active_variation(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	(void)key_code;
	AV = AV == 0 ? 1 : 0;
}

int		motion_mouse(int x, int y, t_container *fractol)
{
	if (AV == 1)
	{
		VX = (((long double)x - WIDTH / 2) / 150);
		VY = (((long double)y - HEIGHT / 2) / 150);
	}
	return (0);
}
