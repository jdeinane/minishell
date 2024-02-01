/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:00:27 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 11:05:19 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	lexer_errors(char **tokens, int *token_index, char *current_token, int token_len)
{
	char	*new_token;
	int		i;

	i = 0;
	if (token_len > 0)
	{
		current_token[token_len] = '\0';
		new_token = ft_strdup(current_token);
		if (!new_token)
		{
			error_msg("Malloc failed", NULL, strerror(errno), errno);
			while (i < *token_index)
			{
				free(tokens[i]);
				i++;
			}
			free(tokens);
			return (false);
		}
		tokens[*token_index] = new_token;
		(*token_index)++;
	}
	ft_memset(current_token, 0, MAX_TOKEN_LEN);
	return (true);
}
