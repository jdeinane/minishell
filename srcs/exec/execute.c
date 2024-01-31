/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:09:57 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 16:38:48 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute(t_data *data, t_commands *cmds, int num_cmd)
{
	int		status;

	status = 0;
	process_input(data->user_input, cmds);
	init_commands(data, cmds);
	parse_tokens(cmds->tokens, num_cmd, cmds);
	if (cmds->operators[0])
		create_pipes(cmds, num_cmd);
	if (is_redirection_cmd(cmds, num_cmd) && is_in_out_file(cmds->io, cmds, true) == false)
		exit_minishell(data, EXIT_FAILURE);
	redirect_io(cmds->io, num_cmd);
	close_fds(cmds, false);
	if (is_builtin(cmds->cmd[num_cmd].args[0]))
		status = execute_builtin(data, cmds, num_cmd);
	else
	{
		if (ft_strchr(cmds->cmd[num_cmd].args[0], '/') == NULL)
		{
			status = execute_path(data, cmds, num_cmd);
			if (status != CMD_NOT_FOUND)
				free_exit(data, cmds, EXIT_SUCCESS);
		}
		status = execute_local(data, cmds, num_cmd);
	}
	free_cmds(cmds);
	exit_minishell(data, status);
	return (status);
}
