/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewatanab <ewatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:49:11 by ewatanab          #+#    #+#             */
/*   Updated: 2021/07/08 18:05:30 by ewatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

struct			s_dlist;
typedef struct	s_dlist t_dlist;

struct			s_dlist
{
	void	*content;
	t_dlist	*next;
	t_dlist	*prev;
};

t_dlist			*dlist_new(void *content);
t_dlist			*dlist_front(t_dlist *lst);
t_dlist			*dlist_last(t_dlist *lst);
void			dlist_push_front(t_dlist **lst, t_dlist *newlst);
void			dlist_push_back(t_dlist **lst, t_dlist *newlst);
void			dlist_insert(t_dlist **lst, t_dlist *newlst);
void			dlist_pop_front(t_dlist *lst, void (*del)(void *));
void			dlist_pop_back(t_dlist *lst, void (*del)(void *));
void			dlist_erase(t_dlist *lst, void (*del)(void *));
void			dlist_clear(t_dlist **lst, void (*del)(void *));
void			dlist_swap(t_dlist **a, t_dlist **b);
int				dlist_size(t_dlist *lst);

#endif
