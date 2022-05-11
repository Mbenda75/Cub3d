/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:12:37 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 18:54:53 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_stronly(const char *s, const char *s2)
{
	int	i;

	i = 0;
	if (!s2)
		return (1);
	while (s2[i])
	{
		if (*s != s2[i] && !ft_isspace(s2[i]))
		{
			printf("Error\n Bad map");
			return (0);
		}
		i++;
	}
	return (1);
}

int	loop_raycast(t_data *data)
{
	key_hook(data);
	draw(data);
	return (0);
}

int	mouse_hook(t_data *data)
{
	if (data->map3)
		free_map3(data);
	if (data->map)
		free_map(data);
	exit_opt(data, "Bye bye \n");
	return (0);
}

char	*ft_strjoinfree(char *s1, char *s2, int to_free)
{
	char	*array;

	array = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	strcpy(array, s1);
	strcpy(array + ft_strlen(s1), s2);
	if (to_free == 1 || to_free == 3)
		free(s1);
	if (to_free == 2 || to_free == 3)
		free(s2);
	return (array);
}

int	check_temp(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
