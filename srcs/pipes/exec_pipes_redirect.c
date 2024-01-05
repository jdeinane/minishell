/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:35:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 17:56:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	init_pipes_and_forks(t_commands *cmds)
{
	if (create_pipes(cmds) < 0)
		return (-1);
	return (fork());
}

void	execute_cmd(t_commands *cmds, int index)
{
	setup_pipe_redir(cmds, index);
	if (is_builtin(cmds->cmds[index]))
		exec_builtin(cmds->cmd[index]);
	else
		exec_external_command(cmds->cmds[index]);
}

int	exec_cmd_pipes_and_redirect(t_commands *cmds)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = init_pipes_and_forks(cmds);
	if (pid < 0)
		return (-1);
	while (i < cmds->num_cmds)
	{
		if (pid == 0)
			execute_cmd(cmds, i);
		wait(NULL);
		i++;
	}
	return (0);
}
