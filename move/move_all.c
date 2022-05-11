/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:49:14 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:49:38 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	esc(t_data *data)
{
	if (data->map3)
		free_map3(data);
	if (data->map)
		free_map(data);
	exit_opt(data, "Bye bye \n");
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 65307)
		esc(data);
	else if (keycode == 119)
		data->key_w = 1;
	else if (keycode == 115)
		data->key_s = 1;
	else if (keycode == 100)
		data->key_d = 1;
	else if (keycode == 97)
		data->key_a = 1;
	else if (keycode == 65363)
		data->key_r = 1;
	else if (keycode == 65361)
		data->key_l = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 119)
		data->key_w = 0;
	else if (keycode == 115)
		data->key_s = 0;
	else if (keycode == 100)
		data->key_d = 0;
	else if (keycode == 97)
		data->key_a = 0;
	else if (keycode == 65363)
		data->key_r = 0;
	else if (keycode == 65361)
		data->key_l = 0;
	return (0);
}
