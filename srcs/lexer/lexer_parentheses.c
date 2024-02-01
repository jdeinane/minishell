/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_parentheses.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:48:17 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 10:50:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lexer_parentheses(char **tokens, int *token_index, \
			char *current_token, int *token_len, char c)
{
	if (*token_len > 0)
	{
		current_token[*token_len] = '\0';
		tokens[(*token_index)++] = ft_strdup(current_token);
		*token_len = 0;
	}
	char parenthesis_token[2] = {c, '\0'};
	tokens[(*token_index)++] = ft_strdup(parenthesis_token);
}
