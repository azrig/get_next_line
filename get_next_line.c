/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <azrig@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:27:01 by azrig             #+#    #+#             */
/*   Updated: 2025/02/05 03:07:36 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*check_stash(char **stash)
{
	char	*line;
	char	*temp;
	char	*nl;

	if (!*stash)
		return (NULL);
	nl = nl_pos(*stash);
	if (!nl)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
	}
	else
	{
		line = ft_substr(*stash, 0, nl - *stash + 1);
		temp = ft_strdup(nl + 1);
		free(*stash);
		*stash = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		nbyte;
	static char	*stash;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!nl_pos(stash))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte <= 0)
			break ;
		buffer[nbyte] = '\0';
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	free(buffer);
	buffer = NULL;
	return (check_stash(&stash));
}
