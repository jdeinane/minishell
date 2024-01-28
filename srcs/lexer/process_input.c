/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:43:52 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/28 21:20:53 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	process_input(char *input, t_data *data)
{
	int (index) = 0;
	t_list (*tokens) = NULL;
	while (input[index])
	{
		if (is_space(input[index]))
			index++;
		else if (input[index] == '\'' || input[index] == '"')
			handle_quotes(&input, &index, &tokens);
		else if (ft_strchr("<>|;", input[index]) != NULL)
			handle_redir_and_pipes(&input, &index, &tokens);
		else if (input[index] == '$')
			handle_env_var(&input, &index, &tokens);
		else
			process_token(data, &input, &index, &tokens);
	}
}
