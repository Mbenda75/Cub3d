/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:16:36 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 13:50:22 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/parse.h"

int	size_width(t_data *data)
{
	int	i;
	int	width1;
	int	width2;

	i = 0;
	if (!data->map)
		return (0);
	width1 = ft_strlen(data->map[0]);
	while (data->map[i])
	{
		if (data->map[i])
			width2 = ft_strlen(data->map[i]);
		if (width1 < width2)
			width1 = width2;
		i++;
	}
	return (width1);
}

int	size_lenght(t_data *data)
{
	int	i;

	i = 0;
	if (!data->map)
		return (0);
	while (data->map[i])
		i++;
	return (i);
}
