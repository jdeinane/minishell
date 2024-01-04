/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:31:12 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:09:51 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_echo(char **av)
{
	int		i;
	int		nl;

	i = 1;
	nl = 1;
	if (av[1] && ft_strcmp(av[1], "-n") == 0)
	{
		nl = 0;
		i++;
	}
	while (av[i] != NULL)
	{
		printf("%s", av[i]);
		if (av[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (nl)
		printf("\n");
	return (0);
}
