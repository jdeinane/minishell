/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg_to_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:29:36 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 20:32:21 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_arg_to_cmd(t_commands *cmd, char *token)
{
	int		last_cmd_index;
	t_cmd	*current_cmd;
	int		arg_count;

	last_cmd_index = cmd->num_cmds - 1;
	current_cmd = &cmd->cmd[last_cmd_index];
	arg_count = 0;
	while (current_cmd->args[arg_count] != NULL)
		arg_count++;
	current_cmd->args = ft_realloc(current_cmd->args, sizeof(char *) * (arg_count + 2));
	if (current_cmd->args == NULL)
		return ;
	current_cmd->args[arg_count] = ft_strdup(token);
	current_cmd->args[arg_count + 1] = NULL;
}
