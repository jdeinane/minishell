/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:19:06 by brjoves           #+#    #+#             */
/*   Updated: 2024/02/02 15:19:08 by brjoves          ###   ########.fr       */
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
