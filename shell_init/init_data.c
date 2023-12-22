/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:14:00 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/22 18:25:14 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_data(t_data *data)
{
	char	**environ;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env = environ;
	data->user_input = NULL;
	data->work_dir = getcwd(NULL, 0);
	data->old_work_dir = data->work_dir;
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
		rl_redisplay();
	else if (sig == SIGQUIT)
		exit(1);
}

void	init_signals(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

void	init_directory(t_data *data)
{
	char	*pwd;
	char	*oldpwd;

	pwd = getenv("PWD");
	oldpwd = getenv("OLDPWD");

	if (pwd)
		data->work_dir = ft_strdup(pwd);
	else
		data->work_dir = getcwd(NULL, 0);
	if (oldpwd)
		data->old_work_dir = ft_strdup(oldpwd);
	else
		data->old_work_dir = ft_strdup(data->work_dir);
}

void init_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i] != NULL)
	{
		add_history(data->env[i]);
		i++;
	}
}

void	init_history(void)
{
	rl_initialize();
	rl_readline_name = "minishell";
}
