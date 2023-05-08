/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:36:10 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 00:40:33 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

static inline char	*minishell_gnl_free_line(char *line);

char
	*minishell_get_next_line(int fd)
{
	char			*line;
	char			buffer;
	register int	check;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	check = read(fd, &buffer, 1);
	if (check == -1 || check == 0)
		return (minishell_gnl_free_line(line));
	while (check > 0)
	{
		line = str_append_chr(line, buffer);
		if (line == NULL)
			return (NUll);
		if (buffer == '\n')
			return (line);
		check = read(fd, &buffer, 1);
	}
	if (check == -1)
		return (minishell_gnl_free_line(line));
	return (line);
}

static inline char
	*minishell_gnl_free_line(char *line)
{
	free(line);
	return (NULL);
}
