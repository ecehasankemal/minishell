/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 01:10:23 by hece              #+#    #+#             */
/*   Updated: 2023/05/09 01:12:09 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "global.h"

int		env_init(void);
char	*env_get_value(char *name);
char	*env_find_var(char *name);
bool	env_var_is_value(char *var_name, char *value);
bool	env_is_var_char(char c);

int		env_unset_var(char *name);
int		env_put_var(char *str);
int		env_set_env(char *name, char *value);

#endif
