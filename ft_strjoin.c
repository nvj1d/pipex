/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 02:02:29 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/13 18:07:11 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	s;
	size_t	i;

	j = 0;
	if (ft_strlen(dest) >= size)
	{
		return (size + ft_strlen(src));
	}
	else
	{
		j = ft_strlen(dest);
		i = ft_strlen(dest);
		s = 0;
		while (src[s] && j < size - 1)
		{
			dest[j] = src[s];
			s++;
			j++;
		}
		dest[j] = '\0';
		return (i + ft_strlen(src));
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;
	int		a;
	int		b;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	ptr = malloc(a + b + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, (char *)s1, a + 1);
	ft_strlcat(ptr, (char *)s2, a + b + 1);
	return (ptr);
}
