/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:25:20 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/07 15:56:44 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		a;

	if (s && f)
	{
		a = ft_strlen(s);
		if ((str = ft_memalloc(a + 1)) == NULL)
			return (NULL);
		str[a] = '\0';
		a = -1;
		while (s[++a])
			str[a] = f(a, s[a]);
		return (str);
	}
	return (NULL);
}
