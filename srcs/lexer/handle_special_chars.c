/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_special_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:01:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 10:37:01 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	handle_special_chars(t_commands *cmds, int *i, char *input)
{
	char	c;
	char	next_c;
	char	*redirection;
	char	var_name[VAR_MAX_SIZE];
	int		var_index;
	char	*var_value;

	c = input[*i];
	next_c = input[*i + 1];
	if (c == '|')
		cmds->cmds[cmds->num_cmds++] = ft_strdup("|");
	else if (c == '>' || c == '<')
	{
		redirection = (char *)malloc(3 * sizeof(char));
		if (!redirection)
		{
			cmds->exit_value = ("minishell: ", strerror(errno), NULL, STDERR);
			return ;
		}
		redirection[0] = c;
		redirection[1] = '\0';
		if (c == '>' && next_c == '>')
		{
			redirection[1] = '>';
			redirection[2] = '\0';
			(*i)++;
		}
		cmds->cmds[cmds->num_cmds++] = redirection;
	}
	else if (c == '$')
	{
		var_index = 0;
		(*i)++;
		while (ft_isalnum(input[*i]) || input[*i] == '_')
		{
			var_name[var_index++] = input[*i];
			(*i)++;
		}
		var_name[var_index] = '\0';
		var_value = get_env_var(var_name);
		if (var_value != NULL)
			cmds->cmds[cmds->num_cmds++] = ft_strdup(var_value);
		else
		{
			cmds->exit_value = ("minishell: ", var_name, ": Undefined variable.", STDERR);
		}
		(*i)--;
	}
}
