/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:43:26 by hece              #+#    #+#             */
/*   Updated: 2023/05/06 16:45:57 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int
	builtin_env(int argc __attribute((unused)),
	char *argv[] __attribute((unused)))
{
	register int	index;

	if (g_env == NULL)
	{
		print_error(SHELL_NAME, "env", NULL, "environ not set");
		return (EXIT_FAILURE);
	}
	index = 0;
	while (g_env[index])
	{
		ft_putendl_fd(g_env[index], STDOUT_FILENO);
		index++;
	}
	return (0);
}
