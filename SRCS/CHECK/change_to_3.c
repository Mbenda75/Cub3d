/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:54:02 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 19:54:05 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/check.h"

int	check_line_close(t_data *data, int line)
{
	int	i;

	i = 0;
	while (data->map[line][i])
	{
		if (data->map[line][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_str3dup(char *s, t_data *data)
{
	int		i;
	char	*s2;

	s2 = malloc(sizeof(char) * (data->width + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i <= data->width - 1)
	{
		s2[i] = '3';
		i++;
	}
	s2[i] = '\0';
	i = 0;
	while (i <= data->width - 1)
	{
		if (s[i] && s[i] != ' ')
			s2[i] = s[i];
		else if (s[i] == ' ')
			s2[i] = '3';
		else
			return (s2);
		i++;
	}
	return (s2);
}

void	change_space_to_3(t_data *data)
{
	int	i;

	i = -1;
	data->lenght = 0;
	if (!data->map)
		return ;
	while (data->map[data->lenght])
		data->lenght++;
	data->map3 = malloc(sizeof(char *) * data->lenght + 1);
	if (!data->map3)
		return ;
	while (++i < data->lenght)
		data->map3[i] = ft_str3dup(data->map[i], data);
}