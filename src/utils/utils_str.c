/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:41:03 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 00:45:22 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

char
	*str_append_str(char *str, char *append)
{
	char	*tmp;

	tmp = str;
	str = ft_strjoin(str, append);
	free(tmp);
	return (str);
}

char
	*str_append_chr(char *str, char append)
{
	char			*new_str;
	register int	index;

	if (str == NULL)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (new_str != NULL)
	{
		index = 0;
		while (str[index])
		{
			new_str[index] = str[index];
			index++;
		}
		new_str[index] = append;
		new_str[index + 1] = '\0';
	}
	free(str);
	return (new_str);
}

char
	str_last_chr(char *str)
{
	if (str[0] != '\0')
		return (str[ft_strlen(str) - 1]);
	else
		return ('\0');
}
