/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:59:31 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/29 14:18:11 by jubaldo          ###   ########.fr       */
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
# include <limits.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>

# define MAX_PATH 4096
# define MAX_ARGS 512
# define VAR_MAX_SIZE 1024

# define OLD_PWD "OLDPWD"
# define PWD "PWD"

# define STDOUT STDOUT_FILENO
# define STDIN  STDIN_FILENO
# define STDERR STDERR_FILENO

# define CMD_NOT_EXEC   126
# define CMD_NOT_FOUND  127

# define OR		1
# define AND	2
# define PIPE	3

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
	char			**tokens;
	char			**paths;
	t_pipe			*pipe;
	t_redirect		*io;
	t_cmd			*cmd;
}	t_commands;

typedef struct s_num_parenth
{
	int	first_p;
	int	last_p;
}	t_num_parenth;

extern int	g_status_code;

// MAIN
void		minishell(int ac, char **av, char **envp);
int			main(int ac, char **av, char **envp);

// BUILTINS
int			builtin_cd(t_data *data, t_commands *cmds, int i);
int			builtin_echo(char **av);
int			builtin_env(t_data *data, t_commands *cmds, int num_cmd);
int			builtin_exit(t_data *data, t_commands *cmds, int num_cmds);
int			builtin_cmd(t_data *data, t_commands *cmds, int num_cmd);
int			builtin_pwd(void);
int			builtin_unset(t_data *data, t_commands *cmds, int num_cmd);

// EXEC

// ENV
bool		is_valid_var_name(char *name);
char		*get_env_var_value(char **envp, char *var);
bool		set_env_var(t_data *data, char *key, char *value);
int			env_var_count(char **envp);
int			get_env_var_index(char **env, char *var);
void		env_var_remove(t_data *data, int index);
char		**env_var_realloc(t_data *data, int len);

// INIT
bool		init_data(t_data *data, char **envp);
void		init_commands(t_data *data, t_commands *cmds);
void		init_redirections(t_commands *cmds);
void		init_pipes(t_commands *cmds);
void		init_parenth(int *i, t_num_parenth *num_p);
void		init_cmd(t_data *data, t_commands *cmds, int num_cmd);

// LEXER

// PARSER

// PIPES
void		create_pipes(t_commands *cmds, int index);
void		check_pipes(t_commands *cmds, int index);
void		close_pipes(t_commands *cmds);
void		close_pipes_fd(t_commands *cmds);

// REDIRECTIONS
int			handle_input(t_commands *cmds, char *part);
int			handle_output(t_commands *cmds, char *part, bool trunc);
void		handle_heredoc(t_commands *cmds, char *part);
bool		is_redirection_cmd(t_commands *cmds, int i);
void		handle_redirections(t_commands *cmds, int j);
void		redirect_io(t_redirect *io, int index_cmd);
void		restore_io(t_redirect *io);
bool		check_file(t_redirect *io, t_commands *cmds, bool free);

// LIBFT
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
int			ft_isalnum(int c);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strdup(const char *src);
size_t		ft_strlen(char const *s);
char		*ft_strndup(const char *s1, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
char		*ft_strpbrk(const char *str, const char *accept);
size_t		ft_strspn(const char *str, const char *accept);
char		*ft_strtok(char *str, const char *delim);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isdigit(int c);
long		ft_strtol(const char *str, char **endptr, int base);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strsjoin(char *str, char *add);
int			ft_atol(const char *str, bool *error);
void		*ft_realloc(void *ptr, size_t newsize);

// SIGNALS
void		signals_wait_cmd(void);
void		signals_run_cmd(void);

// UTILS
int			is_space(int c);
bool		is_command(char **tokens, int token_index);
char		**get_paths(char **envp);
bool		is_numeric(const char *str);
bool		is_digit2(char c, int base);
bool		check_args(int ac, char **av);
void		exit_minishell(t_data *data, int status_code);
bool		input_handler(t_data *data);
char		*get_prompt(void);
int			skip_whitespace(const char *str);
bool		clear_prev_input(t_redirect *io, bool in_file);
void		free_ptr(void *ptr);
void		free_str(char **str);
void		close_fds(t_commands *cmds, bool reset_io);
void		free_cmds(t_commands *cmds);
void		free_io(t_redirect *io);
bool		is_argument(char **tokens, int token_index, t_commands *cmds);
bool		is_redirection(char *token);
bool		is_pipe(const char *token);
int			error_msg(char *cmd, char *spec, char *msg, int status_code);

#endif