/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:50:06 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 10:02:30 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	setup_redirections_and_pipes(t_cmd *cmd, t_commands *cmds, int cmd_index)
{
	handle_redirections(cmds, cmd_index);
	if (cmd_index > 0 && cmds->operators[cmd_index - 1] == PIPE)
		dup2(cmds->pipe[cmd_index - 1].fd[0], STDIN_FILENO);
	if (cmds->operators[cmd_index] == PIPE)
		dup2(cmds->pipe[cmd_index].fd[1], STDOUT_FILENO);
	close_pipes_fd(cmds);
}
