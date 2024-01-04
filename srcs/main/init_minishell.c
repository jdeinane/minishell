/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:28:38 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:11:34 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_minishell(int ac, char **av, char **envp)
{
	t_data		*data;
	t_commands	*cmds;
	char		*input;

	data = init_data();
	cmds = init_commands();
	init_env(data, envp);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			break ;
		add_history(input);
		parse_and_execute(input, data, cmds);
		free(input);
	}
	free_data(data);
	free_commands(cmds);
}
