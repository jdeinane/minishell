/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:51:02 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/22 18:28:20 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		init_minishell(int ac, char **av, char **envp)
{
	t_data	data;
	if (check_args(ac, av) == false || init_struct(&data, envp) == false)
		exit_minishell(NULL, EXIT_FAILURE);
	init_prompt(&data);
	return (0);
}

static void	init_prompt(t_data *data)
