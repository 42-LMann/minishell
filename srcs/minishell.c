/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:18:02 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 17:12:33 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_msh   *msh_init(t_msh  *msh)
{
	msh->exit = 1;
	msh->in = dup(STDIN);
	msh->out = dup(STDOUT);
	return(msh);
}

t_msh   *env_init(t_msh  *msh, char  **env)
{
    size_t i;

    i = 0;
    while (env[i])
        i++;
	msh->env.env_list = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		msh->env.env_list[i] = ft_strdup(env[i]);
		i++;
	}
    msh->env.pwdpath = NULL;
    msh->env.cmdpath = NULL;
    msh->env.cmd_pathways = NULL;
	return(msh);
}

void    minishell(char **env)
{
    t_msh	msh;
	char	*line;

    msh_init(&msh);
    env_init(&msh, env);
    while (msh.exit != 0)
    {

		lexer(&msh);
		printf("~$");
		//msh.exit = 0;
    }
	free_env(&msh);
	free_msh(&msh);
}