/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 12:19:43 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/29 17:06:41 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_map(char *av)
{
	int		ret;
	int		fd;
	char	*map;
	char	*buff;

	if (!(map = (char*)ft_memalloc(sizeof(char) * 1)))
		return (NULL);
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		if (!(map = ft_strjoinfree(map, buff)))
			return (NULL);
		if (!(map = ft_strjoinfree(map, "\n")))
			return (NULL);
		free(buff);
	}
	if (ret == -1)
		return (NULL);
	close(fd);
	return (map);
}
