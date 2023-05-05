/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:35:46 by hece              #+#    #+#             */
/*   Updated: 2023/05/04 16:56:14 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int
	env_init(void)
{
	extern char		**environ;
	register int	index;

	index = split_count(environ);
	if (index == 0)
		return (0);
	g_env = (char **)malloc((index + 1) * sizeof(char *));
	if (g_env == NULL)
		return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
	index = 0;
	while (environ[index])
	{
		g_env[index] = ft_strdup(environ[index]);
		if (g_env[index] == NULL)
		{
			ft_free_split(&g_env);
			return (print_error(SHELL_NAME, NULL, NULL, strerror(ENOMEM)));
		}
		index++;
	}
	g_env[index] = NULL;
	return (0);
}

char
	*env_get_value(char *name)
{
	char	*env_var;

	env_var = env_find_var(name);
	if (env_var)
		return (ft_strchr(env_var, '=') + 1);
	else
		return (NULL);
}

char
	*env_find_var(char *name)
{
	register int	l_name;
	register int	index;

	if (name == NULL || g_env == NULL)
		return (NULL);
	if (ft_strchr(name, '='))
		l_name = ft_strchr(name, '=') - name;
	else
		l_name = ft_strlen(name);
	index = 0;
	while (g_env[index])
	{
		if (!ft_strncmp(name, g_env[index], l_name)
			&& g_env[index][l_name] == '=')
			return (g_env[index]);
		index++;
	}
	return (NULL);
}

bool
	env_var_is_value(char *var_name, char *value)
{
	char	*env_value;

	env_value = env_get_value(var_name);
	if (env_value)
		if (ft_strncmp(env_value, value, ft_strlen(value) + 1) == 0)
			return (true);
	return (false);
}

bool
	env_is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}
