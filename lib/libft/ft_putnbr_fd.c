/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:10:11 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 17:10:15 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = nb * -1;
		ft_putnbr_fd(nb, fd);
	}
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}

/*
#include <stdio.h>
#include <fcntl.h>

int main()
{
   	int n = 2147483647;
   	int n1 = -2147483647;
	int fd;
	fd = open("deneme3.txt",O_RDWR);
	printf("%d",fd);
  	ft_putnbr_fd(n,fd);
	ft_putnbr_fd(n1,fd);
}
*/
