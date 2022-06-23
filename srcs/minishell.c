/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:18:02 by lmann             #+#    #+#             */
/*   Updated: 2022/06/23 18:21:20 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    minishell(char **env)
{
    t_msh	msh;
	char	*line;

    msh_init(&msh);
	fd_init(&msh);
    env_init(&msh, env);
    while (msh.exit == 0)
    {
		prompt(&line);
		lexer(&msh, &line);
		parser(&msh);
		//msh.exit = 0;
    }
	free_env(&msh);
	free_msh(&msh);
}