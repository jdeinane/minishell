/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:59:27 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 16:45:02 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	create_pipes(t_commands *cmds)
{
	int	i;
	int	pipe_fd[2];

	i = 0;
	while (i < cmds->num_cmds - 1)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return (-1);
		}
		i++;
	}
	cmds->pipe[i].fd[0] = pipe_fd[0];
	cmds->pipe[i].fd[1] = pipe_fd[1];
	return (0);
}
