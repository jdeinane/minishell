/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 23:58:49 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:10:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin_exit(void)
{
	exit(0);
	return (0);
}
