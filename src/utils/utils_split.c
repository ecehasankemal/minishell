/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:45:57 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 00:50:00 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

int
	split_count(char *split[])
{
	int	index;

	index = 0;
	while (split && split[index])
		index++;
	return (index);
}

int
	split_append_str(char ***split, char *new_str)
{
	char			**new_split;
	register int	index;

	new_split = (char **)malloc(sizeof(char *) * (split_count(*split) + 2));
	if (new_split == NULL)
		return (NULL);
	index = 0;
	while (*split && (*split)[index])
	{
		new_split[index] = (*split)[index];
		index++;
	}
	new_split[index] = new_str;
	new_split[index + 1] = NULL;
	free(*split);
	*split = new_split;
	return (0);
}
