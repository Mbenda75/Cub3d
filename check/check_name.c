/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:16:26 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 18:31:48 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int	ft_check_name_map(char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1) - 4;
	s2 = ".cub";
	while (s1[i])
	{	
		if (s1[i] != *s2++)
			return (0);
		i++;
	}
	return (1);
}

int	check_fd(char *name_map)
{
	int	fd;
	int	tmp;

	tmp = open(name_map, __O_DIRECTORY);
	if (tmp != -1)
	{
		printf("Error \n Problem of file");
		close (tmp);
		return (-1);
	}
	fd = open(name_map, O_RDONLY | __O_NOFOLLOW);
	if (fd == -1)
	{
		printf("Error \n when check_fd");
		close(fd);
		return (-1);
	}
	return (fd);
}
