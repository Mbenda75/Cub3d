/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:54:03 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/11 19:55:38 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

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
		mlx_destroy_image(data->mlx, data->north.img);
	if (data->south.img != NULL)
		mlx_destroy_image(data->mlx, data->south.img);
	if (data->west.img != NULL)
		mlx_destroy_image(data->mlx, data->west.img);
	if (data->east.img != NULL)
		mlx_destroy_image(data->mlx, data->east.img);
	if (data->tx.img != NULL)
		mlx_destroy_image(data->mlx, data->tx.img);
}
