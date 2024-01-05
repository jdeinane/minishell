/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:02:44 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 17:33:27 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	close_pipes(t_commands *cmds)
{
	int	i;

	i = 0;
	while (i < cmds->num_cmds - 1)
	{
		if (cmds->pipe[i].fd[0] != -1)
		{
			close(cmds->pipe[i].fd[0]);
			cmds->pipe[i].fd[0] = -1;
		}
		if (cmds->pipe[i].fd[1] != -1)
		{
			close(cmds->pipe[i].fd[1]);
			cmds->pipe[i].fd[1] = -1;
		}
	}
}
