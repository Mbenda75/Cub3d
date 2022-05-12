/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:17:35 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 16:09:34 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

void	check_main(int ac, char **av, t_data *data)
{
	if (ac != 2)
	{
		printf("Error \nnumber of argument\n");
		exit(1);
	}
	if (ft_check_name_map(av[1]) == 0)
		exit_opt(data, "Error \nbad name\n");
	if (!check_all(ac, av, data))
		exit_opt(data, "Error\n map\n");
}

int	check_all(int ac, char **av, t_data *data)
{
	if (ac != 2)
		return (0);
	else if (!get_map(data, av))
		exit_opt(data, "Error \n when get map\n");
	if (data->width < 3 || data->lenght < 3)
		exit_opt(data, "Error \n map to small\n");
	change_space_to_3(data);
	if (!check_if_is_close(data) || !first_lenght(data))
	{
		free_map3(data);
		free_map(data);
		exit_opt(data, "Error \n map not close\n");
		return (0);
	}
	return (1);
}
