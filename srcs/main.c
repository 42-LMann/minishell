/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:46:30 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 16:51:06 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int    minishell(char **env)
{
	
    t_msh	msh;
	char	*line;


	if ((msh_init(&msh) || env_init(&msh, env) || fd_init(&msh)) == MALLOC_FAIL)
		return (MALLOC_FAIL);
	save_term_settings(&msh->terminos_p);
    while (mini.exit == 0)
    {
		printf("%S@%S:%S$ ",
			find_path(env, "USER"), find_path(env, "NAME"), find_path(env, "PWD"));
		lexer(&msh, &line);
		parser(&msh);

    }
	free_env(&msh);
	free_msh(&msh);
	return (0);
}

int	main(int argc, char *argv[argc], char **env)
{
	(void)argc;
	(void)argv;
	minishell(env);
	return(0);
}