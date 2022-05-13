/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:18:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 14:12:13 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/option.h"

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
	exit_opt(data, "Error\n Already load\n");
}

void	get_opt_exit(int res, t_data *data, char *line, char **tmp)
{
	if (res == -1)
	{
		free(line);
		free_tab(tmp);
		exit_opt(data, "Error\n texture\n");
	}
}

int	if_opt(t_data *data, char **tmp, int res, char *line)
{
	if (!ft_strncmp(tmp[0], "NO", 3))
	{
		res = get_texture(data, tmp[1], &data->north);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "SO", 3))
	{	
		res = get_texture(data, tmp[1], &data->south);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "WE", 3))
	{
		res = get_texture(data, tmp[1], &data->west);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "EA", 3))
	{
		res = get_texture(data, tmp[1], &data->east);
		get_opt_exit(res, data, line, tmp);
	}
	else if (!ft_strncmp(tmp[0], "F", 2))
		res = take_rgb(&data->floor, tmp[1], data);
	else if (!ft_strncmp(tmp[0], "C", 2))
		res = take_rgb(&data->ceiling, tmp[1], data);
	return (res);
}

int	get_opt(t_data *data, char *line, int res)
{
	char	**tmp;

	tmp = NULL;
	tmp = ft_split(line, ' ');
	if (!tmp)
		exit_opt(data, "Error\n, Malloc failed");
	res = if_opt(data, tmp, res, line);
	if (res == 2)
		return_get_opt(line, tmp, data);
	free_tab(tmp);
	return (res);
}
