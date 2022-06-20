/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:05 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 14:47:08 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_pwdpath(char **envp)
{
	while (ft_strncmp("PWD", *envp, 3))
		envp++;
	return (*envp + 4);
}

char	*find_path(char **envp, char *var)
{
	while (ft_strncmp(var, *envp, (ft_strlen(var) - 1))
		envp++;
	return (*envp + ft_strlen(var));
}