/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:30:35 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/26 17:57:25 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_redirection_cmd(t_commands *cmds, int i)
{
	if (cmds->cmd[i].redirections[0])
		return (true);
	else
		return (false);
}

void	handle_redirections(t_commands *cmds, int j)
{
	int	i;
	int	status_code;

	i = 0;
	status_code = -1;
	while (cmds->cmd[j].redirections[i])
	{
		if (ft_strncmp(cmds->cmd[j].redirections[i], ">>", 2) == 0)
			status_code = rd_output_handler(cmds, cmds->cmd[j].redirections[i],
					false);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], "<<", 2) == 0)
			handle_heredoc(cmds, cmds->cmd[j].redirections[i]);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], "<", 1) == 0)
			status_code = handle_input(cmds, cmds->cmd[j].redirections[i]);
		else if (ft_strncmp(cmds->cmd[j].redirections[i], ">", 1) == 0)
			status_code = rd_output_handler(cmds, cmds->cmd[j].redirections[i],
					true);
		cmds->io->cmd_index = j;
		if (status_code != -1)
			break ;
		i++;
	}
}
