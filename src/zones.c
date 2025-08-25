/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:31:19 by npremont          #+#    #+#             */
/*   Updated: 2025/08/25 11:22:14 by npremont         ###   ########.fr       */
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

	size_t bloc_size = unit_size + sizeof(t_header) + sizeof(t_header) % 16;

	for (size_t i = 0; i < zone_size; i += bloc_size)
	{
		t_header* header = (t_header *)zone + i;
		header->is_free = true;
		header->size = unit_size;
		if (i + bloc_size > zone_size)
			header->next = zone + bloc_size;
	}
	
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
