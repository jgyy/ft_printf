/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:18:30 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:18:39 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t dstlen = ft_strlen(dst);
    size_t srclen = ft_strlen(src);
    if (dstsize <= dstlen)
        return (dstsize + srclen);
    ft_strlcpy(dst + dstlen, src, dstsize - dstlen);
    return (dstlen + srclen);
}
