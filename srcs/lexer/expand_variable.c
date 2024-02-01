/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:32:32 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 10:55:31 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void expand_variable(char **tokens, int *token_index, char *current_token, int *token_len, char c, char *input, int *i)
{
    if (c == '$')
	{
        if (*token_len > 0)
		{
            current_token[*token_len] = '\0';
            tokens[(*token_index)++] = ft_strdup(current_token);
            *token_len = 0;
        }
        char var_name[MAX_TOKEN_LEN] = {0};
        int var_len = 0;
        (*i)++;
        while (ft_isalnum(input[*i]) || input[*i] == '_')
		{
            add_char_to_token(var_name, &var_len, input[*i]);
            (*i)++;
        }
        (*i)--;
        char *var_value = getenv(var_name);
        if (var_value) {
            tokens[(*token_index)++] = ft_strdup(var_value);
        }
    }
}
