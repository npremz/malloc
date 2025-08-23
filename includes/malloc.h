/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npremont <npremont@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:35:52 by npremont          #+#    #+#             */
/*   Updated: 2025/08/23 14:08:38 by npremont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define SMALL_UNIT     128
# define MEDIUM_UNIT    1024

# define DEBUG 1

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/mman.h>

typedef enum
{
    ZONE_SMALL,
    ZONE_MEDIUM, 
    ZONE_LARGE
}   t_zone_type;

typedef struct s_header
{
    size_t              size;
    bool                is_free;

    struct s_header*    next;
}   t_header;

typedef struct s_zone
{
    void*               start;
    void*               end;
    size_t              block_size;
    struct s_zone*      allocated_list;
    struct s_zone*      free_list;
}   t_zone;

typedef struct s_large_zone
{
    size_t                  size;
    size_t                  r_size;
    struct s_large_zone*    next;
}   t_large_zone;

typedef struct s_malloc_data
{
    t_zone*         s_zone;
    t_zone*         m_zone;
    t_large_zone*   l_zone;

    size_t          total_allocated;
}   t_malloc_data;

#endif
