/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegoh <jegoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:19:58 by jegoh             #+#    #+#             */
/*   Updated: 2024/10/13 15:20:12 by jegoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    while (n-- && (*s1 || *s2))
    {
        if (*s1 != *s2)
            return (*(unsigned char *)s1 - *(unsigned char *)s2);
        s1++;
        s2++;
    }
    return (0);
}
