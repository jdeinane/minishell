/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 00:22:11 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	process_input(char *input, t_commands *cmds)
{
    char (buffer[MAX_TOKEN_LEN]) = {0};
    int (buf_index) = 0;
    bool (in_quotes) = false;
    int (i) = 0;
	int (token_counts) = 0;
    char (c);

	while (input[i] != '\0')
	{
		c = input[i];
		if ((c == '"' || c == '\'') && !in_quotes)
			in_quotes = true;
		else if ((c == '"' || c == '\'') && in_quotes)
			in_quotes = false;
		if (!in_quotes && (is_space(c) || is_special_char(c)))
		{
			if (buf_index > 0)
			{
				buffer[buf_index] = '\0';
				cmds->cmds[token_counts++] = ft_strdup(buffer);
				buf_index = 0;
			}
			if (is_special_char(c) && !is_space(c))
				handle_special_char(cmds, &i, input);
			else
				buffer[buf_index++] = c;
		}
		i++;
	}
	if (buf_index > 0)
	{
		buffer[buf_index] = '\0';
		cmds->cmds[token_counts++] = ft_strdup(buffer);
	}
	cmds->num_cmds = token_counts;
}
