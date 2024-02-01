/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:33:49 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 10:42:06 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lexer_operator(char **tokens, int *token_index, char *current_token, \
		int *token_len, char c)
{
	if (*token_len > 0)
	{
		current_token[*token_len] = '\0';
		tokens[(*token_index)++] = ft_strdup(current_token);
		*token_len = 0;
	}
	if (c == '|')
		tokens[(*token_index)++] = ft_strdup("|");
}
