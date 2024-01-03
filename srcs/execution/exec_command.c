/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:53:37 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 19:28:10 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_command(t_cmd *cmd, t_data *data)
{
	int	status;

	if (is_builtin(cmd))
		status = exec_builtin(cmd, data);
	else
		status = exec_external_command(cmd, data);
	if (status == -1)
	{
		printf("minishell: %s: command not found\n", cmd->path);
	}
}

int	exec_external_command(t_cmd *cmd, t_data *data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd->path, cmd->args, data->env) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXIT(status))
			return (WEXITSTATUS(status));
		else
			return (-1);
	}
}
