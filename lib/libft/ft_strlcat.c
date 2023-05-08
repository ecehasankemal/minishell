/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:10:53 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 15:11:57 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dindex;
	size_t	sindex;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	dindex = ft_strlen(dest);
	sindex = 0;
	while (src[sindex] != '\0' && dindex + 1 < size)
	{
		dest[dindex] = src[sindex];
		dindex++;
		sindex++;
	}
	dest[dindex] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[sindex]));
}

/*#include <stdio.h>
int	main()
{
	char a[] = "hece";
	char b[] = "hacason";
	printf("return %zu -> %s", ft_strlcat(a, b, 8), a);
}*/
