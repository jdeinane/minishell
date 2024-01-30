/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:23:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 20:26:54 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_new_cmd(t_commands *cmd, char *token)
{
	t_cmd	*new_cmd;

	if (cmd->cmd == NULL)
	{
		cmd->cmd = malloc(sizeof(t_cmd));
		if (cmd->cmd == NULL)
			return ;
	}
	else
	{
		cmd->cmd = ft_realloc(cmd->cmd, sizeof(t_cmd) * (cmd->num_cmds + 1));
		if (cmd->cmd == NULL)
			return ;
	}
	new_cmd = &cmd->cmd[cmd->num_cmds];
	new_cmd->path = ft_strdup(token);
	new_cmd->args = malloc(sizeof(char *) * MAX_ARGS);
	if (new_cmd->args == NULL)
		return ;
	new_cmd->args[0] = ft_strdup(token);
	new_cmd->redirections = NULL;
	cmd->num_cmds += 1;
}
