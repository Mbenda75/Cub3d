/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:18:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 19:43:39 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
		if (!tmp[i])
		{
			free_tab(tmp);
			return (-1);
		}
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

void	return_get_opt(char *line, char **tmp, t_data *data)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
	free_tab(tmp);
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	exit_opt(data, "Error\n Already load");
}

int	check_status_tx(t_data *data)
{
	if (data->north.status == 1 && data->south.status == 1 && data->west.status == 1 && data->east.status == 1)
		return (1);
	return (0);
}

int	get_opt(t_data *data, char *line, int res)
{
	char	**tmp;

	tmp = NULL;
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit_opt(data, "Error\n, Malloc failed");
	if (!ft_strncmp(tmp[0], "NO", 3))
	{
		res = get_texture(data, tmp[1], &data->north);
		if (res == -1)
		{
			free(line);
			free_tab(tmp);
			exit_opt(data, "Error\n texture\n");
		}
		
	}
	else if (!ft_strncmp(tmp[0], "SO", 3))
	{	
		res = get_texture(data, tmp[1], &data->south);
		if (res == -1)
		{
			free(line);
			free_tab(tmp);
			exit_opt(data, "Error\n texture\n");
		}
	}
	else if (!ft_strncmp(tmp[0], "WE", 3))
	{
		res = get_texture(data, tmp[1], &data->west);
		if (res == -1)
		{
			free(line);
			free_tab(tmp);
			exit_opt(data, "Error\n texture\n");
		}
		
	}
	else if (!ft_strncmp(tmp[0], "EA", 3))
	{
		res = get_texture(data, tmp[1], &data->east);
		if (res == -1)
		{
			free(line);
			free_tab(tmp);
			exit_opt(data, "Error\n texture\n");
		}
	}
	else if (!ft_strncmp(tmp[0], "F", 2))
		res = take_rgb(&data->floor, tmp[1], data);
	else if (!ft_strncmp(tmp[0], "C", 2))
		res = take_rgb(&data->ceiling, tmp[1], data);
	if (res == 2)
		return_get_opt(line, tmp, data);
	free_tab(tmp);
	return (res);
}
