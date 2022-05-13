/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:37:55 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 13:52:16 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "../INC/parse.h"

void	init_display(t_data *data);
int		draw(t_data *data);
void	put_in_display(t_data *data, int x);
#endif
