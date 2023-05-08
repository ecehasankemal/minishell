/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:06:33 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 17:06:35 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
	}
}

/*
#include <stdio.h>
#include <fcntl.h>
int main()
{
		int fd;
		fd = open("deneme2.txt",O_RDWR);
		ft_putstr_fd("hece",fd);
		printf("%d",fd);
}
*/
