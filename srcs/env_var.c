/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:24:02 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 15:55:14 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*env_init(t_list **lst, char  **envp)
{
	t_list	*temp;
	int 	i;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		if (!(temp = malloc(sizeof(t_list))))
			return (NULL);
		if (!(temp->content = ft_strdup(envp[i])))
			return (NULL);
		temp->next = 0;
		ft_lstadd_back(lst, temp);
		i++;
	}
	return (*lst);
}