/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubaldo <jubaldo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:52:25 by jubaldo           #+#    #+#             */
/*   Updated: 2024/01/03 17:11:09 by jubaldo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    builtin_pwd(void)
{
    char *cwd;
    char buff[4096];

    cwd = getcwd(buff, sizeof(buff));
    if (cwd == NULL)
    {
        perror("pwd");
        return (1);
    }
    printf("%s\n", cwd);
}
