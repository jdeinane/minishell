/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 16:45:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**process_input(char *input, t_commands *cmds)
{
    char (buffer[MAX_TOKEN_LEN]) = {0};
    int (buf_index) = 0;
    bool (in_quotes) = false;
	bool (unclosed_quotes) = false;
    int (i) = 0;
	int (token_counts) = 0;
    char (c);
	char (*token);

	while (input[i] != '\0')
	{
		c = input[i];
		if ((c == '"' || c == '\'') && !in_quotes)
		{
			in_quotes = true;
			buffer[buf_index++] = c;
		}
		else if ((c == '"' || c == '\'') && in_quotes)
		{
			in_quotes = false;
			buffer[buf_index++] = c;
		}
		else if (!in_quotes && (is_space(c) || is_special_char(c)))
		{
			if (buf_index > 0)
			{
				buffer[buf_index] = '\0';
				token = ft_strdup(buffer);
				if (token == NULL)
				{
					cmds->exit_value = ("minishell: ", strerror(errno), NULL, STDERR);
					return ;
				}
				cmds->cmds[token_counts++] = token;
				buf_index = 0;
			}
			if (is_special_char(c) && !is_space(c))
				handle_special_char(cmds, &i, input);
			else
				buffer[buf_index++] = c;
		}
		i++;
	}
	if (in_quotes)
	{
		unclosed_quotes = true;
		cmds->exit_value = ("minishell: ", "Unclosed quotes", NULL, STDERR);
		return ;
	}
	if (buf_index > 0 && !unclosed_quotes)
	{
		buffer[buf_index] = '\0';
		token = ft_strdup(buffer);
		if (token == NULL)
		{
			cmds->exit_value = ("minishell: ", strerror(errno), NULL, STDERR);
			return ;
		}
		cmds->cmds[token_counts++] = token;
	}
	cmds->num_cmds = token_counts;
}
