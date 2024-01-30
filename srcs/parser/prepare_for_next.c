/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_for_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:55:39 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 23:15:03 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	prepare_for_next_cmd(t_commands *cmd)
{
	t_cmd	*new_cmd;

	cmd->num_cmds += 1;
	cmd->cmd = ft_realloc(cmd->cmd, sizeof(t_cmd) * cmd->num_cmds);
	if (cmd->cmd == NULL)
		return ;
	new_cmd = &cmd->cmd[cmd->num_cmds - 1];
	ft_memset(new_cmd, 0, sizeof(t_cmd));
	new_cmd->redirections = malloc(sizeof(t_redirect));
	if (new_cmd->redirections == NULL)
		return ;
	ft_memset(new_cmd->redirections, 0, sizeof(t_redirect));
	new_cmd->args = malloc(sizeof(char *));
	if (new_cmd->args == NULL)
		return ;
	new_cmd->args[0] = NULL;
}
