/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:02:02 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/01 18:17:47 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_pipes(t_pipe *pipe, int num_pipes)
{
    int i;

    i = 0;
    if (pipe == NULL)
        return (NULL);
    pipe->fd = malloc(sizeof(int) * 2 * num_pipes);
    if (pipe->fd == NULL)
    {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }
    while (i < num_pipes)
    {
        if (pipe(pipe->fd + 1 * 2) == -1)
        {
            perror("Pipe failed");
            exit(EXIT_FAILURE);
        }
        i++;
    }
}