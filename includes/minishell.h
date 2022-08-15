/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:51 by lmann             #+#    #+#             */
/*   Updated: 2022/06/23 17:28:21 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "datatypes.h"
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
	t_token_list	*lexer;
	t_tree			*tree;
}	t_token;

typedef struct s_fds
{
	int		fdin;
	int		fdout;
	int		pipein;
	int		pipeout;
	int		pid;
}	t_fds;


typedef struct s_env
{
	char		*key;
	char		*value;
	char		**env_list;
}	t_env;


char	*find_path(char **envp, char *var);

void    minishell(char **env);

void	*env_init(t_msh *msh, char **env);
void	*msh_init(t_msh *msh);
void	*fd_init(t_msh *msh);

t_msh   *free_env(t_msh *msh);
void	*free_msh(t_msh *msh);

#endif