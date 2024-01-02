/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:50:34 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/02 22:03:11 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_env_var(t_data *data, const char *key, const char *value)
{
	int		i;
	int		env_size;
	int		key_len;
	int		value_len;
	char	*env_var;

	i = 0;
	key_len = ft_strlen(key);
	value_len = ft_strlen(value);
	env_var = malloc(key_len + value_len + 2);
	if (!env_var)
		return ;
	ft_strcpy(env_var, key);
	env_var[key_len] = '=';
	ft_strcpy(env_var + key_len + 1, value);
	while (data->env && data->env[i])
	{
		if (ft_strncmp(data->env[i], key, key_len) == 0 && data->env[i][key_len] == ' ')
		{
			free(data->env[i]);
			data->env[i] = env_var;
			i++;
			return ;
		}
	}
}
