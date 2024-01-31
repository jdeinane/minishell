/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 00:09:57 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 09:30:20 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute(t_data *data)
{
	char		**tokens;
	int			num_tokens;
	t_commands	cmds;
	int			status;
	pid_t		pid;
	int			i;

	status = 0;
	i = 0;
	process_input(data->user_input, &cmds);
	init_commands(data, &cmds);
	parse_tokens(&cmds);
	while (i < cmds.num_cmds)
	{
		if (is_builtin(cmds.cmd[i]))
			status = execute_builtin(&cmds.cmd[i]);
		else
		{
			pid = fork();
			if (pid == 0)
			{
				setup_redirections_and_pipes(&cmds.cmd[i]);
				execve(cmds.cmd[i].path, cmds.cmd[i].args, data->env);
				exit(EXIT_FAILURE);
			}
			else if (pid > 0)
				waitpid(pid, &status, 0);
			else
			{
				perror("fork");
				return (EXIT_FAILURE);
			}
		}
		i++;
	}
	free_tokens(tokens, num_tokens);
	free_cmds(&cmds);
	return (WEXITSTATUS(status));
}
