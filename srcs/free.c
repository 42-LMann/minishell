/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:40:17 by lmann             #+#    #+#             */
/*   Updated: 2022/06/23 15:35:35 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_msh   *free_env(t_msh *msh)
{
	int i;

	i = 0;
	while (msh->env.env_list[i])
	{
		free(msh->env.env_list[i]);
		i++;
	}
	return(msh);
}

void   *free_msh(t_msh *msh)
{
	return(msh);
}