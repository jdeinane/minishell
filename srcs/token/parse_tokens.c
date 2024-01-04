/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:42 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 12:19:21 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_to_cmd(t_cmd *cmd, char *token)
{
	char	**new_args;
	int		arg_count;
	int		i;

	i = 0;
	arg_count = 0;
	new_args = malloc(sizeof(char *) * (arg_count + 2));
	if (!new_args)
		return ;
	while (cmd->args && cmd->args[arg_count])
		arg_count++;
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

bool	parse_tokens(t_tokenizer *tokenizer, t_commands *cmds)
{
	int		i;
	int		cmd_index;

	i = 0;
	cmd_index = 0;
	while (i < tokenizer->count)
	{
		if (is_cmd_separator(tokenizer->count))
		{
			cmd_index++;
			init_cmd(&cmds->cmds[cmd_index]);
		}
		else
			add_token_to_cmd(&cmds->cmds[cmd_index], tokenizer->tokens[i]);
		i++;
	}
	return (true);
}
