/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:50:28 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:50:36 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	move_w(t_data *data, t_play *player)
{
	if (data->map[(int)(player->pos.x + player->dir.x * 0.4)]
		[(int)(player->pos.y)] == '0')
		player->pos.x += player->dir.x * 0.4;
	if (data->map[(int)(player->pos.x)][(int)(player->pos.y + player->dir.y
		* 0.4)] == '0')
		player->pos.y += player->dir.y * 0.4;
}

void	move_s(t_data *data, t_play *player)
{
	if (data->map[(int)(player->pos.x - player->dir.x * 0.4)]
	[(int)(player->pos.y)] == '0')
		player->pos.x -= player->dir.x * 0.4;
	if (data->map[(int)(player->pos.x)][(int)(player->pos.y - player->dir.y
		* 0.4)] == '0')
		player->pos.y -= player->dir.y * 0.4;
}

void	move_d(t_data *data, t_play *player)
{
	if (data->map[(int)(player->pos.x + player->plane.x
			* 0.4)][(int)(player->pos.y)] == '0')
		player->pos.x += player->plane.x * 0.4;
	if (data->map[(int)(player->pos.x)][(int)(player->pos.y + player->plane.y
		* 0.4)] == '0')
		player->pos.y += player->plane.y * 0.4;
}

void	move_a(t_data *data, t_play *player)
{
	if (data->map[(int)(player->pos.x - player->plane.x
			* 0.4)][(int)(player->pos.y)] == '0')
		player->pos.x += -(player->plane.x * 0.4);
	if (data->map[(int)(player->pos.x)][(int)(player->pos.y - player->plane.y *
	0.4)] == '0')
		player->pos.y += -(player->plane.y * 0.4);
}

int	key_hook(t_data *data)
{
	if (data->key_w == 1)
		move_w(data, &data->player);
	if (data->key_s == 1)
		move_s(data, &data->player);
	if (data->key_d == 1)
		move_d(data, &data->player);
	if (data->key_a == 1)
		move_a(data, &data->player);
	if (data->key_r == 1)
		rot_right(data);
	if (data->key_l == 1)
		rot_left(data);
	if (data->key_w == 0 && data->key_s == 0
		&& data->key_l == 0 && data->key_r == 0
		&& data->key_a == 0 && data->key_d == 0)
		return (0);
	return (1);
}
