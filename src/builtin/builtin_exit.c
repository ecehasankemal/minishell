/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:05:09 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 00:13:37 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "exec.h"

static inline bool	num_is_numeric(char *str);

int
	builtin_exit(int argc, char *argv[], bool subshell, t_list *l_free)
{
	int	exit_num;

	if (!subshell && isatty(STDERR_FILENO))
		ft_putstr_fd("exit\n", STDERR_FILENO);
	exit_num = exec_exit_status_get();
	if (argc >= 2 && num_is_numeric(argv[1]) == false)
		exit_num = 255;
	else if (argc == 2)
		exit_num = ft_atoi(argv[1]);
	else if (argc > 2)
	{
		print_error(SHELL_NAME, "exit", NULL, "too many arguments");
		return (EXIT_FAILURE);
	}
	exec_free_all(argv, l_free);
	exit(exit_num);
}

static inline bool
	num_is_numeric(char *str)
{
	register int	index;

	index = 0;
	if (str[0] == '\0')
	{
		print_error(SHELL_NAME, "exit", str, "numeric argument required");
		return (false);
	}
	else if ((str[0] == '-' || str[0] == '+') && str[1] != '\0')
		index++;
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
		{
			print_error(SHELL_NAME, "exit", str, "numeric argument required");
			return (false);
		}
		index++;
	}
	return (true);
}
