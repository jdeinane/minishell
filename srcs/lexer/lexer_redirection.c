/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:29:34 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 10:32:33 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lexer_redirections(char **tokens, int *token_index, char *current_token, \
		int *token_len, char c, char next_char)
{
	if (*token_len > 0)
	{
		current_token[*token_len] = '\0';
		tokens[(*token_index)++] = ft_strdup(current_token);
		*token_len = 0;
	}
	if (c == '>' && next_char == '>')
	{
		tokens[(*token_index)++] = ft_strdup(">>");
		return (1);
	}
	else 
	{
		char redirection_token[2] = {c, '\0'};
		tokens[(*token_index)++] = ft_strdup(redirection_token);
	}
    return (0);
}
