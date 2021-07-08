/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:10:09 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 07:45:09 by ewatanab         ###   ########.fr       */
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

void			dlist_destroy(t_dlist **lst, void (*del)(void *));
