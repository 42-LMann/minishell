/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:47:05 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 16:37:03 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_err		set_var(t_list *env_list, char *var, char *value)
{
	t_list	*tmp;
	char	*old;
	char	*new;

	tmp = env_list;
	if (!value)
	{
		if (!(new = ft_strdup(var)))
			return (INPUT_ERR);
	}
	else if (!(new = ft_strjoin(var, value)))
		return (INPUT_ERR);
	while (tmp)
	{
		if (!(ft_strncmp(tmp->content, var, ft_strlen(var))))
		{
			old = tmp->content;
			tmp->content = new;
			free(old);
		}
		tmp = tmp->next;
	}
	return (NO_ERROR);
}

char	*find_path(t_list *env_lst, char *var)
{
	t_list	*tmp;

	tmp = env_lst;
	while (tmp != NULL)
	{
		if (!(ft_strncmp(tmp->content, var, (int)ft_strlen(var))))
			return (ft_strdup((char *)&(tmp->content[ft_strlen(var)])));
		tmp = tmp->next;
	}
	return (NULL);
}