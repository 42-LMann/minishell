/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:30 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 16:54:09 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(void)
{
	printf("%s@%s:%s$ ",
			find_path(g_envs, "USER="), find_path(g_envs, "LOGNAME="), find_path(g_envs, "PWD="));
}

int	minishell(char **env)
{
	g_print	= 0;
	char	*buffer;
	int		status = 0;
	t_cmd	cmd;

	g_envs = env_init(&g_envs, env);
    while (status == 0)
    {
		//lexer(&msh, &line);
		//parser(&msh);
		status = 1;
    }
	ft_lstclear(&g_envs, free);
	return (0);
}

int	main(int argc, char *argv[argc], char **env)
{
	(void)argc;
	(void)argv;
	minishell(env);
	return(0);
}

https://github.com/backslash-zero/minishell/blob/master/src/execs/reads.c