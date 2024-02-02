/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:18:56 by brjoves           #+#    #+#             */
/*   Updated: 2024/02/02 15:18:58 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	last_exit_status(char *av, bool *error)
{
	unsigned long long	i;

	i = 0;
	if (!av)
		return (g_status_code);
	while (is_space(av[i]))
		i++;
	if (av[i] == '-' || av[i] == '+')
		i++;
	if (!ft_isdigit(av[i]))
		*error = true;
	while (av[i])
	{
		if (!ft_isdigit(av[i]) && !is_space(av[i]))
			*error = true;
		i++;
	}
	i = ft_atol(av, error);
	return (i % 256);
}

int	builtin_exit(t_data *data, t_commands *cmds, int num_cmds)
{
	int		exit_status;
	bool	error;

	error = false;
	if (!cmds || !cmds->cmd[num_cmds].args[1])
		exit_status = g_status_code;
	else
	{
		exit_status = last_exit_status(cmds->cmd[num_cmds].args[1], &error);
		if (error)
			exit_status = error_msg("exit", cmds->cmd[num_cmds].args[1],
					"numeric arguments required", STDERR_FILENO);
		else if (cmds->cmd[num_cmds].args[2])
			return (error_msg("exit", NULL, "too many arguments", \
					EXIT_FAILURE));
	}
	close_fds(cmds, false);
	free_cmds(cmds);
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit_minishell(data, exit_status);
	return (STDERR_FILENO);
}
