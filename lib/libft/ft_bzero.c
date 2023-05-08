/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:51:45 by hece              #+#    #+#             */
/*   Updated: 2022/12/07 11:47:43 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t bytelength)
{
	ft_memset(ptr, 0, bytelength);
}

/*#include <unistd.h>

void	ft_putstr(char *str, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		write(1, &str[count], 1);
		count++;
	}
}

int	main(void)
{
	char	a[] = "hece\n";
	char	mete[] = "hece\n";
	ft_putstr(a, 5);
	ft_bzero(mete, 3);
	ft_putstr(mete, 5);
}*/
