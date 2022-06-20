/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:51 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 16:45:23 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"

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


typedef struct s_token
{

}	t_token;

typedef struct s_env
{
	char		**env_list;
	//char		*paths;
	char		**cmdpath;
	char		**pwdpath;
	char		**cmd_pathways;
	//char		**cmd_args;
	//char		*cmd;
}	t_env;

typedef struct s_msh
{
	t_env		env;
	int			exit;
	int			in;
	int			out;
}	t_msh;

char	*find_path(char **envp, char *var);

void    minishell(char **env);

t_msh   *env_init(t_msh  *msh, char  **env);

t_msh   *free_env(t_msh *msh);

t_msh	*free_msh(t_msh *msh);

#endif