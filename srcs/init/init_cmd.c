/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:49:59 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:10:44 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    init_cmd(t_cmd *cmd)
{
    if (cmd == NULL)
        return;
    cmd->path = NULL;
    cmd->args = NULL;
    cmd->redirections = NULL;
}

void    init_cmds(t_commands *cmds)
{
    if (cmds == NULL)
        return;
    cmds->pid = NULL;
    cmds->num_cmds = 0;
    cmds->num_exec = 0;
    cmds->operators = NULL;
    cmds->exit_value = 0;
    cmds->cmds = NULL;
    cmds->paths = NULL;
    cmds->pipe = NULL;
    cmds->io = NULL;
    cmds->cmd = NULL;
}
