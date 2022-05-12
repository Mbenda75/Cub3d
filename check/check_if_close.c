/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 16:08:23 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

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

int	first_lenght(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->lenght - 1)
	{
		if (data->map3[i][0] && (data->map3[i][0] != '1' && \
		data->map3[i][0] != '3'))
			return (0);
		i++;
	}
	return (1);
}

int	check_if_is_close(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!first_lenght(data))
		return (0);
	while (i <= data->lenght - 1)
	{
		j = 0;
		while (j <= data->width - 1)
		{
			if ((data->map3[i][j] && (data->map3[i][j] == '0' || \
			data->map3[i][j] == 'W' || data->map3[i][j] == 'E' || \
			data->map3[i][j] == 'E' || data->map3[i][j] == 'S')) && \
			((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
			(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
			(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
			(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
