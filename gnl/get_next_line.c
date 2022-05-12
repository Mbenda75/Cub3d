/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 17:56:28 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 14:32:05 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

char	*ft_save(char *save)
{
	int		i;
	char	*dst;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	dst = (char *)malloc(sizeof(char) * (i + 1));
	if (!dst)
	{
		save = NULL;
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		dst[i] = save[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_resave(char *save)
{
	int		i;
	int		len;
	char	*dst;
	int		j;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	i++;
	len = ft_strlen(save);
	dst = (char *)malloc(sizeof(char) * ((len - i) + 1));
	if (!dst)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	j = 0;
	while (save[i])
		dst[j++] = save[i++];
	free(save);
	save = NULL;
	dst[j] = '\0';
	return (dst);
}

int	get_next_line_protect(int fd, char **save, char **line)
{
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE < 1 || \
	read(fd, NULL, 0) != 0 || !line)
		return (0);
	if (!*save)
		*save = ft_strdup("");
	return (1);
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*save;
	int			rd;

	if (!get_next_line_protect(fd, &save, line))
		return (-1);
	while (!ft_strchr(save, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd == -1)
			return (-1);
		if (rd == 0)
		{
			*line = ft_strdup(save);
			free(save);
			save = 0;
			return (0);
		}
		save = ft_strjoin(save, buffer);
	}
	if (ft_end(save) == 1)
		*line = ft_save(save);
	save = ft_resave(save);
	return (1);
}
