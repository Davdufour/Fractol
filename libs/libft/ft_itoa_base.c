/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 22:08:55 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/25 12:43:21 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size_nbr(int n, int base)
{
	int a;

	a = 1;
	while (n /= base)
		a++;
	return (a);
}

char		*ft_itoa_base(int n, int base)
{
	char		*baze;
	char		*nbr;
	int			a;
	long int	tmp;

	baze = "0123456789ABCDEF";
	tmp = n;
	a = size_nbr(n, base);
	a += (tmp < 0 && base == 10) ? 1 : 0;
	if ((nbr = ft_strnew(a)) == NULL)
		return (NULL);
	if (tmp < 0)
	{
		if (base == 10)
			nbr[0] = '-';
		tmp *= -1;
	}
	if (tmp == 0)
		nbr[0] = '0';
	while (tmp)
	{
		nbr[--a] = baze[tmp % base];
		tmp = tmp / base;
	}
	return (nbr);
}
