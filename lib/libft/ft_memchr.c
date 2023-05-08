/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:46:04 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 15:46:20 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

// ft_memchr("sample", 'a', 6); == ample

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*string;
	size_t	iter;

	iter = 0;
	string = (char *)str;
	while (iter < n)
	{
		if ((unsigned char)string[iter] == (unsigned char)c)
			return ((void *)&string[iter]);
		iter++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*p = "sample";
	char	b = 'a';
	printf("org : %s, mine : %s", memchr(p,b,6), ft_memchr(p,b,6));
}*/
