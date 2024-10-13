/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:21:38 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:21:42 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t needle_len = ft_strlen(needle);
    if (!needle_len)
        return ((char *)haystack);
    while (*haystack && len >= needle_len)
    {
        if (!ft_strncmp(haystack, needle, needle_len))
            return ((char *)haystack);
        haystack++;
        len--;
    }
    return (NULL);
}
