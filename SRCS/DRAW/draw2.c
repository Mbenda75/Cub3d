/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:14:00 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/13 20:23:52 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/draw.h"

void	draw_rgb(t_data *data, t_color *color, int y, int x)
{
	if (data->tx.endian == 1)
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = color->r;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = color->g;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = color->b;
	}
	else
	{
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ y * data->tx.line] = color->b;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 1 + y * data->tx.line] = color->g;
		data->tx.addr[(x * data->tx.bpp >> 3)
			+ 2 + y * data->tx.line] = color->r;
	}
}

void	draw_wall(t_data *data, t_img *tex, int y, int x)
{
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ (int)((y - data->ray.wall_start * 1.0) / data->ray.line_height
			* tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 1 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 1 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
	data->tx.addr[(x * data->tx.bpp >> 3)
		+ 2 + y * data->tx.line]
		= tex->addr[(int)(data->ray.wall_x * tex->width) * (tex->bpp >> 3)
		+ 2 + (int)((y - data->ray.wall_start * 1.0)
			/ data->ray.line_height * tex->height) *tex->line];
}

void	draw_tmp(t_data *data, int y, int x)
{
	if (data->ray.side == NO)
		draw_wall(data, &data->north, y, x);
	else if (data->ray.side == SO)
		draw_wall(data, &data->south, y, x);
	else if (data->ray.side == WE)
		draw_wall(data, &data->west, y, x);
	else if (data->ray.side == EA)
		draw_wall(data, &data->east, y, x);
}

void	set_stop(t_data *data, int *start, int *end)
{
	if (data->ray.wall_start < 0)
		*start = 0;
	else
		*start = data->ray.wall_start;
	if (data->ray.wall_end >= WIN_HEIGHT)
		*end = WIN_HEIGHT - 1;
	else
		*end = data->ray.wall_end;
}

void	put_in_display(t_data *data, int x)
{
	int	y;
	int	start;
	int	end;

	y = 0;
	set_stop(data, &start, &end);
	while (y < start)
	{
		draw_rgb(data, &data->ceiling, y, x);
		y++;
	}
	while (y < end)
	{
		draw_tmp(data, y, x);
		y++;
	}
	while (y < WIN_HEIGHT - 1)
	{
		draw_rgb(data, &data->floor, y, x);
		y++;
	}
}
