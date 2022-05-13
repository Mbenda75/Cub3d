/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:50:37 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 14:03:56 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/check.h"

int	check_letter_error(t_data *data)
{
	free_map(data);
	exit_opt(data, "Error \n use of wrong character\n");
	return (0);
}

int	check_letter(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	if (!data->map)
		return (0);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] && (data->map[j][i] != '0' && \
			data->map[j][i] != '1' && data->map[j][i] != 'N' && \
			data->map[j][i] != 'S' && data->map[j][i] != 'E' && \
			data->map[j][i] != 'W' && data->map[j][i] != ' '))
				return (check_letter_error(data));
			i++;
		}
		j++;
	}
	return (1);
}

int	if_status0(int status)
{
	if (status == 0)
	{
		printf("%s\n", "Error \n It's missing a position point\n");
		return (0);
	}
	return (1);
}

int	if_status1(void)
{
	printf("%s\n", "Error \n multiple position point\n");
	return (0);
}

int	check_duplicate_position(t_data *data)
{
	int	i;
	int	j;
	int	status;

	j = 0;
	status = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i] && (data->map[j][i] == 'N' || \
			data->map[j][i] == 'S' || data->map[j][i] == 'E' || \
			data->map[j][i] == 'W'))
			{
				if (status >= 1)
					return (if_status1());
				status++;
			}
			i++;
		}
		j++;
	}
	return (if_status0(status));
}
