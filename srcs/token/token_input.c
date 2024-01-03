/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:52:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 15:36:47 by jubaldo          ###   ########.fr       */
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

void	add_token(char **tokens, int *size, int *count, char *start, int len)
{
	if (*count >= *size - 1)
	{
		*size *= 2;
		*tokens = expand_tokens_array(*tokens, *size);
	}
	(*tokens)[*count] = ft_strndup(start, len);
	(*tokens)[++(*count)] = NULL;
}

char	**tokenize_input(char *input)
{
	int		i;
	int		size;
	int		count;
	char	**tokens;
	char	*start;
	char	current_quote;
	bool	in_quote;

	size = 10;
	count = 0;
	i = 0;
	tokens = malloc(sizeof(char *) * size);
	start = input;
	in_quote = false;
	current_quote = '\0';
	while (input[i] != 0)
	{
		if ((input[i] == '"' || input[i] == '\'') && !in_quote)
		{
			in_quote = true;
			current_quote = input[i];
			start = i + 1;
		}
		else if (input[i] == current_quote && in_quote)
		{
			in_quote = false;
			add_token(&tokens, &size, &count, start, i - start);
			start = i + 1;
		}
		else if((input[i] == ' ' || input[i] == '\n' || input[i] == '\t') 
				&& !in_quote)
		{
			if (i > start)
				add_token(&tokens, &size, &count, start, i - start);
			start = i + 1;
		}
		i++;
	}
	if (start != input + ft_strlen(input))
		add_token(&tokens, &size, &count, start, input + \
					ft_strlen(input - start));
	return (tokens);
}
