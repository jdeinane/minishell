/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:31:44 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 13:37:25 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	handle_redirections(t_commands *cmds)
{
	t_redirect	*redirect;
	int			i;

	i = 0;
	while (i < cmds->num_cmds)
	{
		redirect = &cmds->io[i];
		if (redirect->fd_in != STDIN_FILENO)
			if (redirect_input(redirect->in_file) < 0)
				return (-1);
		if (redirect->fd_out != STDOUT_FILENO)
			if (redirect_output(redirect->out_file) < 0)
				return (-1);
		if (redirect->append_file)
			if (append_output(redirect->append_file) < 0)
				return (-1);
		if (redirect->heredoc_eof)
			if (here_document(redirect->heredoc_eof) < 0)
				return (-1);
		i++;
	}
	return (0);
}
