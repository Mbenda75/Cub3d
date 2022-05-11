/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:41:44 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:41:46 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "../parse.h"

void	free_map(t_data *data);
void	free_map3(t_data *data);
void	free_tab(char **map);
void	free_img(t_data *data);

#endif