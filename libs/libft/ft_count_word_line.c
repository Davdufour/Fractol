/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:31:18 by ddufour           #+#    #+#             */
/*   Updated: 2016/10/12 12:41:23 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word_line(char *line, char split)
{
	int word;
	int a;

	word = 0;
	a = 0;
	if (line)
	{
		while (line[a])
		{
			if (line[a] != split)
			{
				word++;
				while (line[a] != ' ' && line[a])
					a++;
			}
			else
				a++;
		}
	}
	return (word);
}
