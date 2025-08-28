/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:31:19 by npremont          #+#    #+#             */
/*   Updated: 2025/08/28 15:24:05 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void*	createZone(size_t unit_size)
{
	size_t header_zone_and_padding = paddedSize(sizeof(t_zone), 16);
	size_t header_and_padding = paddedSize(sizeof(t_header), 16);
	size_t bloc_size = header_and_padding + unit_size;
	size_t zone_size = paddedSize(bloc_size * 100, getpagesize());

	void*	zone  = mmap(NULL, zone_size,
		PROT_READ | PROT_WRITE,
		MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
			
	if (zone == MAP_FAILED) return(perror("small zone mmap failed"), NULL);

	t_zone* ret_zone = (t_zone *)((char *)zone);
	ret_zone->start = zone;
	ret_zone->end = zone + zone_size;
	ret_zone->allocated_list = NULL;
	ret_zone->block_size = bloc_size;
	ret_zone->next = NULL;
	ret_zone->free_list = zone + header_zone_and_padding;
	ret_zone->free_list->size = zone_size - header_zone_and_padding;
	ret_zone->free_list->next = NULL;

	if (DEBUG)
		printf("Created small zone of size %lu with header of size %lu.\n"
			"\tFree bloc of size %lu located at %p\n",
			zone_size, header_zone_and_padding,
			zone_size - header_zone_and_padding, ret_zone->free_list);
	
	return (ret_zone);
}

void*	getFirstFreeSlot(t_zone	*zone , size_t size)
{
	t_header*	free_bloc = NULL;
	t_zone*		zone_it = zone;

	printf("%p\n", zone_it);

	size_t header_and_padding = paddedSize(sizeof(t_header), 16);
	size_t bloc_size = header_and_padding + paddedSize(size, 16);

	if (DEBUG)
		printf("Looking for a free slot of size %lu...\n", bloc_size);

	while (zone_it)
	{
		t_header*	free_list_it = zone_it->free_list;
		while (free_list_it)
		{
			if (free_list_it->size >= size)
				free_bloc = free_list_it;
			free_list_it = free_list_it->next;
		}
		zone_it = zone_it->next;
	}
	
	if (DEBUG && free_bloc)
		printf("\t => Found a free bloc of size %lu at %p\n",
			free_bloc->size, free_bloc);

}

void*   handleSmallUnit(size_t size, t_malloc_data* data)
{
	if (DEBUG)
		printf("Small alloc called.\n");


	if (!data->s_zone)
		data->s_zone = createZone(SMALL_UNIT);
	
	void*	first_fit = getFirstFreeSlot(data->s_zone, size);

    return NULL;
}

void*   handleMediumUnit(size_t size, t_malloc_data* data)
{
    return NULL;
}

void*   handleLargeUnit(size_t size, t_malloc_data* data)
{
    return NULL;
}
