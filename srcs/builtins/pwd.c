/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:23:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/26 00:22:16 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_pwd(void)
{
	char	*cwd;
	char	buff[MAX_PATH];

	cwd = getcwd(buff, MAX_PATH);
	if (cwd)
	{
		ft_putendl_fd(buff, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	error_msg("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
