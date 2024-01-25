/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:01:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/26 00:05:35 by jubaldo          ###   ########.fr       */
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
