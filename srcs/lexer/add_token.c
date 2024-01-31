/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:32:32 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 00:17:52 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_token(char **tokens, int *size, char *token, int *token_len)
{
	if (*token_len == 0)
		return ;
	token[*token_len] = '\0';
	(*size)++;
	*tokens = realloc(*tokens, sizeof(char *) * (*size + 1));
	(*tokens)[*size - 1] =ft_strdup(token);
	*token_len = 0;
}
