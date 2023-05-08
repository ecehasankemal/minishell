/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:37:49 by hece              #+#    #+#             */
/*   Updated: 2023/05/06 13:40:50 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int
	builtin_echo(int argc __attribute((unsed)), char *argv[])
{
	register int	index;
	register bool	newline;

	newline = false;
	index = 1;
	while (argv[index] && !ft_strncmp(argv[index], "-n", 3))
		index++;
	if (index == 1)
		newline = true;
	while (argv[index])
	{
		ft_putstr_fd(argv[index], 1);
		if (argv[index + 1])
			ft_putchar_fd(' ', 1);
		index++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
	return (0);
}
