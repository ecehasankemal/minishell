/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:50:30 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 15:50:48 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			iter;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	iter = 0;
	if (n == 0)
		return (0);
	while ((str1[iter] == str2[iter]) && iter < n - 1)
		iter++;
	return (str1[iter] - str2[iter]);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*p1 = "sample";
	char	*p2 = "semple";
	int	d1[] = {4, 3, 2, 1};
	int	d2[] = {4, 3, 3, 1};
	printf("org : %d, mine : %d", memcmp(p1,p2,6), ft_memcmp(p1,p2,6));
	printf("org : %d, mine : %d", memcmp(d1,d2,16), ft_memcmp(d1,d2,16));
}*/
