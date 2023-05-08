/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:12:28 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 01:16:02 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include "global.h"

struct s_builtins
{
	char	*name;
	int		(*func)(int argc, char *argv[]);
};

int	builtin_check(char *argv[]);
int	builtin_exec(char *argv[], bool subshell, t_list *l_free);

int	builtin_cd(int argc, char *argv[]);

int	builtin_echo(int argc, char *argv[]);

int	builtin_env(int argc, char *argv[]);

int	builtin_exit(int argc, char *argv[], bool subshell, t_list *l_free);

int	builtin_export(int argc, char *argv[]);
int	builtin_pwd(int argc, char *argv[]);

int	builtin_unset(int argc, char *argv[]);

#endif
