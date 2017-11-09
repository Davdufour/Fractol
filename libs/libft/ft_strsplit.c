/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 18:42:54 by ddufour           #+#    #+#             */
/*   Updated: 2016/06/24 19:04:19 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_count(char const *s, char c, int a)
{
	int b;

	b = 0;
	while (s[a] != c && s[a])
	{
		b++;
		a++;
	}
	return (b);
}

static int	size_tab(char const *s, char c)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (s[a])
	{
		if (s[a] != c)
		{
			while (s[a] != c && s[a] != '\0')
				a++;
			b++;
		}
		else
			a++;
	}
	return (b);
}

char		**ft_strsplit(char const *s, char c)
{
	int		a;
	int		b;
	int		d;
	char	**tab;

	if (!s || !(tab = (char**)ft_memalloc(sizeof(char*) * size_tab(s, c) + 1)))
		return (NULL);
	tab[size_tab(s, c)] = NULL;
	a = 0;
	b = -1;
	while (s[a])
	{
		if (s[a] != c)
		{
			d = 0;
			if ((tab[++b] = (char*)ft_memalloc(sizeof(char)
				* char_count(s, c, a) + 1)) == NULL)
				return (NULL);
			while (s[a] != c && s[a] != '\0')
				tab[b][d++] = s[a++];
		}
		else
			a++;
	}
	return (tab);
}
