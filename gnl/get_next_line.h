/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 13:49:59 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:45:56 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_end(char *str);
char	*ft_resave(char *save);
int		get_next_line(int fd, char **line);
void	*ft_memset(void *b, int c, unsigned int len);

#endif
