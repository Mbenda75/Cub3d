/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegadri <adegadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 21:17:34 by adegadri          #+#    #+#             */
/*   Updated: 2022/05/11 16:53:54 by adegadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_charset(char const s, char c)
{
	return (s == c);
}

static int	count_word(char const *str, char c)
{
	int	i;
	int	state;
	int	count;

	i = 0;
	state = 1;
	count = 0;
	while (str[i])
	{
		if (!is_charset(str[i], c) && state == 1)
		{
			count++;
			state = 0;
		}
		else
			if (is_charset(str[i], c) && state == 0)
				state = 1;
		i++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(str[i], c))
		i++;
	return (i);
}

static void	ft_do_split(char **tab, int countword, char const *s, char c)
{
	int	i;
	int	j;
	int	wl;

	i = 0;
	while (i < countword)
	{
		j = 0;
		while (*s && is_charset(*s, c))
			s++;
		wl = word_len(s, c);
		tab[i] = (char *)malloc(sizeof(char) * (wl + 1));
		if (!tab[i])
		{
			while (i >= 0)
				free (tab[i--]);
			tab = NULL;
			return ;
		}
		while (*s && !is_charset(*s, c))
			tab[i][j++] = *s++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		countword;
	char	**tab;

	if (!s)
		return (0);
	countword = count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (countword + 1));
	if (!tab)
		return (NULL);
	ft_do_split(tab, countword, s, c);
	return (tab);
}
