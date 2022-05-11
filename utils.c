/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:54:14 by benmoham          #+#    #+#             */
/*   Updated: 2022/05/11 18:38:54 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int	ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

char	*ft_strmalloc(const char *s)
{
	int			len;
	char		*s2;

	len = 0;
	while (s[len])
		len++;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	return (s2);
}

void	*ft_memset(void *b, int c, unsigned int len)
{
	char	*str;

	str = b;
	while (len)
	{
		*str = (unsigned char)c;
		str++;
		len--;
	}
	return (b);
}

long	ft_atol(char *str)
{
	int		neg;
	long	res;

	neg = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-')
		neg = -neg;
	if (*str == '+' || *str == '-')
		++str;
	else if (*str == '+')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		++str;
	}
	return (neg * res);
}
