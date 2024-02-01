/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:29 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 11:07:34 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_char_to_token(char *token, int *len, char c)
{
	token[*len] = c;
	(*len)++;
	token[*len] = '\0';
}

char	**tokenize_input(const char *input)
{
	char	**tokens;
	char	*current_token[MAX_TOKEN_LEN];
	char	special_token[2];
	char	c;
	int		i;
	int		skip;
	int		token_len;
	int		token_index;
	bool	in_quote;

	token_index = 0;
	token_len = 0;
	in_quote = false;
	i = 0;
	skip = 0;
	current_token[MAX_TOKEN_LEN] = NULL;
	tokens = init_token_array();
	while (input[i] != '\0')
	{
		c = input[i];
		if (c == '"' || c == '\'')
		{
			if (!in_quote)
				in_quote = true;
			else
				in_quote = false;
		}
		else if (!in_quote && (is_space(c) || is_special_char(c)))
		{
			if (token_len > 0)
			{
				current_token[token_len] = '\0';
				tokens[token_index++] = ft_strdup(current_token);
				ft_memset(current_token, 0, MAX_TOKEN_LEN);
				token_len = 0;
			}
			if (is_special_char(c) && c != ' ')
			{
				special_token[2] = {c, '\0'};
				tokens[token_index++] = ft_strdup(special_token);
			}
			if (!in_quote && (c == '>' || c == '<'))
				skip = lexer_redirections(tokens, &token_index, current_token, &token_len, c, input[i + 1]);
			i += skip;
			if (!in_quote && c == '|')
				lexer_operator(tokens, &token_index, current_token, &token_len, c);
			if (!in_quote && (c == '(' || c == ')'))
				lexer_parentheses(tokens, &token_index, current_token, &token_len, c);
			if (!in_quote && c == '$')
				expand_variable(tokens, &token_index, current_token, &token_len, c, input, &i);
			if (!error_lexor(tokens, &token_index, current_token, token_len))
				return (NULL);
		}
		else
			add_char_to_token(current_token, &token_len, c);
		i++;
	}
	if (token_len > 0)
	{
		current_token[token_len] = '\0';
		tokens[token_index] = ft_strdup(current_token);
		token_index++;
	}
	tokens[token_index] = NULL;
	return (tokens);
}
