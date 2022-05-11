/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:25:28 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/11 16:39:27 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	init_display(t_data *data)
{
	data->tx.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->tx.img)
		exit_opt(data, "Init display\n");
	data->tx.addr = mlx_get_data_addr(data->tx.img, &data->tx.bpp,
			&data->tx.line, &data->tx.endian);
	if (!data->tx.addr)
		exit_opt(data, "Init display\n");
}
