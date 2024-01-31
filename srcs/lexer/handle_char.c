/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:33:49 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/31 17:34:52 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_char(char c, char *token, int *token_len, bool *in_quote) {
	if (c == '\"' || c == '\'')
		*in_quote = !*in_quote;
	else
	{
		token[*token_len] = c;
		(*token_len)++;
	}
}
