/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 00:19:05 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static bool	is_separator(char c)
{
    return (c == ' ' || c == '|' || c == '>' || c == '<' || c == '&' \
	|| c == '(' || c == ')');
}

char	**tokenize_input(const char *input)
{
	char	**tokens;
	char	c;
	char	token[MAX_TOKEN_LEN];
	int		size;
	int		token_len;
	bool	in_quote;
	int		i;

	tokens = NULL;
	size = 0;
	token_len = 0;
	in_quote = false;
	i = 0;
	tokens = malloc(sizeof(char *));
	if (!tokens)
		return (NULL);
    tokens[0] = NULL;
    while (input[i] != '\0') 
	{
        c = input[i];
        if ((c == '\"' || c == '\'') && !in_quote)
		{
            in_quote = true;
            continue;
		}
        else if ((c == '\"' || c == '\'') && in_quote) 
		{
            in_quote = false;
            continue;
        }
        if (!in_quote && is_special_char(c))
		{
            add_token(&tokens, &size, token, &token_len);
            token[0] = c;
            token[1] = '\0';
            add_token(&tokens, &size, token, &token_len);
		}
        else if (!in_quote && is_separator(c))
            add_token(&tokens, &size, token, &token_len);
        else
            token[token_len++] = c;
		i++;
    }
    add_token(&tokens, &size, token, &token_len);
    tokens[size] = NULL;
    return (tokens);
}
