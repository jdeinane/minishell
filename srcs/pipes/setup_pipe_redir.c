/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:57:20 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 17:58:55 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	setup_pipe_redirection(t_commands *cmds)
{
	int	i;

	i = 0;
	while (i < cmds->num_cmds)
	{
		if (i > 0)
		{
			dup2(cmds->pipe[i - 1].fd[0], STDIN_FILENO);
			close(cmds->pipe[i - 1].fd[0]);
		}
		if (i < cmds->num_cmds - 1)
		{
			dup2(cmds->pipe[i].fd[1], STDOUT_FILENO);
			close(cmds->pipe[i].fd[1]);
		}
	}
}
