/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:09:21 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 15:30:59 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    write_input_to_tmp_file(int fd, const char *delimiter)
{
    char    buffer[1024];
    ssize_t nbytes;

    while (1)
    {
        printf("> ");
        nbytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        if (nbytes < 0)
        {
            perror("read");
            return ;
        }
        buffer[nbytes] = '\0';
        if (ft_strncmp(buffer, delimiter, ft_strlen(delimiter)) == 0
            && buffer[ft_strlen(delimiter)] == '\n')
            break ;
        write(fd, buffer, nbytes);
    }
}

int open_tmp_file(const char *tmp_file)
{
    int fd;

    fd = open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        perror("Error creating temporary file for here document");
    return (fd);
}

int here_document(const char *delimiter)
{
    char    *tmp_file;
    char    buffer[1024];
    int     fd;

    tmp_file = "/tmp/minishell_heredoc.tmp";
    fd = open_tmp_file(tmp_file);
    if (fd < 0)
        return (-1);
    write_input_to_tmp_file(fd, delimiter);
    close(fd);
    fd = open(tmp_file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening temporary file for here document");
        return (-1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (0);
}
