/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:48:51 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 13:52:16 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALL_H
# define INIT_ALL_H
# include "../INC/parse.h"

void	init_win(t_data *data);
void	init_data(t_data *data);
void	init_img(t_data *data);
void	init_rgb(t_data *data);
void	set_plane(t_data *data, double dx, double dy);
void	set_dir(t_data *data, double x, double y);
void	west_east(t_data *data, char dir);
void	init_player(t_data *data, int h, int w, char dir);

#endif