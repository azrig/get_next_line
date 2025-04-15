/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:40:15 by azrig             #+#    #+#             */
/*   Updated: 2025/02/05 03:07:52 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nl_pos(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	j = 0;
	if (s2)
	{
		while (s2[j])
			str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(const char *str, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *str)
{
	char	*s;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	if (!*str)
		return (NULL);
	s = malloc(ft_strlen(str) + 1);
	if (!s)
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
