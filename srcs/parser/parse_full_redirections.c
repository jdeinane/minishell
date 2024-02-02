/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_full_redirections.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:26:19 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/02 14:27:40 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	handle_quotes(t_index *i_data, char *s, int add_malloc, \
					char special_char)
{
	if (add_malloc == 1)
	{
		i_data->i++;
		while (s[i_data->i] && s[i_data->i++] != special_char)
			i_data->malloc_size++;
	}
	else
	{
		i_data->i++;
		while (s[i_data->i] && s[i_data->i++] != special_char)
			;
	}
}

static void	get_size(t_index *i_data, char *s)
{
	i_data->malloc_size = 0;
	while (s[i_data->i] && s[i_data->i] != '<' && s[i_data->i] != '>')
	{
		if (s[i_data->i] == '\'' || s[i_data->i] == '\"')
			handle_quotes(i_data, s, 0, s[i_data->i]);
		else
			i_data->i++;
	}
	while (s[i_data->i] && (s[i_data->i] == '<' || s[i_data->i] == '>' || \
			s[i_data->i] == ' ' ))
	{
		i_data->i++;
		i_data->malloc_size++;
	}
	while (s[i_data->i] && s[i_data->i] != ' ')
	{
		if (s[i_data->i] == '\'' || s[i_data->i] == '\"')
			handle_quotes(i_data, s, 1, s[i_data->i]);
		else
		{
			i_data->malloc_size++;
			i_data->i++;
		}
	}
}

static size_t	ft_countstr(char *str)
{
	t_index	i_data;
	size_t	count;

	i_data.i = 0;
	count = 0;
	while (str[i_data.i])
	{
		get_size(&i_data, str);
		if (i_data.malloc_size != 0)
			count++;
	}
	return (count);
}

static void	ft_split2(char **str, char *s, size_t countc)
{
	t_index	i_data;

	i_data.i = 0;
	i_data.j = 0;
	while (i_data.j < countc)
	{
		get_size(&i_data, s);
		str[i_data.j] = (char *)malloc((i_data.malloc_size + 1) * sizeof(char));
		str[i_data.j][i_data.malloc_size] = '\0';
		if (str[i_data.j++] == NULL)
		{
			str = NULL;
			break ;
		}
	}
}

char	**handle_redirection(char *str)
{
	char	**str;
	size_t	i;

	if (!str)
		return (NULL);
	i = ft_countstr(str);
	str = (char **)malloc((i + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	ft_split2(str, str, i);
	if (str == NULL)
		return (NULL);
	parse_redirectionns(str, str, i);
	return (str);
}
