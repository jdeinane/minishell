/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:10:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_env(t_data *data, char **envp)
{
	int		i;
	int		env_size;

	i = 0;
	env_size = 0;
	while (envp[env_size])
		env_size++;
	data->env = malloc(sizeof(char *) * (env_size + 1));
	if (!data->env)
		return ;
	while (i < env_size)
	{
		data->env[i] = ft_strdup(envp[i]);
		if (!data->env[i])
			return ;
	}
	data->env[i] = NULL;
}
