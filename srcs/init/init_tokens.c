/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:59:37 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 16:51:43 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_tokens(t_tokenizer *tokens, char *input)
{
	tokens->count = 0;
	tokens->size = 10;
	tokens->tokens = malloc(sizeof(char *) * tokens->size);
	if (!tokens->tokens)
		return ;
	tokens->start = input;
	tokens->current_quote = '\0';
	tokens->in_quote = false;
}
