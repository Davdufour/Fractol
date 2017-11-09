/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:42:59 by ddufour           #+#    #+#             */
/*   Updated: 2016/09/19 18:24:52 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if ((str = (char*)ft_memalloc(len + 1)) == NULL)
		return (NULL);
	str[len] = '\0';
	str = ft_memcpy(str, s + start, len);
	return (str);
}
