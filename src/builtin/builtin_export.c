/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:14:19 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 00:27:16 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env.h"

static inline void	print_vars(void);
static inline bool	is_valid_argument(char *arg);

int
	builtin_export(int argc, char *argv[])
{
	int				status;
	register int	index;

	status = EXIT_SUCCESS;
	if (argc == 1)
		print_vars();
	index = 1;
	while (argc > 1 && argv[index])
	{
		if (is_valid_argument(argv[index]) == false)
		{
			print_error(SHELL_NAME, argv[index],
				NULL, "not a valid identifier");
			status = EXIT_FAILURE;
		}
		else if (ft_strchr(argv[index], '='))
			env_put_var(argv[index]);
		index++;
	}
	return (status);
}

static inline void
	print_vars(void)
{
	char			**env_copy;
	register int	l_var_name;
	register int	index;

	if (g_env == NULL || *g_env == NULL)
		return ;
	env_copy = (char **)malloc((split_count(g_env) + 1) * sizeof(char *));
	if (env_copy == NULL)
	{
		print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM));
		return ;
	}
	env_copy = ft_memcpy(env_copy, g_env,
		(split_count(g_env) + 1) * sizeof(char *));
	split_sort(env_copy);
	index = 0;
	while (env_copy[index])
	{
		l_var_name = ft_strchr(env_copy[index], '=') - env_copy[index];
		printf("%.*s", l_var_name + 1, env_copy[index]);
		printf("\"%s\"\n", env_get_value(env_copy[index]));
		index++;
	}
	free(env_copy);
}

static inline bool
	is_valid_argument(char *arg)
{
	register int	index;

	if (arg[0] == '\0' || arg[0] == '=')
		return (false);
	index = 0;
	while (arg[index] != '\0' && arg[index] != '='
		&& env_is_var_char(arg[index]))
		index++;
	if (arg[index] == '\0' || arg[index] == '=')
		return (true);
	else
		return (false);
}
