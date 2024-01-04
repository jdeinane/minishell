/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:53:06 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:11:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_tokens(t_tokenizer *tokenizer)
{
	int	i;

	i = 0;
	if (tokenizer->tokens == NULL)
		return ;
	while (tokenizer->tokens[i] != NULL)
	{
		free(tokenizer->tokens[i]);
		i++;
	}
	free(tokenizer->tokens);
	tokenizer->tokens = NULL;
	tokenizer->count = 0;
	tokenizer->size = 0;
}
