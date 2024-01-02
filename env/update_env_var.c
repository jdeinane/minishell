/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:50:34 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/02 23:42:56 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_var(t_data *data, const char *key, const char *value)
{
	int		key_len;
	int		value_len;
	int		count;
	int 	i;
	char	**new_env;
	char	*env_var;

	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	count = 0;
	i = 0;
	env_var = malloc(key_len + value_len + 2);
	if (!env_var)
		return;
	ft_strcpy(env_var, key);
	env_var[key_len] = '=';
	ft_strcpy(env_var + key_len + 1, value);
	while (data->env && data->env[count])
		count++;
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
	{
		free(env_var);
		return;
	}
	while (i < count)
	{
		new_env[i] = data->env[i];
		i++;
	}
	new_env[count] = env_var;
	new_env[count + 1] = NULL;
	free(data->env);
	data->env = new_env;
}
