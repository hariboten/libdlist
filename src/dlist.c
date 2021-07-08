/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:10:09 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/08 18:25:52 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>


t_dlist			*dlist_new(void *content)
{
	t_dlist	*lst;

	lst = malloc(sizeof(t_dlist));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_dlist			*dlist_front(t_dlist *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist			*dlist_back(t_dlist *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

size_t			dlist_size(t_dlist *lst)
{
	size_t	size;

	size = 1;
	lst = dlist_front(lst);
	while (lst->next)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
