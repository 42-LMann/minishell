/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:45:51 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 16:51:53 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "datatypes.h"
# include "defines.h"
# include "term_colours.h"
# include "env.h"

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

typedef int	t_prompt;
t_prompt	g_print;

typedef struct s_cmd
{
	char	**arg;
	char	**input_arg;	
}	t_cmd;

typedef struct s_token
{
	//t_token_list	*lexer;
	//t_tree			*tree;
}	t_token;

typedef struct s_fds
{
	int		fdin;
	int		fdout;
	int		pipein;
	int		pipeout;
	int		pid;
}	t_fds;


char	*find_path(t_list *env_lst, char *var);
char	*find_pwdpath(char **envp);

int    minishell(char **env);

t_list	*env_init(t_list **lst, char  **envp);

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelete(t_list *lst, void (*del)(void*));

#endif