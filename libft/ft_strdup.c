/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:22:39 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:22:43 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
    size_t len = ft_strlen(s1) + 1;
    char *dup = malloc(len);
    if (!dup)
        return (NULL);
    return ((char *)ft_memcpy(dup, s1, len));
}
