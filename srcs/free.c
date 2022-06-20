/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:40:17 by lmann             #+#    #+#             */
/*   Updated: 2022/06/20 16:47:26 by lmann            ###   ########.fr       */
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

t_msh   *free_msh(t_msh *msh)
{
	return(msh);
}