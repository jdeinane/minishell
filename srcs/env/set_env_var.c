/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:10:57 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 20:52:07 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env_index(char **env, const char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '=')
		{
			return (i);
			i++;
		}
	}
	return (-1);
}

char	*create_env_var(const char *var, const char *value)
{
	size_t	len;
	char	*new_var;

	len = ft_strlen(var) + ft_strlen(value) + 2;
	new_var = malloc(len);
	if (!new_var)
		return (NULL);
	ft_strcpy(new_var, var);
	ft_strcat(new_var, "=");
	ft_strcat(new_var, value);
	return (new_var);
}

void	update_env(char ***env, char *new_var, int index)
{
	int		count;
	int		i;
	char	**new_env;

	i = 0;
	if (index != -1)
	{
		free((*env)[index]);
		(*env)[index] = new_var;
	}
	else
	{
		count = 0;
		while ((*env)[count])
			count++;
		new_env = malloc(sizeof(char *) * (count + 2));
		if (!new_env)
			return ;
		while (i++ < count)
			new_env[i] = (*env)[i];
		new_env[count] = new_var;
		new_env[count + 1] = NULL;
		free(*env);
		*env = new_env;
	}
}

void	set_env_var(char ***env, char *var, char *value)
{
	int		index;
	char	*new_var;

	index = find_env_index(*env, var);
	new_var = create_env_var(var, value);
	if (!new_var)
		return ;
	update_env(env, new_var, index);
}
