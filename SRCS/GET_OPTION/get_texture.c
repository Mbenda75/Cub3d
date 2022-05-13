/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 13:05:48 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 14:01:12 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/option.h"

int	count(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_status_tx(t_data *data)
{
	if (data->north.status == 1 && data->south.status == 1 && \
	data->west.status == 1 && data->east.status == 1)
		return (1);
	return (0);
}

int	if_not_tmp(char **tmp, int i)
{
	if (!tmp[i])
	{
		free_tab(tmp);
		return (-1);
	}
	return (0);
}

int	take_rgb(t_color *s_key, char *line, t_data *data)
{
	int		i;
	long	res[3];
	char	**tmp;

	i = -1;
	if (s_key->status == 1)
		return (2);
	tmp = ft_split(line, ',');
	if (!tmp)
		exit_opt(data, "Error\n Malloc failed\n");
	while (++i < 3)
	{
		if (if_not_tmp(tmp, i) == -1)
			return (-1);
		res[i] = ft_atol(tmp[i]);
		if (!res[i] || res[i] < 0 || res[i] > 255 || ft_digit(tmp[i]) == 0)
		{	
			free_tab(tmp);
			return (-1);
		}
	}
	add_rgb(res, s_key);
	free_tab(tmp);
	return (1);
}

int	get_texture(t_data *data, char *path, t_img *img)
{
	int	i;

	i = 0;
	(void)data;
	if (img->status == 1)
		return (2);
	while (path[i])
	{
		if (ft_isspace(path[i]))
		{
			path[i] = '\0';
			break ;
		}
		i++;
	}
	img->img = mlx_xpm_file_to_image(data->mlx, path, \
	&img->width, &img->height);
	if (!img->img)
		return (-1);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, \
	&img->line, &img->endian);
	if (!img->addr)
		return (-1);
	img->status = 1;
	return (1);
}
