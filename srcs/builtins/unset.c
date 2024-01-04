/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:56:11 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/04 14:10:10 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int builtin_unset(char **av, char **env)
{
    if (av[1] == NULL)
    {
        printf("unset: not enough arguments\n");
        return (1);
    }
    remove_env_var(env, av[1]);
    return (0);
}
