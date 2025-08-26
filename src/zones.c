/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:31:19 by npremont          #+#    #+#             */
/*   Updated: 2025/08/26 12:55:37 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static void*	createZone(size_t zone_size, size_t unit_size)
{
	void*	zone  = mmap(NULL, zone_size,
						PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	if (zone == MAP_FAILED)
	{
        perror("small zone mmap failed");
        return NULL;
    }

	size_t header_zone_and_padding = sizeof(t_zone);
	if (header_zone_and_padding % 16 != 0)
		header_zone_and_padding += 16 - (header_zone_and_padding % 16);

	t_zone* ret_zone = (t_zone *)((char *)zone);

	size_t header_and_padding = sizeof(t_header);
	if (header_and_padding % 16 != 0)
		header_and_padding += 16 - (header_and_padding % 16);
		
	size_t bloc_size = header_and_padding + unit_size;

	if (DEBUG)
		printf("Creating small zone of size %lu. \n", zone_size);

	for (size_t i = header_zone_and_padding, j = 0;
		(i + bloc_size) < zone_size; i += bloc_size, j++)
	{
		if (DEBUG)
			printf("Creating bloc %lu of size %lu at position %lu => ", j, bloc_size, i);

		t_header* header = (t_header *)((char *)zone + i);
		header->is_free = true;
		header->size = unit_size;
		if (i + bloc_size < zone_size)
			header->next = zone + i + bloc_size;

		if (DEBUG)
			printf("Bloc %lu created at %p\n", j, zone + i);
	}

	ret_zone->start = zone;
	ret_zone->end = zone + zone_size;
	ret_zone->allocated_list = NULL;
	ret_zone->block_size = bloc_size;
	ret_zone->free_list = zone + header_zone_and_padding;
	
	return (zone);
}

void*   handleSmallUnit(size_t size, t_malloc_data* data)
{
	if (!data->s_zone)
		data->s_zone = createZone(SMALL_ZONE_SIZE, SMALL_UNIT);

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
