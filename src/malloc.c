/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:06:25 by npremont          #+#    #+#             */
/*   Updated: 2025/08/25 11:10:20 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static t_malloc_data*  g_data;

t_malloc_data*  get_data()
{
    if (!g_data)
    {
        g_data = mmap(NULL, sizeof(t_malloc_data),
                    PROT_READ | PROT_WRITE,
                    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

        if (g_data == MAP_FAILED)
		{
            perror("mmap failed");
            return NULL;
        }

        g_data->s_zone = NULL;
        g_data->m_zone = NULL;
        g_data->l_zone = NULL;
        g_data->total_allocated = 0;
    }

    if (DEBUG)
        printf("Total memory allocated: %lu\n", g_data->total_allocated);

    return (g_data);
}

void*   ft_malloc(size_t size)
{
    t_malloc_data* data = get_data();
    if (!data) return (NULL);

    if (DEBUG)
        printf("pageSize: %d\n", getpagesize());

    if (size <= SMALL_UNIT)
        return handleSmallUnit(size, data);
    else if (size > SMALL_UNIT && size <= MEDIUM_UNIT)
        return handleMediumUnit(size, data);
    else 
        return handleLargeUnit(size, data);

    return (NULL);
}
