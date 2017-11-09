/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:47:48 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/10 14:32:47 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *str;

	if ((str = (char*)ft_memalloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	str = (char*)ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
