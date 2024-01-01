/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:56:57 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/01 17:58:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    init_env(t_data *data)
{
    if (data = NULL)
        return ;
    data->env = NULL;
    data->user_input = NULL;
    data->work_dir = NULL;
    data->old_work_dir = NULL;
}
