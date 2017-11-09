/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:02:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/11/29 17:48:40 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	variation_color(void *structure, int key_code)
{
	t_container *fractol;

	fractol = structure;
	(void)key_code;
	VC = VC == 0 ? 1 : 0;
}

void	active_variation_m(void *structure, int button, int x, int y)
{
	t_container *fractol;

	fractol = structure;
	(void)x;
	(void)y;
	(void)button;
	AV = AV == 0 ? 1 : 0;
}

int		exit_prog(t_container *fractol)
{
	(void)fractol;
	exit(0);
	return (0);
}

int		msg_error(int error)
{
	if (error == 0)
	{
		ft_putendl("usage : ./fractol [fractal name]");
		ft_putendl("Fractal:");
		ft_putendl("-mandelbrot");
		ft_putendl("-julia");
		ft_putendl("-sierpinski");
		ft_putendl("-tricorn");
		ft_putendl("-mandelperp");
		ft_putendl("-celticmandel");
		ft_putendl("-celticperp");
		ft_putendl("-burningshipperp");
		ft_putendl("-buffaloperp");
		ft_putendl("-custom[1,2,3,4,5,6]");
	}
	else if (error == 1)
		ft_putendl("malloc error");
	return (0);
}
