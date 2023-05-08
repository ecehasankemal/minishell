/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:19:51 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 15:20:08 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strchr("sample", 'a'); = ample

char	*ft_strchr(const char *str, int c)
{
	unsigned int	iter;

	iter = 0;
	while (str[iter])
	{
		if (str[iter] == (char)c)
			return ((char *)&str[iter]);
		iter++;
	}
	if ((char)c == str[iter])
		return ((char *)&str[iter]);
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	char	*str = "sample write";
	char	c = 'z';
	printf("%s | %c -> %s", str, c, ft_strchr(str, c));
}*/
