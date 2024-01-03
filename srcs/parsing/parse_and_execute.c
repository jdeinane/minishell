/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:47:32 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 15:37:23 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_and_execute(char *input, t_data *data, t_commands *cmds)
{
	char	**tokens;
	int		i;

	i = 0;
	tokens = tokenize_input(input);
	if (!tokens)
		return ;
	if (!parse_tokens(tokens, cmds))
	{
		free_tokens(tokens);
		return ;
	}
	while (i < cmds->num_cmds)
	{
		execute_command(&cmds->cmd[i], data);
		i++;
	}
	free_tokens(tokens);
}
