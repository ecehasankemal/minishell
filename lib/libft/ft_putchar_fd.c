/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece  <hece@student.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:05:03 by hece              #+#    #+#             */
/*   Updated: 2022/09/18 17:05:08 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/* 
 #include <stdio.h>
 #include <fcntl.h>
 int main()
 {		
		int fd;
		fd = open("deneme.txt",O_RDWR);
		ft_putchar_fd('a',fd);
		printf("%d",fd);
 }  
*/
