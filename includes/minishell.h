/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:51 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 14:45:54 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* Custom function library */
# include "libft.h"

/* INT_MAX and INT_MIN */
# include <limits.h>

/* TRUE/FALSE bool statements */
# include <stdbool.h>

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* to perror */
# include <stdio.h>


typedef struct s_env
{
	char		*paths;
	char		**cmd_paths;
	char		**cmd_args;
	char		*cmd;
}	t_env;

typedef struct s_msh
{
	t_env			*env;		
}	t_msh;

char	*find_path(char **envp, char *var)

void    minishell(char **env);

t_msh	env_init(t_msh *msh);

#endif