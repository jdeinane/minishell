/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:42 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 15:39:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_to_cmd(t_cmd *cmd, char *token)
{
	static int	arg_count;
	char		**new_args;
	int			i;

	i = 0;
	arg_count = 0;
	while (cmd->args && cmd->args[arg_count])
	{
		new_args = malloc(sizeof(char *) * (arg_count + 2));
		arg_count++;
	}
	if (!new_args)
		return ;
	while (i < arg_count)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[arg_count] = ft_strdup(token);
	new_args[arg_count + 1] = NULL;
	free(cmd->args);
	cmd->args = new_args;
}

bool	parse_tokens(char **tokens, t_commands *cmds)
{
	int	i;
	int	cmd_index;

	i = 0;
	cmd_index = 0;
	init_cmd(&cmds->cmd[cmd_index]);
	while (tokens[i] != NULL)
	{
		if (is_cmd_separator(tokens[i]))
		{
			// gerer un separateur de cmd (comme un pipe)
			cmd_index++;
			init_cmd(&cmds->cmd[cmd_index]);
		}
		else
			add_token_to_cmd(&cmds->cmd[cmd_index], tokens[i]);
	i++;
	}
	return (true);
}
