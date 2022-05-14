/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:16:24 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 20:00:24 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/check.h"

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


int	if_check_in_close(t_data *data, int i, int j)
{
	if ((data->map3[i][j] && (data->map3[i][j] == '0' || \
	data->map3[i][j] == 'W' || data->map3[i][j] == 'E' || \
	data->map3[i][j] == 'N' || data->map3[i][j] == 'S')) && \
	((data->map3[i][j + 1] && data->map3[i][j + 1] == '3') || \
	(data->map3[i][j - 1] && data->map3[i][j - 1] == '3') || \
	(data->map3[i + 1][j] && data->map3[i + 1][j] == '3') || \
	(data->map3[i - 1][j] && data->map3[i - 1][j] == '3')))
		return (0);
	else if (((data->map3[i][j] && (data->map3[i][j] == '0' || \
	data->map3[i][j] == 'W' || data->map3[i][j] == 'E' || \
	data->map3[i][j] == 'N' || data->map3[i][j] == 'S')) && \
	((!data->map3[i][j + 1]) || (!data->map3[i][j - 1]) || \
	(!data->map3[i + 1][j]) || (!data->map3[i - 1][j]))))
		return (0);
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
			if (!if_check_in_close(data, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
