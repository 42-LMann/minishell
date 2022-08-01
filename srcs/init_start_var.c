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

t_err   *fd_init(t_msh  *msh)
{
	msh->fds.fdin = -1;
	msh->fds.fdout = -1;
	msh->fds.pipein = -1;
	msh->fds.pipeout = -1;
	msh->fds.pid = -1;
}

t_err	*msh_init(t_msh  *msh)
{

	msh->exec = 1;
	msh->exit = 0;
	msh->in = dup(STDIN);
	msh->out = dup(STDOUT);
}

t_err	mv_to_ms_envp(char *env_var, t_env *custom_envp)
{
	char	*key;
	char	*value;

	if (!env_var)
		return(printf(RED "[copy_to_custom_env] str to NULL..\n" RESET));
	if (get_env_key(env_var, &key) == MALLOC_FAIL)
		return(MALLOC_FAIL);
}

t_err	*env_init(t_msh  *msh, char  **envp)
{
	size_t i;

	ft_bzero(msh, sizeof(t_msh));
	i = 0;
	while (envp[i])
		i++;
	msh->env = ft_calloc(i + 3, sizeof(t_env))
	if (!msh->env)
		return (MALLOC_FAIL);
	//msh->env.env_list = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		//msh->env.env_list[i] = ft_strdup(envp[i]);
		mv_to_ms_envp(envp[i], &msh->env[i])
		i++;
	}
}