/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:30:53 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 07:29:32 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

void			dlist_push_front(t_dlist **lst, t_dlist *newlst)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	dlist_front(*lst)->prev = dlist_back(newlst);
	dlist_back(newlst)->next = dlist_front(*lst);
	*lst = dlist_front(newlst);
	return ;
}

void			dlist_push_back(t_dlist **lst, t_dlist *newlst)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	dlist_front(newlst)->prev = dlist_back(*lst);
	dlist_back(*lst)->next = dlist_front(newlst);
	return ;
}

void			dlist_insert(t_dlist **lst, t_dlist *newlst)
{
	t_dlist	*newlst_front;
	t_dlist	*newlst_back;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = newlst;
		return ;
	}
	newlst_front = dlist_front(newlst);
	newlst_back = dlist_back(newlst);
	(*lst)->prev->next = newlst_front;
	newlst_front->prev = (*lst)->prev;
	(*lst)->prev = newlst_back;
	newlst_back->next = *lst;
	return ;
}

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
