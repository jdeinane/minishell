/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:02:46 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/05 16:58:13 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redirect_input(const char *filemame)
{
	int	fd;

	fd = open(filemame, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file for input redirection");
		return (-1);
	}
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		perror("Error redirecting input");
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
