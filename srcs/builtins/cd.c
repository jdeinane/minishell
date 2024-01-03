/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:09:23 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 19:24:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(char **av, t_data *data)
{
	char	*path;
	char	old_path[4096];
	char	new_path[4096];

	if (getcwd(old_path), sizeof(old_path) == NULL)
		return (perror("cd"), 1);
	if (av[1] != NULL)
		path = av[1];
	else
	{
		path = getenv("HOME");
		if (path == NULL)
			return (printf("cd: HOME not set\n"), 1);
	}
	if (chdir(path) != 0)
		return (perror("cd"), 1);
	if (getcwd(new_path, sizeof(new_path)) == NULL)
		return (perror("getcwd"), 1);
	update_env_var(data->env, "OLDPWD", old_path);
	update_env_var(data->env, "PWD", new_path);
	return (0);
}
