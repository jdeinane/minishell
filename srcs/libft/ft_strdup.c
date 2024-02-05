/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:22:45 by jubaldo           #+#    #+#             */
/*   Updated: 2024/02/05 17:52:00 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	if (!src)
		return (NULL);
	len = ft_strlen(src);
	while (src[len])
		len++;
	dup = malloc(sizeof(*dup) * (len + 1));
	if (dup != NULL)
	{
		while (src[i])
		{
			dup[i] = src[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}
