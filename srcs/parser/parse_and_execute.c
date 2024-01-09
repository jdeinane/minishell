/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:47:32 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 17:02:41 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_and_execute(char *input, t_data *data, t_commands *cmds)
{
	t_tokenizer	tokenizer;
	char		**tokens;
	int			i;

	i = 0;
	tokenize_input(&tokenizer, input);
	if (!tokens)
		return ;
	if (!parse_tokens(&tokenizer, cmds))
	{
		free_tokens(&tokenizer);
		return ;
	}
	while (i < cmds->num_cmds)
	{
		exec_command(&cmds->cmd[i], data);
		i++;
	}
	free_tokens(&tokenizer);
}
