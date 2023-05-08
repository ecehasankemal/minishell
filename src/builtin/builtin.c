/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:20:07 by hece              #+#    #+#             */
/*   Updated: 2023/05/06 13:15:04 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static inline const struct s_builtins	g_builtins[] = {
{"echo", builtin_echo},
{"cd", builtin_cd},
{"pwd", builtin_pwd},
{"env", builtin_env},
{"export", builtin_export},
{"unset", builtin_unset},
{NULL, NULL},
};

int
	builtin_check(char *argv[])
{
	register int	c_name;
	int				index;

	index = 0;
	if (argv[0] && !ft_strncmp(argv[0], "exit", 5))
		return (INT_MAX);
	while (g_builtins[index].name != NULL && argv)
	{
		c_name = ft_strlen(g_builtins[index].name);
		if (argv[0]
			&& !ft_strncmp(argv[0], g_builtins[index].name, c_name + 1))
			return (index + 1);
		index++;
	}
	return (0);
}

int
	builtin_exec(char *argv[], bool subshell, t_list *l_free)
{
	register int	i_builtin;

	i_builtin = builtin_check(argv);
	if (i_builtin == 0)
		return (ERROR);
	errno = 0;
	if (i_builtin == INT_MAX)
		return (builtin_exit(split_count(argv), argv, subshell, l_free));
	return (g_builtins[i_builtin - 1].func(split_count(argv), argv));
}
