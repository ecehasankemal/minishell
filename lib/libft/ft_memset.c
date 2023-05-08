/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:24:25 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 11:24:42 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t bytelength)
{
	char	*str;
	size_t	iter;

	iter = 0;
	str = (char *)ptr;
	while (iter < bytelength)
	{
			str[iter] = value;
			iter++;
	}
	return (ptr);
}

/*#include <unistd.h>

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
}

int	main(void)
{
	char	a[] = "hece\n";
	char	mete[] = "hece";
	ft_putstr(a);
	ft_memset(mete, 'b', 3);
	ft_putstr(mete);
}*/
