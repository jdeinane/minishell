/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:43:52 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/29 14:04:57 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	process_input(char *input, t_commands *cmds)
{
	int (token_len) = 0;
	int (current_cmd_index) = 0;
	int (i) = 0;
	char (*token) = malloc(MAX_ARGS * sizeof(char));
	if (!token)
		return ;
	while (input[i] != '\0')
	{
		if (is_space(input[i]))
			finalize_token(&token, &token_len, cmds, &current_cmd_index);
		else
			handle_character(input[i], &token, &token_len);
		i++;
	}
	finalize_token(&token, &token_len, cmds, &current_cmd_index);
	free(token);
}
