/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:44:03 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/09 13:45:17 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_data	*init_data()
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
	{
		perror("Failed to allocate t_data");
		return NULL ;
	}
	data->env = NULL;
	data->user_input = NULL;
	data->work_dir = NULL;
	data->old_work_dir = NULL;
	return (data);
}
