/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:00:23 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 14:12:20 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**expand_tokens_array(char **old_tokens, int new_size)
{
	char	**new_tokens;
	int		i;

	i = 0;
	new_tokens = malloc(new_size * sizeof(char *));
	if (new_tokens == NULL)
		return (perror("malloc"), NULL);
	while (i < new_size)
	{
		new_tokens[i] = NULL;
		i++;
	}
	while (old_tokens[i] != NULL && i < new_size)
	{
		new_tokens[i] = old_tokens[i];
		i++;
	}
	free(old_tokens);
	return (new_tokens);
}
