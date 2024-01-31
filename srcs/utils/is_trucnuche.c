/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_trucnuche.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:36:43 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 16:18:04 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_space(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (c);
	return (0);
}

bool	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->path, "echo") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "unset") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd->path, "exit") == 0)
		return (true);
	return (false);
}

bool	is_in_out_file(t_redirect *io, t_commands *cmds, bool free)
{
	if (!io || (!io->in_file && !io->out_file))
		return (true);
	if (((io->in_file && io->fd_in == -1)
			|| (io->out_file && io->fd_out == -1)) && io->error == true)
	{
		if (free)
		{
			close_fds(cmds, false);
			free_cmds(cmds);
		}
		return (false);
	}
	return (true);
}
