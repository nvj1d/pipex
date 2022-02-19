/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnajid <mnajid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 02:02:44 by mnajid            #+#    #+#             */
/*   Updated: 2022/02/13 18:06:33 by mnajid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

static char	*ft_startinvalid(void)
{
	char			*str;

	str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_startinvalid());
	if (len >= ft_strlen(s))
			len = ft_strlen(s);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
