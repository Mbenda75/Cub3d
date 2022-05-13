/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:24:48 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 13:50:22 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INC/parse.h"

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
		printf("%s\n", msg);
	if (data->mlx != NULL)
	{
		if (data->win != NULL)
		{
			free_img(data);
			mlx_destroy_window(data->mlx, data->win);
			data->win = NULL;
		}
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->line)
	{
		free(data->line);
		data->line = NULL;
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

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		e;

	e = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(*str) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (e < i)
	{
		str[e] = s[e];
		e++;
	}
	str[e] = '\0';
	return (str);
}
