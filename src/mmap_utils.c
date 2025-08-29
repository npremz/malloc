/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:03:05 by npremont          #+#    #+#             */
/*   Updated: 2025/08/29 14:38:49 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t paddedSize(size_t size, size_t round_to)
{
	if (size % round_to != 0)
		size += round_to - (size % round_to);

	return (size);
}

void	header_add_front(t_header** lst, t_header* new)
{
	new->next = *lst;
	*lst = new;
}

t_zone	*zone_lstlast(t_zone *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	zone_lstadd_back(t_zone **lst, t_zone *new)
{
	if (*lst)
		zone_lstlast(*lst)->next = new;
	else
		*lst = new;
}
