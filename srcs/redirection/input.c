/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brjoves <brjoves@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:05 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/26 17:53:58 by brjoves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	open_infile(t_commands *cmds, char *file)
{
	cmds->io->in_file = file;
	if (cmds->io->in_file && cmds->io->in_file[0] != '\0')
		return (error_msg_cmd(file, NULL, "ambiguous redirect", false));
	cmds->io->fd_in = open(cmds->io->in_file, O_RDONLY);
	if (cmds->io->fd_in == -1)
		return (error_msg_cmd(cmds->io->in_file, NULL, strerror(errno), false));
	return (-1);
}

static void	remove_quotes(char *str)
{
	char	*read_ptr;
	char	*write_ptr;

	read_ptr = str;
	write_ptr = str;
	if (str == NULL)
		return ;
	while (*read_ptr != '\0')
	{
		if (*read_ptr == '\'' || *read_ptr == '\"')
		{
			*write_ptr = *read_ptr;
			write_ptr++;
		}
		read_ptr++;
	}
	*write_ptr = '\0';
}

int	handle_input(t_commands *cmds, char *part)
{
	char	**part_split;
	char	*result;
	int		status_code;

	remove_quotes(part);
	part_split = ft_split(part, '<');
	result = ft_strtrim(part_split[0], " ");
	init_redirections(cmds);
	status_code = open_infile(cmds, result);
	free_str(part_split);
	if (status_code != -1)
		cmds->io->error = true;
	else
		cmds->io->error = false;
	return (status_code);
}
