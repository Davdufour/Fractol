/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddufour <ddufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:15:53 by ddufour           #+#    #+#             */
/*   Updated: 2016/09/20 16:26:45 by ddufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_content	*creat_and_check(int fd, t_content **gnl, int choix)
{
	t_content *cpy;

	if (choix == 1)
	{
		if (!(cpy = (t_content*)malloc(sizeof(t_content))))
			return (NULL);
		cpy->content = NULL;
		cpy->file_descriptor = fd;
		cpy->next = NULL;
	}
	else
	{
		cpy = *gnl;
		while (cpy->file_descriptor != fd)
		{
			cpy = cpy->next;
			if (cpy == NULL)
				return (NULL);
		}
	}
	return (cpy);
}

static	char		*fonction_norm(t_content **cpy, int a)
{
	char	*tmp;

	tmp = ft_strsub((*cpy)->content, 0, a);
	(*cpy)->content = ft_strsubfree(
		(*cpy)->content, a + 1, ft_strlen((*cpy)->content) - ft_strlen(tmp));
	(*cpy)->retour = 1;
	return (tmp);
}

static	char		*extract_line(t_content **cpy)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	int		a;

	ret = 1;
	if (!((*cpy)->content))
		if (!((*cpy)->content = (char*)ft_memalloc(sizeof(char) * 1)))
			return (NULL);
	while (ret != 0)
	{
		if ((ret = read((*cpy)->file_descriptor, buff, BUFF_SIZE)) < 0)
			return (NULL);
		buff[ret] = '\0';
		if (!((*cpy)->content = ft_strjoinfree((*cpy)->content, buff)))
			return (NULL);
		a = -1;
		while ((*cpy)->content[++a])
			if ((*cpy)->content[a] == '\n')
				return (fonction_norm(cpy, a));
	}
	if (a > 0)
		return (fonction_norm(cpy, a));
	else
		(*cpy)->retour = 0;
	return ((*cpy)->content);
}

static int			ft_free(t_content **list, int fd)
{
	t_content	*cpy;
	t_content	*tmp;

	cpy = *list;
	tmp = *list;
	if ((*list)->file_descriptor == fd)
		(*list) = (*list)->next;
	else
	{
		while (cpy->next->file_descriptor != fd && cpy->next)
			cpy = cpy->next;
		tmp = cpy->next;
		cpy->next = cpy->next->next;
	}
	free(tmp->content);
	free(tmp);
	tmp = NULL;
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static	t_content	*gnl = NULL;
	t_content			*cpy;

	if (!line)
		return (-1);
	if (!gnl)
		gnl = creat_and_check(fd, NULL, 1);
	if ((cpy = creat_and_check(fd, &gnl, 0)) == NULL)
	{
		cpy = gnl;
		while (cpy->next)
			cpy = cpy->next;
		cpy->next = creat_and_check(fd, NULL, 1);
		cpy = cpy->next;
	}
	if (!(*line = extract_line(&cpy)))
		return (-1);
	if (cpy->retour == 0)
		return (ft_free(&gnl, fd));
	return (cpy->retour);
}
