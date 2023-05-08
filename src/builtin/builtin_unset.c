/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:49:03 by hece              #+#    #+#             */
/*   Updated: 2023/05/06 16:53:27 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"

int
	builtin_unset(int argc __attribute((unsed)), char *argv[])
{
	register int	layer;
	register int	index;
	int				status;

	status = 0;
	layer = 1;
	while (argv[layer])
	{
		index = 0;
		while (argv[layer][index] && env_is_var_char(argv[layer][index]))
			index++;
		if (argv[layer][index] != '\0' || argv[layer][0] == '\0')
		{
			print_error(SHELL_NAME, "unset", argv[layer],
				"not a valid identifier");
			status = EXIT_FAILURE;
		}
		else
			env_unset_var(argv[layer]);
		layer++;
	}
	return (status);
}
