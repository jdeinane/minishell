/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 17:32:26 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	is_separator(char c)
{
    return (c == ' ' || c == '|' || c == '>' || c == '<' || c == '&');
}

char	**tokenize_input(const char *input)
{
	char	**tokens;
	char	token[MAX_TOKEN_LEN];
	int		token_len;
	int		size;
	bool	in_quote;
	int		i;

	size = 0;
	token_len = 0;
	i = 0;
	in_quote = false;
	token[0] = NULL;
	tokens = malloc(sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	while (input[i] != '\0')
	{
		if (is_serapator(input[i] != '\0') && !in_quote)
			add_token(&tokens, &size, token, &token_len);
		else
			handle_char(input[i], token, &token_len, &in_quote);
	}
	add_token(&tokens, &size, token, &token_len);
	tokens[size] = NULL;
	return (tokens);
}
