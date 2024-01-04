/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 18:02:02 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:10:49 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    init_pipes(t_pipe *pipe, int num_pipes)
{
    int i;

    i = 0;
    if (pipe == NULL)
        return ;
    pipe->fd = malloc(sizeof(int) * 2 * num_pipes);
    if (!pipe->fd)
		return ;
	while (i < 2 * num_pipes)
	{
		pipe->fd[i] = -1;
		i++;
	}
}
