/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:54:03 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/13 14:02:15 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/free.h"

void	free_data(t_data *data)
{
	if (data->fd)
		close (data->fd);
	if (data->map)
	{
		free_map(data);
		data->map = NULL;
	}
	if (data->map3)
	{
		free_map3(data);
		data->map3 = NULL;
	}
}

void	free_img(t_data *data)
{
	if (data->north.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->north.img);
		data->north.img = NULL;
	}
	if (data->south.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->south.img);
		data->south.img = NULL;
	}
	if (data->west.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->west.img);
		data->west.img = NULL;
	}
	if (data->east.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->east.img);
		data->east.img = NULL;
	}
	if (data->tx.img != NULL)
	{
		mlx_destroy_image(data->mlx, data->tx.img);
		data->tx.img = NULL;
	}
}
