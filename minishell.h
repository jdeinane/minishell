/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:59:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 16:46:38 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <signal.h>
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_PATH 4096

# define OLD_PWD "OLDPWD"
# define PWD "PWD"

# define STDOUT STDOUT_FILENO
# define STDIN  STDIN_FILENO
# define STDERR STDERR_FILENO

# define CMD_NOT_EXEC   126
# define CMD_NOT_FOUND  127

# define OR     1
# define AND    2
# define PIPE   3

typedef struct s_redirect
{
	bool	error;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
	int		cmd_index;
	char	*in_file;
	char	*out_file;
	char	*append_file;
	char	*heredoc_eof;
}	t_redirect;

typedef struct s_data
{
	char		**env;
	char		*user_input;
	char		*work_dir;
	char		*old_work_dir;
}	t_data;

typedef struct s_cmd
{
	char	*path;
	char	**args;
	char	**redirections;
}	t_cmd;

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
	t_redirect		*io;
	t_cmd			*cmd;
}	t_commands;

typedef struct s_index_data
{
	size_t	i;
	size_t	malloc_size;
	size_t	j;
}	t_index_data;

typedef struct s_tokenizer
{
	char	**tokens;
	char	*start;
	char	current_quote;
	bool	in_quote;
	int		count;
	int		size;
}	t_tokenizer;

extern int	g_status_code;

// BUILTINS
int		builtin_cd(char **av, t_data *data);
int		builtin_echo(char **av);
int		builtin_env(char **env);
int		builtin_exit(void);
int		builtin_export(char **av, char **env);
int		builtin_pwd(void);
int		builtin_unset(char **av, char **env);

// ENV
void	remove_env_var(char **env, const char **var);
void	update_env_var(t_data *data, const char *key, const char *value);
void	set_env_var(char ***env, char *var, char *value);
int		find_env_index(char **env, const char *var);
char	*create_env_var(const char *var, const char *value);

// EXEC
int		is_builtin(t_cmd *cmd);
int		exec_builtin(t_cmd *cmd, t_data *data);
int		exec_external_command(t_cmd *cmd, t_data *data);
void	exec_command(t_cmd *cmd, t_data *data);

// INIT
void	init_cmd(t_cmd *cmd);
t_data	*init_data();
void	init_cmds(t_commands *cmds);
void	init_env(t_data *data, char **envp);
void	init_pipes(t_pipe *pipe, int num_pipes);
void	init_redirect(t_redirect *redirect);
void	init_tokens(t_tokenizer *tokens, char *input);

// LEXER
void	free_tokens(t_tokenizer *tokenizer);
void	add_token_to_cmd(t_cmd *cmd, char *token);
void	add_token(t_tokenizer *tokenizer, int token_len);
void	update_quote_status(char c, t_tokenizer *tokenizer);
void	check_and_add_token(t_tokenizer *tokenizer, char c, int pos);
void	tokenize_input(t_tokenizer *tokenizer, char *input);
bool	parse_tokens(t_tokenizer *tokenizer, t_commands *cmds);
char	**expand_tokens_array(char **old_tokens, int new_size);

// MAIN
void	init_minishell(int ac, char **av, char **envp);
int		main(int ac, char **av, char **envp);

// PARSER
void	parse_and_execute(char *input, t_data *data, t_commands *cmds);

// PIPES
void	close_pipes(t_commands *cmds);
void	execute_cmd(t_commands *cmds, int index);
void	setup_pipe_redir(t_commands *cmds);
int		create_pipes(t_commands *cmds);
int		init_pipes_and_forks(t_commands *cmds);
int		exec_cmd_pipes_and_redirect(t_commands *cmds);

// REDIRECTION
int		append_output(const char *filename);
int		open_tmp_file(const char *tmp_file);
int		here_document(const char *delimiter);
int		redirect_input(const char *filemame);
int		redirect_output(const char *filename);
int		handle_redirections(t_commands *cmds);
void	write_input_to_tmp_file(int fd, const char *delimiter);

// UTILS
bool	is_cmd_separator(char *token);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(char *src);
size_t	ft_strlen(char const *s);
char	*ft_strndup(const char *s1, size_t n);
void	free_data(t_data *data);
void	free_commands(t_commands *cmds);

#endif