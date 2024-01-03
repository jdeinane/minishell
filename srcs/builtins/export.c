/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:59:23 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 17:54:29 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_export(char **av, char **env)
{
	int		i;
	char	*var;
	char	*value;

	i = 0;
	if (av[1] == NULL)
	{
		while (env[i] != NULL)
		{
			printf("declare -x %s\n", env[i]);
			i++;
		}
	}
	else
	{
		var = av[1];
		value = ft_strchr(var, '=');
		if (value)
		{
			*value = '\0';
			value++;
			set_env_var(env, var, value);
		}
		else
			set_env_var(env, var, "");
	}
	return (0);
}
