/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:47:06 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/30 15:55:35 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	is_command(char *token)
{
	if (access(token, X_OK) == 0)
		return (true);
	return (false);
}

bool	is_redirection(char *token)
{
    return (ft_strcmp(token, ">") == 0 || ft_strcmp(token, ">>") == 0 ||
           ft_strcmp(token, "<") == 0 || ft_strcmp(token, "<<") == 0);
}

bool	is_argument(char *token)
{
	if (!is_command(token) && !is_redirection(token) && !is_pipe(token))
		return (true);
	return (false);
}

bool is_pipe(char *token) 
{
    return (ft_strcmp(token, "|") == 0);
}
