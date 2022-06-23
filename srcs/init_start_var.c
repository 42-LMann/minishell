/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_start_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:24:02 by lmann             #+#    #+#             */
/*   Updated: 2022/06/23 15:17:08 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void   *fd_init(t_msh  *msh)
{
	msh->fds.fdin = -1;
	msh->fds.fdout = -1;
	msh->fds.pipein = -1;
	msh->fds.pipeout = -1;
	msh->fds.pid = -1;
}

void	*msh_init(t_msh  *msh)
{
	msh->exit = 0;
	msh->in = dup(STDIN);
	msh->out = dup(STDOUT);
}

void	*env_init(t_msh  *msh, char  **env)
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
}