/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:58:41 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 15:44:16 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_redirect(t_redirect *redirect)
{
	if (!redirect)
		return (NULL);
  redirect->error = false;
  redirect->fd_in = STDIN;
  redirect->fd_out = STDOUT;
  redirect->stdin_backup = -1;
  redirect->stdout_backup = -1;
  redirect->cmd_index = 0;
  redirect->in_file = NULL;
  redirect->out_file = NULL;
  redirect->heredoc_eof = NULL;
}
