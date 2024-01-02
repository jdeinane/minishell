/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:10:57 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 00:23:29 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env_var(char **env, char *var, char *value)
{
	size_t	len;
	int		index;
	int		i;
	int		count;
	char	*new_var;
	char	**new_env;

	len = ft_strlen(var) + ft_strlen(value) + 2;
	index = -1;
	i = 0;
	count = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0 && env[i][ft_strlen(var)] == '=')
		{
			index = i;
			break;
		}
	}
	new_var = malloc(len);
	if (!new_var)
		return;
	ft_strcpy(new_var, var);
	ft_strcat(new_var, "=");
	ft_strcat(new_var, value);
	if (index == -1)
	{
		free(env[index]);
		env[index] = new_var;
	}
	else
	{
		while (env[count] != NULL)
			count++;
	}
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
	{
		free(new_var);
		return;
	}
	while (i < count)
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[count] = new_var;
	new_env[count + 1] = NULL;
	free(env);
	env = new_env;
}
