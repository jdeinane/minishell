/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:40:47 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 20:53:32 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void handle_redirection(t_commands *cmd, char *token, char *next_token)
{
    int 		last_cmd_index;
    t_redirect	*redirect;

	last_cmd_index = cmd->num_cmds - 1;
	redirect = &cmd->cmd[last_cmd_index].redirections;
	if (ft_strcmp(token, ">") == 0)
	{
		redirect->out_file = ft_strdup(next_token);
		redirect->fd_out = open(redirect->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (ft_strcmp(token, ">>") == 0)
	{
		redirect->append_file = ft_strdup(next_token);
		redirect->fd_out = open(redirect->append_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (ft_strcmp(token, "<") == 0)
	{
		redirect->in_file = ft_strdup(next_token);
		redirect->fd_in = open(redirect->in_file, O_RDONLY);
	}
	else if (ft_strcmp(token, "<<") == 0)
		redirect->heredoc_eof = ft_strdup(next_token);
	if ((redirect->fd_in < 0 || redirect->fd_out < 0) & !redirect->heredoc_eof)
	{
		cmd->exit_value = -1;
		error_msg("minishell: ", NULL, ": No such file or directory", EXIT_FAILURE);
		redirect->error = true;
	}
}
