/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:51:16 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 16:46:09 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"
# include "libft.h"

char    *g_cmdline;
t_list  *g_envs;

t_list  *env_init(t_list **lst, char **envp);
t_err	set_var(t_list *env_list, char *var, char *value);
char	*get_var(t_list *list, char *var);

#endif