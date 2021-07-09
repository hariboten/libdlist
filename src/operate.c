/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:00:14 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 14:28:05 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

void			dlist_swap(t_dlist *a, t_dlist *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
	return ;
}

void			dlist_qsort(t_dlist *front, t_dlist *back, bool cmp(void *, void *))
{
	t_dlist	*it;
	t_dlist	*rit;
	void	*pivot;

	if (front == back)
		return ;
	it = front;
	rit = back;
	pivot = front->content;
	while (it != rit)
	{
		while (it != rit && (cmp(it->content, pivot)))
			it = it->next;
		while (it != rit && !(cmp(rit->content, pivot)))
			rit = rit->prev;
		if (it == rit)
			break ;
		dlist_swap(it, rit);
		rit = rit->prev;
	}
	dlist_qsort(front, it, cmp);
	dlist_qsort(rit->next, back, cmp);
	return ;
}
