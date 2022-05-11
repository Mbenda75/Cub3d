/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:53:58 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/11 16:41:36 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	free_tab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map3(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->lenght - 1)
	{
		free(data->map3[i]);
		i++;
	}
	free(data->map3);
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}
