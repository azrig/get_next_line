/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:20:57 by azrig             #+#    #+#             */
/*   Updated: 2025/02/01 22:23:11 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*nl_pos(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(const char *str, size_t start, size_t len);
char	*ft_strdup(const char *str);

#endif