/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:33:17 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/01 10:19:28 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	reset_parentheses(t_num_parenth *num_p, t_commands *cmds, int index)
{
	if (cmds->operators[index] != PIPE)
		num_p->first_p = num_p->first_p -1;
	else
		num_p->last_p++;
}

static int	check_parentheses(t_commands *cmds, int index)
{
	int				i;
	int				j;
	t_num_parenth	num_p;

	init_parenth(&i, &num_p);
	while (i < cmds->num_cmds)
	{
		j = 0;
		while (cmds->cmds[i][j++] == '(')
			num_p.first_p++;
		while (cmds->cmds[i][j])
		{
			if (cmds->cmds[i][j] == ')')
				reset_parentheses(&num_p, cmds, i);
			j++;
		}
		i++;
		if (num_p.first_p >= 1 && i > index && num_p.last_p >= 1)
			break ;
	}
	if (i < index)
		return (0);
	else
		return (i - 1);
}

void	check_pipes(t_commands *cmds, int index)
{
	int	i;

	i = 0;
	if (cmds->operators[index] != PIPE)
		i = check_parentheses(cmds, index);
	if (i == 0)
		i = index;
	if (cmds->operators[i] == PIPE)
		dup2(cmds->pipe[i + 1].fd[1], STDOUT);
}
