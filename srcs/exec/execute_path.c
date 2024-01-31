/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:52:00 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 16:32:29 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_cmd_path(t_commands *cmds, int index)
{
	char	*cmd_comp;
	char	*cmd;
	int		i;

	i = 0;
	cmd = ft_strdup("/");
	cmd = ft_strsjoin(cmd, cmds->cmd[index].args[0]);
	if (cmds->paths)
	{
		while (cmds->paths[i])
		{
			cmd_comp = ft_strsjoin(cmds->paths[i], cmd);
			if (access(cmd_comp, F_OK | X_OK) == 0)
			{
				free_ptr(cmd);
				return (cmd_comp);
			}
			free_ptr(cmd_comp);
			i++;
		}
	}
	free_ptr(cmd);
	return (NULL);
}

int	execute_path(t_data *data, t_commands *cmds, int num_cmd)
{
	cmds->cmd[num_cmd].path = get_cmd_path(cmds, num_cmd);
	if (!cmds->cmd[num_cmd].path)
		return (CMD_NOT_FOUND);
	if (execve(cmds->cmd[num_cmd].path, cmds->cmd[num_cmd].args, data->env) == -1)
		error_msg("execve", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
