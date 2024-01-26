/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:39:56 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/26 17:46:56 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_pipes(t_commands *cmds)
{
	int	i;

	i = 0;
	while (i < cmds->num_cmds)
	{
		if (cmds->pipe[i].fd)
		{
			close(cmds->pipe[i].fd[0]);
			close(cmds->pipe[i].fd[1]);
		}
		i++;
	}
}

void	close_pipes_fd(t_commands *cmds)
{
	int	i;

	i = 0;
	while (i < cmds->num_exec)
	{
		if (cmds->pipe[i].fd)
		{
			close(cmds->pipe[i].fd[0]);
			close(cmds->pipe[i].fd[1]);
		}
		i++;
	}
}
