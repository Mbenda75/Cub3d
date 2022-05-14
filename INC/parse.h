/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:03:40 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/13 17:38:17 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <math.h>
# include <string.h>

# include "../mlx/mlx.h"

# define NO 0
# define SO 1
# define WE 2
# define EA 3

# define ESC	65307

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1000

# define WALL1 "./xpm/sand_floor.xpm"
# define WALL2 "./xpm/sand.xpm"
# define WALL3 "./xpm/stone_wall.xpm"
# define WALL4 "./xpm/stone.xpm"

# include "../INC/struct.h"
# include "../INC/get_next_line.h"
# include "../INC/check.h"
# include "../INC/init_all.h"
# include "../INC/option.h"
# include "../INC/move.h"
# include "../INC/draw.h"
# include "../INC/free.h"

char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_isspace(char c);
char	*ft_strmalloc(const char *s);
void	exit_opt(t_data *data, char *msg);
int		ft_strlen(char *str);
int		size_width(t_data *data);
int		ft_digit(char *str);
int		ft_isdigit(int c);
int		size_lenght(t_data *data);
char	*ft_str3dup(char *s, t_data *data);
void	*ft_memset(void *b, int c, unsigned int len);
int		get_map(t_data *data, char **av);
char	*ft_strdup(char *src);
long	ft_atol(char *str);
void	add_rgb(long *res, t_color *s_key);
int		loop_raycast(t_data *data);
int		mouse_hook(t_data *data);
char	*ft_strjoinfree(char *s1, char *s2, int to_free);
int		check_temp(char *s);
int		ft_stronly(const char *s, const char *s2);
int		check_status_tx(t_data *data);
char	*ft_strcpy(char *dest, char *src);
int		count(char *line);

#endif