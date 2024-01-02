/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:04:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/02 13:30:49 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->path, "echo") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "cd") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "pwd") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "export") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "unset") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "env") == 0)
		return (1);
	else if (ft_strcmp(cmd->path, "exit") == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_cmd *cmd, t_data *data)
{
	if (is_builtin(cmd))
	{
		if (ft_strcmp(cmd->path, "echo") == 0)
			return (builtin_echo(cmd->args));
		else if (ft_strcmp(cmd->path, "cd") == 0)
			return (builtin_cd(cmd->args, data));
		else if (ft_strcmp(cmd->path, "pwd") == 0)
			return (builtin_pwd());
		else if (ft_strcmp(cmd->path, "export") == 0)
			return (builtin_export(cmd->args, data));
		else if (ft_strcmp(cmd->path, "unset") == 0)
			return (builtin_unset(cmd->args, data));
		else if (ft_strcmp(cmd->path, "env") == 0)
			return (builtin_env(data));
		else if (ft_strcmp(cmd->path, "exit") == 0)
			return (builtin_exit(cmd->args, data));
	}
	return (-1);
}
