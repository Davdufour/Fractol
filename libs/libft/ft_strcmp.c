/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 18:55:23 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/08 12:05:57 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int a;

	a = 0;
	while (s1[a] == s2[a] && s1[a] && s2[a])
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
