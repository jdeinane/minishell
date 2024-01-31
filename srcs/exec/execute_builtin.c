/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:39:13 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 10:04:37 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute_builtin(t_data *data, t_commands *cmds, int i)
{
	if (ft_strcmp(cmds->cmd[i].path, "cd") == 0)
		return (builtin_cd(data, cmds, i));
	else if (ft_strcmp(cmds->cmd[i].path, "echo") == 0)
		return (builtin_echo(cmds->cmd[i].args));
	else if (ft_strcmp(cmds->cmd[i].path, "env") == 0)
		return (builtin_env(data, cmds, i));
	else if (ft_strcmp(cmds->cmd[i].path, "exit") == 0)
		return (builtin_exit(data, cmds, i));
	else if (ft_strcmp(cmds->cmd[i].path, "export") == 0)
		return (builtin_export(data, cmds, i));
	else if (ft_strcmp(cmds->cmd[i].path, "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(cmds->cmd[i].path, "unset") == 0)
		return (builtin_unset(data, cmds, i));
	else
		return (-1);
}
