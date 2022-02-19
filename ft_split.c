/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 02:02:16 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/13 18:04:34 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_calc_words(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		i++;
	}
	return (j);
}

static char	**ft_free(char ***tab, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		free((*tab)[k]);
		k++;
	}
	free(*tab);
	return (NULL);
}

static char	**ft_alloc(char **tab, const char *s, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < n && s[j])
	{
		k = 0;
		while (s[j] && s[j] != c)
		{
			j++;
			k++;
		}
		if (k != 0)
		{
			tab[i] = (char *)malloc(sizeof(char) * (k + 1));
			if (!tab[i])
				return (ft_free(&tab, i));
			i++;
		}
		j++;
	}
	tab[n] = 0;
	return (tab);
}

static void	ft_fill(char **tab, const char *s, char c, int n)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < n && s[j])
	{
		k = 0;
		if (s[j] != c)
		{
			while (s[j] && s[j] != c)
			{
				tab[i][k] = s[j];
				j++;
				k++;
			}
			tab[i][k] = '\0';
			i++;
		}
		else
			j++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**t;

	if (s == NULL)
		return (NULL);
	n = ft_calc_words(s, c);
	t = (char **)malloc(sizeof(char *) * (n + 1));
	if (!t)
		return (NULL);
	t = ft_alloc(t, s, c, n);
	ft_fill(t, s, c, n);
	return (t);
}
