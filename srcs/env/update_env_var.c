/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:50:34 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 20:41:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_existing_env_var(char ***env, char *new_var, int index)
{
	free((*env)[index]);
	(*env)[index] = new_var;
}

void	add_new_env_var(char **env, char *new_var, int count)
{
	char	**new_env;
	int		i;

	i = 0;
	new_env = malloc(sizeof(char *) * (count + 2));
	while (i < count)
	{
		new_env[i] = (*env)[i];
		i++;
	}
	new_env[count] = new_var;
	new_env[count + 1] = NULL;
	free(*env);
	*env = new_env;
}

void	update_env_var(t_data *data, const char *key, const char *value)
{
	char	*new_var;
	int		index;
	int		count;

	new_var = create_env_var(key, value);
	index = find_env_index(data->env, key);
	count = 0;
	if (!new_var)
		return ;
	while (data->env[count])
		count++;
	if (index != -1)
		update_existing_env_var(&(data->env), new_var, index);
	else
		add_new_env_var(&(data->env), new_var, count);
}
