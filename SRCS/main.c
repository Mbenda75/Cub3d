/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:24:53 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 14:14:27 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/parse.h"

int	check_init_get_map(t_data *data, char **av)
{
	init_data(data);
	init_win(data);
	init_img(data);
	data->fd = check_fd(av[1]);
	if (data->fd == -1)
		exit_opt(data, NULL);
	data->line = ft_strdup("");
	if (!data->line)
		return (0);
	return (1);
}

int	end_get_map(t_data *data)
{
	close(data->fd);
	data->map = ft_split(data->line, '\n');
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
	}
	if (!data->map)
		return (0);
	data->width = size_width(data);
	data->lenght = size_lenght(data);
	if (!check_letter(data) || \
	!check_duplicate_position(data) || \
	ft_stronly("1", data->map[data->lenght - 1]) == 0)
	{
		free_map(data);
		exit_opt(data, NULL);
		return (0);
	}
	return (1);
}

char	*check_tmp_in_get_map(char *tmp, t_data *data, int res)
{
	int	nb;

	nb = 0;
	if (data->status == 0 && (check_temp(tmp) == 1))
		free_tmp(tmp);
	else if (check_temp(tmp) == 0 || data->status == 1)
	{
		tmp = ft_strjoinfree(tmp, " \n", 1);
		nb = count(tmp);
		if (nb > 2)
		{
			free(tmp);
			exit_opt(data, "Error\n texture");
		}
		res = get_opt(data, tmp, 0);
		if (res != 1)
		{
			data->line = ft_strjoinfree(data->line, tmp, 1);
			data->status = 1;
		}
		free_tmp(tmp);
	}
	return (tmp);
}

int	get_map(t_data *data, char **av)
{
	int		res;
	char	*tmp;

	tmp = NULL;
	res = 0;
	data->status = 0;
	if (check_init_get_map(data, av) == 0)
		return (0);
	while ((tmp = get_next_line(data->fd)) && res != -1)
		tmp = check_tmp_in_get_map(tmp, data, res);
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	return (end_get_map(data));
}

int	main(int ac, char **av)
{
	t_data	data;

	check_arg(ac, av);
	data.mlx = NULL;
	data.mlx = mlx_init();
	data.map = NULL;
	data.map3 = NULL;
	check_main(ac, av, &data);
	init_pos_dir(&data);
	mlx_hook(data.win, 17, 1L << 17, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_raycast, &data);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	free_map(&data);
	return (1);
}
