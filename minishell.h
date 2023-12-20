/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:59:31 by jubaldo           #+#    #+#             */
/*   Updated: 2023/12/20 23:55:08 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define PWD	"PWD"
# define OLDPWD	"OLDPWD"

# define OR		1
# define AND	2
# define PIPE	3

# define CMD_NOT_EXEC	126
# define CMD_NOT_FOUND	127

# define STDIN		STDIN_FILENO
# define STDOUT		STDOUT_FILENO
# define STDERR		STDERR_FILENO

typedef struct s_data
{
	char		**env;
	char		*user_input;
	char		*work_dir;
	char		*old_work_dir;
}	t_data;

typedef struct s_redirect
{
	int		fd_in;
	int		fd_out;
	int		cmd_index;
	int		stdin_backup;
	int		stdout_backup;
	char	*in_file;
	char	*out_file;
	char	*heredoc_eof;
	bool	error;
}	t_redirect;

typedef struct s_cmd
{
	char	*path;
	char	**args;
	char	**redirections;
}	t_cmd;

typedef struct s_index
{
	size_t	i;
	size_t	j;
	size_t	malloc_size;
}	t_index;

typedef struct s_pipe
{
	int	*fd;
}	t_pipe;

typedef struct s_commands
{
	pid_t			*pid;
	int				num_cmds;
	int				num_exec;
	int				*operators;
	int				exit_value;
	char			**cmds;
	char			**paths;
	t_pipe			*pipe;
	t_cmd			*cmd;
	t_redirect		*redirect;
}	t_commands;

extern int	g_status_code;

#endif 