/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_parsing_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:19:47 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 20:21:31 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	reset_parsing_state(t_commands *cmd)
{
	t_cmd	*current_cmd;

	if (cmd->num_cmds > 0)
	{
		current_cmd = &cmd->cmd[cmd->num_cmds - 1];
		if (current_cmd->args)
		{
			free(current_cmd->args);
			current_cmd->args = NULL;
		}
		if (current_cmd->redirections)
		{
			free(current_cmd->redirections);
			current_cmd->redirections = NULL;
		}
	}
}
