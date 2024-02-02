/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:18:47 by brjoves           #+#    #+#             */
/*   Updated: 2024/02/02 15:18:49 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_env(t_data *data, t_commands *cmds, int num_cmd)
{
	int	i;

	i = 0;
	if (cmds->cmd[num_cmd].args[1] != NULL)
		return (error_msg("env", NULL, "too many arguments", STDERR));
	if (!data->env)
		return (EXIT_FAILURE);
	while (data->env[i] != NULL)
	{
		if (ft_strchr(data->env[i], '='))
			ft_putendl_fd(data->env[i], STDOUT);
		i++;
	}
	return (EXIT_SUCCESS);
}
