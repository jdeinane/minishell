/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_cmds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:59:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/29 14:43:38 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_token_to_cmds(t_commands *cmds, char *token, int *current_cmd_index)
{
	t_cmd (*current_cmd) = &cmds->cmd[*current_cmd_index];
	int	(arg_count) = 0;
	char (*new_args);

	if (ft_strcmp(token, "|") == 0)
	{
		cmds->operators[*current_cmd_index] = PIPE;
		*current_cmd_index += 1;
    } 
	else 
	{
        if (current_cmd->args == NULL) 
		{
            current_cmd->args = malloc(sizeof(char *) * 2);
            if (!current_cmd->args) return;
            current_cmd->args[0] = ft_strdup(token);
            current_cmd->args[1] = NULL;
        } 
		else 
		{
            while (current_cmd->args[arg_count] != NULL)
				arg_count++;
            new_args = ft_realloc(current_cmd->args, sizeof(char *) * (arg_count + 2));
            if (!new_args)
				return;
            current_cmd->args = new_args;
            current_cmd->args[arg_count] = ft_strdup(token);
            current_cmd->args[arg_count + 1] = NULL;
        }
    }
}
