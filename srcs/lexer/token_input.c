/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:12:04 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_token(t_tokenizer *tokenizer, int token_len)
{
	if (tokenizer->count >= tokenizer->size - 1)
	{
		tokenizer->size *= 2;
		tokenizer->tokens = expand_tokens_array(tokenizer->tokens, \
		tokenizer->size);
	}
	tokenizer->tokens[tokenizer->count] = ft_strndup(tokenizer->start, \
	token_len);
	tokenizer->tokens[++tokenizer->count] = NULL;
}

void	update_quote_status(char c, t_tokenizer *tokenizer)
{
	if ((c == '"' || c == '\'') && !tokenizer->in_quote)
	{
		tokenizer->in_quote = true;
		tokenizer->current_quote = c;
	}
	else if (c == tokenizer->current_quote && tokenizer->in_quote)
		tokenizer->in_quote = false;
}

void	check_and_add_token(t_tokenizer *tokenizer, char c, int pos)
{
	if ((c == ' ' || c == '\n' || c == '\t') && !tokenizer->in_quote
		&& pos > (tokenizer->start - tokenizer->tokens[0]))
	{
		add_token(tokenizer, pos - (tokenizer->start - tokenizer->tokens[0]));
		tokenizer->start = tokenizer->tokens[0] + pos + 1;
	}
}

void	tokenize_input(t_tokenizer *tokenizer, char *input)
{
	int	i;

	i = 0;
	tokenizer->start = input;
	while (input[i] != '\0')
	{
		update_quote_status(input[i], tokenizer);
		check_and_add_token(tokenizer, input[i], i);
		i++;
	}
	if (tokenizer->start != input + i)
		add_token(tokenizer, input + i - tokenizer->start);
}
