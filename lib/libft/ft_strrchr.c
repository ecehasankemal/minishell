/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:38:32 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 15:38:52 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		iter;
	char	*ptr;

	iter = 0;
	ptr = 0;
	while (str[iter])
	{
		if (str[iter] == (unsigned char)c)
			ptr = ((char *)&str[iter]);
		iter++;
	}
	if (str[iter] == c)
			ptr = (char *)&str[iter];
	return (ptr);
}

/*#include <stdio.h>
int	main(void)
{
	char	*str = "www.toros.bilisim. com";
	char	c = '.';
	printf("%s | %c -> %s", str, c, ft_strrchr(str, c));
}*/
