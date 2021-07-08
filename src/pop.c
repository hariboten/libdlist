/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 07:43:21 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 07:46:17 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

void			dlist_pop_front(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*front;

	if (!lst || !*lst)
		return ;
	front = dlist_front(*lst);
	if (del)
		del(front->content);
	if (!front->next)
		*lst = NULL;
	else
	{
		front->next->prev = NULL;
		*lst = front->next;
	}
	free(lst);
	return ;
}

void			dlist_pop_back(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*back;

	if (!lst || !*lst)
		return ;
	back = dlist_back(*lst);
	if (del)
		del(back->content);
	if (!back->prev)
		*lst = NULL;
	else
		back->prev->next = NULL;
	free(lst);
	return ;
}
