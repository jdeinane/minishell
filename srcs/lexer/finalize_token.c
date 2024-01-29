/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:21:19 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/29 14:18:38 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	finalize_token(char **token, int token_len, t_commands *cmds, \
						int current_cmd_index)
{
	(*token)[token_len] = '\0';
	if (ft_strcmp(*token, "|") == 0)
	{
		cmds->operators[current_cmd_index] = PIPE;
		current_cmd_index += 1;
	}
	else
		add_token_to_cmd(token, *token, current_cmd_index);
	token_len = 0;
}
