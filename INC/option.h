/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 12:42:29 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 13:56:48 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTION_H
# define OPTION_H

# include "../INC/parse.h"

int		take_rgb(t_color *s_key, char *line, t_data *data);
int		get_texture(t_data *data, char *path, t_img *img);
void	return_get_opt(char *line, char **tmp, t_data *data);
int		check_status_tx(t_data *data);
void	get_opt_exit(int res, t_data *data,char *line, char **tmp);
int		if_opt(t_data *data, char **tmp, int res, char *line);
int count(char *line);
int		get_opt(t_data *data, char *line, int res);

#endif