/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:17:35 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 19:05:58 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	check_main(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		printf("Error \nnumber of argument\n");
		exit_opt(data, NULL);
	}
	if (ft_check_name_map(av[1]) == 0)
	{
		printf("Error \nbad name\n");
		exit_opt(data, NULL);
	}
	if (!check_all(ac, av, data))
		exit_opt(data, "Error\n map\n");
}

int	check_all(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (0);
	else if (!get_map(data, av))
	{
		printf("%s\n", "Error \n when get map\n");
		return (0);
	}
	if (data->width < 3 || data->lenght < 3)
	{
		printf("%s\n", "Error \n map to small\n");
		return (0);
	}
	change_space_to_3(data);
	if (!check_if_is_close(data))
	{
		free_map3(data);
		free_map(data);
		return (0);
	}
	return (1);
}
