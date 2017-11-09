/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 22:00:03 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/07 12:48:05 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len_s1;
	size_t a;

	a = -1;
	len_s1 = ft_strlen(s1);
	while (++a < n)
		s1[len_s1 + a] = s2[a];
	s1[len_s1 + a] = '\0';
	return (s1);
}
