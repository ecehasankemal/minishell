/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:00:51 by hece              #+#    #+#             */
/*   Updated: 2022/12/05 13:40:44 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*str;
	char	*str2;
	size_t	iter;

	iter = 0;
	str = (char *)dest;
	str2 = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (str2 < str)
		while (++iter <= len)
			str[len - iter] = str2[len - iter];
	else
		return (ft_memcpy(dest, src, len));
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*a = malloc(sizeof(char) * 5);
	char	*b = malloc(sizeof(char) * 5);
	char	*src = "ahmet";
	printf("org : %s, ", (char *)memmove(a, src, 4));
	printf("ft_ : %s", (char *)ft_memmove(b ,src , 4));
}*/
