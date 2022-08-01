/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmann <lmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:40:17 by lmann             #+#    #+#             */
/*   Updated: 2022/08/01 15:57:42 by lmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *ptr;

	if (!alst || !new)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_lstdelete(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *ptr;
	t_list *previous;

	if (!lst || !*lst || !del)
		return;
	ptr = *lst;
	while (ptr)
	{
		previous = ptr;
		ptr = ptr->next;
		ft_lstdelete(previous, del);
	}
	*lst = 0;
}