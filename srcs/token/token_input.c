/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 11:54:45 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**expand_tokens_array(char **tokens, int size)
{
	char	**new_tokens;
	int		i;

	new_tokens = malloc(sizeof(char *) * size);
	i = 0;
	while (i < size / 2)
	{
		new_tokens[i] = tokens[i];
		i++;
	}
	free(tokens);
	return (new_tokens);
}

void	add_token(char **tokens, int *count, char *start, int len)
{
	tokens[*count] = ft_strndup(start, len);
	(*count)++;
	tokens[*count] = NULL;
}

void	handle_quotes(char c, bool *in_quote, char *current_quote)
{
	if ((c == '"' || c == '\'') && !*in_quote)
	{
		*in_quote= true;
		*current_quote = c;
	}
	else if (c == *current_quote && *in_quote)
		*in_quote = false;
}

void	process_token(char **tokens, int *count, char **start, char *end)
{
	if (end > *start)
	{
		add_token(tokens, count, *start, end - *start);
		*start = end + 1;
	}
}

char	**tokenize_input(char *input)
{
	int		count;
	int		i;
	int		len;
	char	**tokens;
}