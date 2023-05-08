/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:14:08 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 16:14:24 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start > length)
		return (ft_strdup(""));
	if (length - start >= len)
		result = (char *)malloc((len + 1) * sizeof(char));
	else
		result = (char *)malloc((length - start + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)&s[start], (len + 1));
	return (result);
}

/*#include <stdio.h>
int	main(void)
{
	char	str[] = "kemal hece";
	char	*ret = ft_substr(str, 3, 9);
	printf("%s -> %s", str, ret);
}*/
