/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:07:19 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 15:08:50 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int append_output(const char *filename)
{
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror("Error opening file for output redirection");
        return (-1);
    }
    if (dup2(fd, STDOUT_FILENO) < 0)
    {
        perror("Error redirecting output for appending");
        close(fd);
        return (-1);
    }
    close(fd);
    return (0);
}
