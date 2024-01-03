/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:08:01 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 20:52:34 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    remove_env_var(char **env, const char **var)
{
    int len;
    int i;
    int j;

    i = 0;
    len = ft_strlen(var);
    while (env[i] != NULL)
    {
        if (ft_strcmp(env[i], var, len) == 0 && env[i][len] == '=')
        {
            j = i;
            while (env[j] != NULL)
            {
                env[j] = env[j + 1];
                j++;
            }
            break;
        }
        i++;
    }
}
