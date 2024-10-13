/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:18:14 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:18:21 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t srclen = ft_strlen(src);
    if (dstsize > 0)
    {
        size_t n = (srclen < dstsize - 1) ? srclen : dstsize - 1;
        ft_memcpy(dst, src, n);
        dst[n] = '\0';
    }
    return (srclen);
}
