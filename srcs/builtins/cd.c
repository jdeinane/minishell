/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:09:23 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/02 21:50:13 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **av, t_data *data)
{
	char	oldPath[4096];
	char	newPath[4096];
	char	*path;

	if (getcwd(oldPath, sizeof(oldPath)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	path = av[1] ? av[1] : getenv("HOME");
	if (path == NULL)
	{
		printf("cd: HOME not set\n");
		return (1);
	}
	if (chrdir(path) != 0)
	{
		perror("cd");
		return (1);
	}
	update_env_var(data, "OLDPWD", oldPath);
	if (getcwd(newPathm, sizeof(newPath)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	update_env_var(data, "PWD", newPath);
	return (0);
}