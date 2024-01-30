/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_current_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:09:25 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 23:20:12 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	validate_command(t_cmd *cmd)
{
	if (cmd->path == NULL || ft_strlen(cmd->path) == 0)
	{
		printf("Command path is not set.\n");
		return (false);
	}
	if (cmd->args == NULL || cmd->args[0] == NULL)
	{
		printf("No arguments provided for command '%s'.\n", cmd->path);
		return (false);
	}
	return (true);
}

void	finalize_current_cmd(t_commands *cmd)
{	
	int	last_cmd_index;

	last_cmd_index = cmd->num_cmds - 1;
	if (cmd->num_cmds > 0)
	{
		if (cmd->cmd[last_cmd_index].redirections)
			handle_redirections(cmd, last_cmd_index);
		if (!validate_command(&cmd->cmd[last_cmd_index]))
		{
			cmd->exit_value = -1;
			error_msg("minishell: ", NULL, ": command not found", EXIT_FAILURE);
		}
	}
	reset_parsing_state(cmd);
}
