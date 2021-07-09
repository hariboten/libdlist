/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 10:00:14 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/09 10:08:12 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dlist.h>

void			dlist_swap(t_dlist *a, t_dlist *b)
{
	t_dlist	*tmp;

	tmp = a->next;
	a->next = b->next;
	a->next->prev = a;
	b->next = tmp;
	b->next->prev = b;
	tmp = a->prev;
	a->prev = b->prev;
	a->prev->next = a;
	b->prev = tmp;
	b->prev->next = b;
	return ;
}
