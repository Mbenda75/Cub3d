/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:34:13 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/12 15:31:45 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../parse.h"

void	change_space_to_3(t_data *data);
int		check_line_close(t_data *data, int line);
int		check_if_is_close(t_data *data);
int		nothing_in_line(char *str);
int		ft_check_name_map(char *s1);
int		check_file(char *name_map);
int		check_fd(char *name_map);
int		check_all(int ac, char **av, t_data *data);
int		check_letter(t_data *data);
int		check_duplicate_position(t_data *data);
void	init_pos_dir(t_data *data);
void    check_wall_map(char **str, int line);
void	check_main(int ac, char **av, t_data *data);

#endif