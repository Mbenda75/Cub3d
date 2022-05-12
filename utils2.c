/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:24:48 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 14:00:39 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	exit_opt(t_data *data, char *msg)
{
	if (msg == NULL)
		(void)msg;
	else
		printf("Error\n %s\n", msg);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
		{
			free_img(data);
			mlx_destroy_window(data->mlx, data->win);
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

void	add_rgb(long *res, t_color *s_key)
{
	s_key->r = (int)res[0];
	s_key->g = (int)res[1];
	s_key->b = (int)res[2];
	s_key->status = 1;
}
