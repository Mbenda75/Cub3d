/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:43:36 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:43:41 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*s2;

	len = 0;
	while (s[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		l2;
	char	*temp;
	char	*str;
	char	*ptr;

	if (!s2)
		return (NULL);
	l2 = ft_strlen(s2);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + l2) + 1));
	if (!str)
		return (NULL);
	ptr = str;
	if (s1)
	{
		temp = s1;
		while (*s1)
			*str++ = *s1++;
		free(temp);
		temp = 0;
	}
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (ptr);
}

int	ft_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
