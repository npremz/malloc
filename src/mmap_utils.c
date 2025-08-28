/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:03:05 by npremont          #+#    #+#             */
/*   Updated: 2025/08/28 12:19:27 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

size_t paddedSize(size_t size, size_t round_to)
{
	if (size % round_to != 0)
		size += round_to - (size % round_to);

	return (size);
}
