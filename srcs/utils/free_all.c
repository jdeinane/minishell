/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:44:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 12:48:57 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data == NULL)
		return ;
	if (data->env != NULL)
	{
		while (data->env[i] != NULL)
		{
			free(data->env[i]);
			i++;
		}
		free(data->env);
	}
	free(data->user_input);
	free(data->work_dir);
	free(data->old_work_dir);
	free(data);
}

void	free_commands(t_commands *cmds)
{
	int	i;

	i = 0;
	if (cmds == NULL)
		return ;
	while (i < cmds->num_cmds)
	{
		free(cmds->cmd[i].path);
		free(cmds->cmd[i].args);
		free(cmds->cmd[i].redirections);
		i++;
	}
	free(cmds->pid);
	free(cmds->operators);
	free(cmds->cmds);
	free(cmds->paths);
	free(cmds->pipe);
	free(cmds->io);
	free(cmds);
}
