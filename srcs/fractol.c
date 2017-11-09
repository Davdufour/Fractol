/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:15:12 by ddufour           #+#    #+#             */
/*   Updated: 2016/12/14 13:55:02 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	write_data_pixel(t_container *fractol, t_thrd *thrd)
{
	DATA[Y * SIZELINE + X * (BPP / 8)] = (B * ITER) / ITERMAX;
	DATA[Y * SIZELINE + X * (BPP / 8) + 1] = (G * ITER) / ITERMAX;
	DATA[Y * SIZELINE + X * (BPP / 8) + 2] = (R * ITER) / ITERMAX;
}

void	*get_fractol(void *arg)
{
	t_container	*fractol;
	t_thrd		*thrd;

	thrd = (t_thrd*)arg;
	fractol = thrd->fractol;
	Y = (I * (HEIGHT / NB_TH)) - 1;
	while (++Y < (HEIGHT / NB_TH) * (I + 1))
	{
		X = -1;
		while (++X < WIDTH)
			fractol->ptrfonct_fractal[FRACTAL](fractol, thrd);
	}
	pthread_exit(0);
}

int		ft_fractol(t_container *fractol)
{
	int			i;
	pthread_t	thread[NB_TH];
	t_thrd		**thrd;

	if (!(thrd = (t_thrd**)malloc(sizeof(t_thrd*) * NB_TH)))
		exit(0);
	i = -1;
	while (++i < NB_TH)
	{
		if (!(thrd[i] = (t_thrd*)malloc(sizeof(t_thrd))))
			exit(0);
		thrd[i]->i = i;
		thrd[i]->fractol = fractol;
		pthread_create(&thread[i], NULL, &get_fractol, thrd[i]);
	}
	i = -1;
	while (++i < NB_TH)
	{
		(void)pthread_join(thread[i], NULL);
		free(thrd[i]);
	}
	free(thrd);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
