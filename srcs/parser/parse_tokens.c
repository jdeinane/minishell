/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:15:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 13:27:33 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_tokens(char **tokens, int num_tokens, t_commands *cmd)
{
	int		i;
	char 	*token;

	i = 0;
	token = tokens[i];
	while (i < num_tokens)
	{
		if (is_command(token))
		{
			finalize_current_cmd(&cmd);
			init_new_cmd(&cmd, token);
		}
		else if (is_argument(token))
			add_arg_to_cmd(&cmd, token);
		else if (is_redirection(token))
			handle_redirection(&cmd, token, tokens[++i]);
		else if (is_pipe(token))
		{
			finalize_current_cmd(&cmd);
			prepare_for_next_cmd(&cmd);
		}
		else
			handle_syntax_error(token);
		i++;
	}
	finalize_current_cmd(&cmd);
}
